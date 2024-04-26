#include <iostream>
#include <string>
#include <limits>

// Function to request a float input from the user with error handling
float requestAFloat(const std::string &msg)
{
    float input;
    while (true)
    {
        std::cout << msg;
        if (std::cin >> input)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
            return input;
        }
        else
        {
            std::cout << "Invalid input. Please enter a valid number.\n";
            std::cin.clear();                                                   // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
        }
    }
}

// Function to calculate the average of scores
double calculateAverage(int count, float maxScore, const std::string &description)
{
    double sum = 0;
    float score;
    for (int i = 1; i <= count; i++)
    {
        std::string prompt = "Please enter the grade for " + description + " " + std::to_string(i) + " (out of " + std::to_string(static_cast<int>(maxScore)) + ") followed by the enter key: ";
        score = requestAFloat(prompt);
        sum += score;
    }
    return sum / count;
}

// Function to calculate the overall grade
double calculateGrade(double midtermsAverage, double quizzesAverage, double projectsAverage, double homeworkAverage)
{
    return midtermsAverage * 0.4 + quizzesAverage * 0.15 + projectsAverage * 0.3 + homeworkAverage * 0.15;
}

int main()
{
    char continueGrading;

    do
    {
        std::cout << "Hello, the purpose of this program is to calculate your grade percentage!\n";

        double projectsAverage = calculateAverage(4, 10, "Project");
        double quizzesAverage = calculateAverage(6, 10, "Quiz");
        double homeworkAverage = calculateAverage(7, 10, "Homework");
        double midtermsAverage = calculateAverage(2, 40, "Midterm");

        double gradeTotal = calculateGrade(midtermsAverage, quizzesAverage, projectsAverage, homeworkAverage);

        std::cout << "Your total grade percentage in the class is " << gradeTotal << "%!\n";

        std::cout << "Do you want to grade another set? (Y/N): ";
        std::cin >> continueGrading;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    } while (continueGrading == 'Y' || continueGrading == 'y');

    return 0;
}
