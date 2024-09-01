//Include the Standard Library
#include <iostream>
// Include the string library
#include <string>
#include <iomanip>
//include using namespace std if you don't want to keep writing std
//using namespace std;

std::string getName()
{
  std::string result;
  std::cout<< "What assignment group will you be calculating? ";
  std::cin>>result;
  return result;
}
int requestIntFromUser(std::string input)
{
  int result;
  std::cout << input;
  while (!(std::cin >> result))
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input. " << input;
    }
    return result;
}

float requestAFloat(std::string name, int iter, int min, float max)
{
  float input;
  /*
    TO DO!
    ADD a while loop around the message, so that it repeats whenever you don't get a valid number.
   ALSO ADD AN ERROR MESSAGE WHEN the user input is invalid

  */
  
  // Ask the user the message
  std::cout << "Please Enter the grade for "<<  name << " " << iter <<" followed by the enter key \n";
  while (!(std::cin >> input) || input < min || input > max)
  {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "Invalid input. Please enter a grade between " << min << " and " << max << ": ";
  }
    //return the float to whoever called you
  // stores the user input in the variable input
  return input;
}
void dropLowestGrade(float grades[], int& count)
{
    int minIndex = 0;
    for (int i = 1; i < count; ++i)
    {
        if (grades[i] < grades[minIndex])
        {
            minIndex = i;
        }
    }
    for (int i = minIndex; i < count - 1; ++i)
    {
        grades[i] = grades[i + 1];
    }
    count--;
}

double calculateAverage(std::string name, int count, int totalGrade, float extraC)
{
  double accumulator;
  float max = totalGrade * (1 + (extraC / 100));
  float grades[100]; // Assuming a maximum of 100 grades
  int i;//loop iteration number
  
  for (i = 1, accumulator = 0; i <= count; ++i)
  {
      grades[i - 1] = requestAFloat(name, i, 0, max);
  }

  if (name != "Midterm" && name != "midterm")
  {
      dropLowestGrade(grades, count);
  }

  for (int j = 0; j < count; ++j)
  {
      accumulator += grades[j];
  }

  double average = accumulator / count;
  double percentage = (average / totalGrade) * 100; // Calculate the percentage

  return percentage;
}


double requestAssignmentDetails()
{
    std::string assignmentName = getName();
    int numberOfAssignments = requestIntFromUser("Please Enter the number of assignments associated with " + assignmentName + ": ");
    int totalAssignmentGrade = requestIntFromUser("Please Enter the total grade possible for all assignments: ");
    float precentageofExtraCredit = requestAFloat("extra credit percentage", 1, 0, 100);

    return calculateAverage(assignmentName, numberOfAssignments, totalAssignmentGrade, precentageofExtraCredit);
}

double calculateGrade()
{
  return requestAssignmentDetails();
}

int main() 
{
  double gradeTotal;
  
  
  std::cout << "Hello, the purpose of this program is to calculate your grade precentage!\n";

  //calling functions to figure out what the values aught to be
  
  gradeTotal = calculateGrade();

    std::cout << "Your total grade percentage in the class is " << std::fixed << std::setprecision(2) << gradeTotal << "%!\n";
}