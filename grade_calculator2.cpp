// *** Project 2 - Grade Calculator ***
// Name: Rafael Garcia
// Date: 05/5/2024

// Description:
// This program calculates the total grade percentage of a student based on the weighted averages of their scores in four categories: projects, quizzes, homework, and midterms. The program prompts the user to input the grades for each category and calculates the total grade percentage based on the specified criteria. The program uses functions to handle input validation, calculate weighted averages, and compute the total grade percentage. The user can choose to calculate another set of grades or exit the program.
#include <iostream>
#include <cstdio>
#include <limits>

// Function to request a float from the user within a specified range
// Validates input to ensure it falls within the expected range and is a float
float requestAFloat(const std::string& name, int iter, float min, float max) {
    float input;
    bool isValidInput = false;

    while (!isValidInput) {
        std::cout << "Please enter the grade for " << name << " " << iter << " followed by the enter key (range " << min << " - " << max << "): ";
        std::cin >> input;

        // Check for input failure or out of range values
        if (std::cin.fail() || input < min || input > max) {
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard incorrect input
            std::cout << "Invalid input. Grades must be between " << min << " and " << max << ". Please try again.\n";
        } else {
            isValidInput = true; // Valid input received, break the loop
        }
    }
    return input;
}

// Function to calculate the average score for a given component (midterms, quizzes, or projects)
double calculateAverage(const std::string& name, int count, float totalGrade, float extraC) {
    double accumulator = 0; // Sum of all grades
    float max = totalGrade * (1 + (extraC / 100)); // Maximum grade possible including extra credit

    // Sum grades for each item
    for (int i = 1; i <= count; i++) {
        accumulator += requestAFloat(name, i, 0, max);
    }

    // Return the average grade
    return accumulator / count;
}

// Function to calculate the final grade percentage based on averages and their weightings
double calculateGrade(double midtermsAverage, double quizzesAverage, double projectsAverage) {
    // Normalize averages by converting them to percentages
    double midtermPercent = (midtermsAverage / 40) * 100;
    double quizzesPercent = (quizzesAverage / 10) * 100;
    double projectsPercent = (projectsAverage / 10) * 100;

    // Calculate final grade using weighted average
    double result = (midtermPercent * 0.4) + (quizzesPercent * 0.3) + (projectsPercent * 0.3);
    return result;
}

int main() {
    double gradeTotal;
    double midtermAverage, quizzesAverage, projectsAverage;

    std::cout << "Hello, the purpose of this program is to calculate your grade percentage!\n";
    
    // Calculate average grades for midterms, quizzes, and projects
    midtermAverage = calculateAverage("Midterm", 2, 40, 10);
    quizzesAverage = calculateAverage("Quiz", 6, 10, 0);
    projectsAverage = calculateAverage("Project", 6, 10, 0);

    // Compute the final grade percentage
    gradeTotal = calculateGrade(midtermAverage, quizzesAverage, projectsAverage);

    // Output the final grade percentage
    printf("Your total grade percentage in the class is %.2f%%!\n", gradeTotal);

    return 0;
}
