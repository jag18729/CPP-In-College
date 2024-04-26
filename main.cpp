#include <stdio.h>

/*
This function returns a float and takes a string (character array) as it's input paramater
Use this whenever you want to get user input.
  */
float requestAFloat(char msg[])
{
    float input;
    // Ask the user the message
    printf(msg);

    // stores the user input in the variable input
    scanf("%f", &input);
    // return the float to whoever called you
    return input;
}
double calculateAverageProjectPercentage()
{
    // declare your variables within the function
    double result;
    float project1;
    float project2;
    float project3;
    float project4;

    /*initialize your variables with numbers*/
    // getting the precentage for project 1
    project1 = requestAFloat("Please enter the grade for Project 1 (out of 10) followed by the enter key: ");
    // getting the precentage for project 2
    project1 = requestAFloat("Please enter the grade for Project 2 (out of 10) followed by the enter key: ");
    // getting the precentage for project 3
    project3 = requestAFloat("Please enter the grade for Project 3 (out of 10) followed by the enter key: ");
    // getting the precentage for project 4
    project4 = requestAFloat("Please enter the grade for Project 4 (out of 10) followed by the enter key: ");

    // calculate your return value
    // initialize result
    result = 0;

    // return your result
    return result;
}

double calculateAverageCengageHomework()
{
    double result;
    float homework1;
    float homework2;
    float homework3;
    float homework4;
    float homework5;
    float homework6;
    float homework7;
    // initialize your variables with numbers
    homework1 = requestAFloat("Please enter the grade for Homework 1 (out of 10) followed by the enter key:");
    // initialize your variables with numbers
    homework2 = requestAFloat("Please enter the grade for Homework 2 (out of 10) followed by the enter key:");
    homework3 = requestAFloat("Please enter the grade for Homework 3 (out of 10) followed by the enter key:");
    homework4 = requestAFloat("Please enter the grade for Homework 4 (out of 10) followed by the enter key:");
    homework5 = requestAFloat("Please enter the grade for Homework 5 (out of 10) followed by the enter key:");
    homework6 = requestAFloat("Please enter the grade for Homework 6 (out of 10) followed by the enter key:");
    homework7 = requestAFloat("Please enter the grade for Homework 7 (out of 10) followed by the enter key:");
    // calculate your return value
    // initialize result
    result = 0;

    // return your result
    return result;
}

double calculateAverageMidtermPercentage()
{
    // declare your variables within the function
    double result;
    float midterm1;
    float midterm2;

    /*initialize your variables with numbers*/
    // getting the precentage for midterm 1
    midterm1 = requestAFloat("Please enter the grade for Midterm 1 (out of 40) followed by the enter key: ");
    // getting the precentage for midterm 2
    midterm2 = requestAFloat("Please enter the grade for Midterm 2 (out of 40) followed by the enter key: ");

    // calculate your return value
    // initialize result
    result = 0;

    // return your result
    return result;
}
double calculateAverageQuizPercentage()
{
    double result;
    float quiz1;
    float quiz2;
    float quiz3;
    float quiz4;
    float quiz5;
    float quiz6;
    // initialize your variables with numbers
    quiz1 = requestAFloat("Please enter the grade for Quiz 1 (out of 10) followed by the enter key:");
    // initialize your variables with numbers
    quiz2 = requestAFloat("Please enter the grade for Quiz 2 (out of 10) followed by the enter key:");
    quiz3 = requestAFloat("Please enter the grade for Quiz 3 (out of 10) followed by the enter key:");
    quiz4 = requestAFloat("Please enter the grade for Quiz 4 (out of 10) followed by the enter key:");
    quiz5 = requestAFloat("Please enter the grade for Quiz 5 (out of 10) followed by the enter key:");
    quiz6 = requestAFloat("Please enter the grade for Quiz 6 (out of 10) followed by the enter key:");
    // calculate your return value
    // initialize result
    result = 0;

    // return your result
    return result;
}
double calculateGrade(double midtermsAverage, double quizesAverage, double projectsAverage, double homeworkAverage)
{
    // calulate the actual precentage
    // midterms are out of 40 and count for 40% of your grade
    double result = (midtermsAverage);
    // Quizes are out of 10 and count for 15% of your grade
    result += quizesAverage * 1.5;
    // Projects are out of 10 and count for 30% of your grade
    result += projectsAverage * 3;
    result += homeworkAverage * 1.5;
    return result;
}

int main(void)
{
    double gradeTotal;
    double midtermAverage;
    double homeworkAverage;
    double quizesAverage;
    double projectsAverage;
    // your program starts here
    printf("Hello, the purpose of this program is to calculate your grade precentage!\n");

    // calling functions to figure out what the values aught to be
    midtermAverage = calculateAverageMidtermPercentage();
    quizesAverage = calculateAverageQuizPercentage();
    projectsAverage = calculateAverageProjectPercentage();
    homeworkAverage = calculateAverageCengageHomework();
    gradeTotal = calculateGrade(midtermAverage, quizesAverage, projectsAverage, homeworkAverage);

    printf("Your total grade precentage in the class is %.2f!\n", gradeTotal);

    return 0;
}