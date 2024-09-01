#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

//function to get the assignment group name
std::string getName()
{
    std::string result;
    std::cout << "What assignment group will you be calculating: ";
    std::cin >> result;
    return result;
}

//function to request an integer from the user
int requestIntFromUser(std::string input)
{
    int result;
    std::cout << input;
    while (!(std::cin >> result))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. " << input;
    }
    return result;
}

//function to request a float from the user with input validation
float requestAFloat(std::string name, int iter, float min, float max)
{
    float input;
    std::cout << "Please Enter the grade for " << name << " " << iter << " followed by the enter key: ";
    while (!(std::cin >> input) || input < min || input > max)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a grade between " << min << " and " << max << ": ";
    }
    return input;
}

//function to calculate the average grade, dropping the lowest grade except for midterms
double calculateAverage(std::string name, int count, int totalGrade, float extraC)
{
    double accumulator = 0;
    float max = totalGrade * (1 + (extraC / 100));
    std::vector<float> grades;

    for (int i = 1; i <= count; ++i)
    {
        grades.push_back(requestAFloat(name, i, 0, max));
    }

    if (name != "Midterm" && name != "midterm")
    {
        auto minIt = std::min_element(grades.begin(), grades.end());
        grades.erase(minIt);
    }

    for (float grade : grades)
    {
        accumulator += grade;
    }

    return accumulator / grades.size();
}

//function to request assignment details from the user
double requestAssignmentDetails()
{
    std::string assignmentName = getName();
    int numberOfAssignments = requestIntFromUser("Please Enter the number of assignments associated with " + assignmentName + ": ");
    int totalAssignmentGrade = requestIntFromUser("Please Enter the total grade possible for all assignments: ");
    float percentageOfExtraCredit = requestAFloat("extra credit percentage", 1, 0, 100);

    return calculateAverage(assignmentName, numberOfAssignments, totalAssignmentGrade, percentageOfExtraCredit);
}

//wrapper function to calculate the total gradw
double calculateGrade()
{
    return requestAssignmentDetails();
}

//main function
int main()
{
    std::cout << "Hello, the purpose of this program is to calculate your grade percentage!\n";
    double gradeTotal = calculateGrade();
    std::cout << "Your total grade percentage in the class is " << gradeTotal << "%!\n";
    return 0;
}
