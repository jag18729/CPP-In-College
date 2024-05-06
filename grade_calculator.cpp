// *** Grade Calculator ***
// Name: Rafael Garcia
// Date: 04/25/2024

// Description:
// This program calculates the total grade percentage of a student based on the weighted averages of their scores in four
// categories: projects, quizzes, homework, and midterms. The program prompts the user to input the grades for each category and
// calculates the total grade percentage based on the specified criteria. The program uses functions to handle input validation,
// calculate weighted averages, and compute the total grade percentage. The user can choose to calculate another set of grades or
// exit the program.

#include <iostream>
#include <string>
#include <limits>
#include <iomanip> // Include to control input/output formatting

// Requests a float input from the user within a specified range with error handling
float requestAFloat(const std::string &msg, float min, float max)
{
    float input;
    std::cout << msg;
    // Validates input to ensure it's a float within the specified range
    while (!(std::cin >> input) || input < min || input > max)
    {
        std::cin.clear();                                                   // Clears error flag on cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears the input buffer
        std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
        std::cout << msg;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears the input buffer after valid input
    return input;
}

// Calculates the weighted average of scores for a specific category
double calculateWeightedAverage(int count, float maxScore, const std::string &description, double weight)
{
    double sum = 0;
    for (int i = 1; i <= count; i++)
    {
        // Constructs a prompt message for each score input
        std::string prompt = "Enter the grade for " + description + " " + std::to_string(i) + " (out of " + std::to_string(static_cast<int>(maxScore)) + "): ";
        // Accumulates the sum of scores
        sum += requestAFloat(prompt, 0, maxScore);
    }
    double average = sum / count;
    // Returns the normalized and weighted average
    return (average / maxScore) * weight;
}

// Calculates the total grade percentage based on weighted averages
double calculateGrade(double midtermsAverage, double quizzesAverage, double projectsAverage, double homeworkAverage)
{
    return projectsAverage + quizzesAverage + homeworkAverage + midtermsAverage;
}

// The main function orchestrates the grade calculation process
int main()
{
    // Prints the welcome message
    std::cout << "Welcome to the Grade Calculator!\n";
    char continueResponse;

    do
    {
        // Calculate weighted averages for each category
        double projectsWeighted = calculateWeightedAverage(4, 10, "Project", 30);
        double quizzesWeighted = calculateWeightedAverage(6, 6, "Quiz", 15);
        double homeworkWeighted = calculateWeightedAverage(7, 10, "Homework", 15);
        double midtermsWeighted = calculateWeightedAverage(2, 40, "Midterm", 40);

        // Sum the weighted averages to compute the total grade percentage
        double gradeTotal = calculateGrade(projectsWeighted, quizzesWeighted, homeworkWeighted, midtermsWeighted);

        // Sets fixed-point notation with two decimal places for the output
        std::cout << std::fixed << std::setprecision(2);
        // Prints the calculated total grade percentage
        std::cout << "Your total grade percentage in the class is " << gradeTotal << "%.\n";

        // Asks user if they want to perform another calculation
        std::cout << "Do you want to calculate another set of grades? (Y/N): ";
        std::cin >> continueResponse;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clears the input buffer after reading a character
    } while (continueResponse == 'Y' || continueResponse == 'y');

    return 0;
}
