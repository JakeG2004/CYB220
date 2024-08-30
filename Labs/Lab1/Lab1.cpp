#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//This program gets up to 10 scores from a students, calculates the average and final grade
//Security: NO INPUT SANITIZATION, TYPE CHECKING AT ALL

void GetStrInput(char[], int size);

int main()
{
  //------DO NOT CHANGE THESE------
  int scores[10];
  char name[100] = "";
  char id[12] = "";
  int number_of_score = 0;
  double average = 0;
  int sum = 0;
  char grade = 'X';
  char comments[5] = "NONE";
  
  //------------------------------

  cout << "\n---------------------------------------\n";
  cout << "Welcome to the scoring system!" <<endl;

  cout << "Enter student's name: ";  //BUFFER OVERFLOW 
  GetStrInput(name, sizeof(name));

  cout << "\nPlease enter student ID: ";
  GetStrInput(id, sizeof(id));
  

  //NO INPUT SANITAZATION, TYPE CHECKING
  cout << "Enter up to 10 student's scores (0-100) (if done, enter -1 to stop): ";
  cout << endl;
  for (int i = 0; i< 10; i++)
  { 
    cout << "Score " << i+1 << ": ";
    int temp;
    cin >> temp;
  
    //  cout << "  temp is " << temp << endl;
    if (temp != -1)
    {
      scores[i] = temp;
      number_of_score++;
      sum = sum + temp;
    }

    else
    {
      break;
    }
  }

  if(number_of_score > 0)
  {
    average = sum / number_of_score;
  }

  else
  {
    average = 0;
  }

  cout << "Student's name is: " << name << endl;
  cout << "Student has " << number_of_score << " scores, sum is " << sum <<", and the average score is " << average << endl;

  // figure out the final grade, A, B, C, D, or F
  if( average >= 90)
    grade = 'A';
  if(average < 90 and average >= 80)
    grade = 'B';
  if (average < 80 and average >= 70)
    grade = 'C';
  if (average < 70 and average >= 60)
    grade = 'D';
  if (average < 60 and average >= 0)
    grade = 'F';
  
  cout << "Based on the average score, final grade is: " << grade << endl;

  cout << "looks good? (Yes or No)";
  cin.ignore();
  cin >> comments;  //BUFFER OVERFLOW, POSSIBLY OVERWRITE THE GRADE VARIABLE TO CHANGE THE FINAL GRADE OF A STUDENT

  cout << "Comments - Looks good? - " << comments << endl << endl;
  cout << "Student name: " << name << endl;
  cout << "Student ID: " << id <<endl;
  cout << "Final grade is: " << grade << endl <<endl;

  cout << "Program exits successfully..." <<endl;

}

void GetStrInput(char str[], int size)
{
  // ensure that input is valid
  while(strnlen(str, size) == 0)
  {
    //get user input
    if(fgets(str, size, stdin) == NULL)
    {
      printf("Error getting input; try again.\n");
      while (getchar() != '\n'); 
      continue;
    }

    //strip \n if it is present
    for(int i = 0; i < size; i++)
    {
      if(str[i] == '\n')
      {
        str[i] = '\0';
        break;
      }
    }

    // Check for extra input and discard it
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    //handle empty input
    if(strnlen(str, size) == 0)
    {
      printf("Invalid input. Try again: ");
    }
  }
}