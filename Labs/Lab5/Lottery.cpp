// This program is to simulate Powerball and Mega Millions

/*[CYB220] Lab requirements:
 * This is a CS120 homework submission. 
 * IMPORTANT: You don't need to find the security related bugs (input validation, type checking)
 * (6 pts) 1. Fixed the arrays and make sure the arrays are shuffled correctly! (This does not count toward a coding problem!)
 * (24 pts) 2. There are at least 4 subtle coding problems in the code, find 3 of them to get full points
 *    a. Read the homework requirement and Do a code review to find the problems
 *    b. Write a comment near the problem code, start your comment with [CYB220]
 *    c. Fix the code!
 *    3. SUBMIT THIS .CPP FILE to CANVAS
 */

//NOTE1: array shuffle does not count as 1 coding problem.
//NOTE2: Same type of issue at different places count as 1 coding problem.
//NOTE3: Users entering a very large number, with characters and type mismatch, are not the type of problem we are looking for in this lab.
//[CYB220] Start your comments like this (with [CYB220]) to make my grading easier. Thanks!

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void ShuffleArray(int arr[], int arrSize);

int main ()
{
	int PowerBallW[69]; //Array for PowerBall White
	int PowerBallR[26]; //Array for PowerBall Red

	int MegaMilW[70]; //Array for MegaMillions White
	int MegaMilR[25];//Array for MegaMillions Red

	int j = 0; //A variable to make choice loop work.

	int White[5]; //Array for user input for white

	int Red =0; //Variable for user input for red 

	int random = 0; //Variable for random number in array
	int choice =0; //Variable storage for user choice

	int correctWhite = 0;
	int win_red = 0;
	int redMatch = 0;

	srand(time(NULL));
	//[CYB220] ERROR: i++ called in for loop statement as well as in the loop, leading to every other value getting skipped
	//----------------------Initialize Arrays-------------------------
	for(int i=0; i<69; i++){
		PowerBallW[i]= i+1;
		//i++;
	}
	for(int i=0; i<26; i++){
		PowerBallR[i]= i+1;
		//i++;
	}
	for(int i=0; i<70; i++){
		MegaMilW[i]= i+1;
		//i++;
	}
	for(int i=0; i<25; i++){
		MegaMilR[i]= i+1;
		//i++;
	}


	//Prompt user and get user choice
	do{
		cout << "Would you like to play MegaMillions or PowerBall?" << endl;
		cout << "Please enter 1 for Megamillions and 2 for PowerBall." <<endl;

		cin >> choice;

		//[CYB220] choice is not properly selected here since j is initialized to 0, and only incremented, not set.
		/*if (choice == 1)
		{
			j++;
		}
		
		else if (choice == 2)
		{
			j++;
		}*/

		if(choice == 1 || choice == 2)
		{
			j = choice;
		}
		
		else 
		{
			cout << "Error. Please enter a valid option." << endl;
		}

	//[CYB220] Fix loop iterator
	} while (j != 1 && j != 2);

	//Print user choice
	if (choice == 1)
	{
		cout << "You have chosen to play MegaMillions." <<endl;
	} 
	
	else 
	{
		cout << "You have chosen to play PowerBall." <<endl;
	}

	cout << "Please enter 5 numbers for the white ball numbers you wish to play with." << endl;

	//get 5 numbers from the user
	for (int i=0; i<5; i++)
	{
		//redefinition of j
		int j =0;

		if (choice == 1)
		{ // Conditionals for valid numbers.
			cout << "Please choose numbers between 1 & 70." << endl;
			cin >> White[i];
			if (White[i] <1 || White[i] >70) 
			{
				do
				{
					//[CYB220] reset valid input flag
					j = 0;
					cout << "Invalid number." << endl << "Try again. Please enter a number." << endl;
					cin >>White[i];

					if (White[i] > 1 && White[i] <= 70)
					{
						j++;
					} 
					
					else 
					{
						cout << "No." << endl;
					}
				} while (j==0);
			}	
		} 
		
		else 
		{
			cout << "Please choose numbers between 1 & 69." << endl;
			//[CYB220] missing cin statement here
			cin >> White[i];
			if (White[i] <1 || White[i] >69) 
			{
				do
				{
					//[CYB220] reset valid input flag
					j = 0;
					cout << "Invalid number." << endl << "Try again. Please enter a number." << endl;
					cin >>White[i];

					if (White[i] >1 && White[i] <=69)
					{
						j++;
					} 
					
					else 
					{
						cout << "No." << endl;
					}
				} while (j==0);
			}
		}
		
	
	}

	// Condition flag
	j = 0;

	if (choice == 1) 
	{
		cout << "Please enter one number for the red ball." << endl;
		cout << "Your number should be between 1 and 25." << endl;
		cin >> Red;
		if (Red < 1 || Red > 25) 
		{
			do
			{
				cout << "Invalid number." << endl << "Try again. Please enter a number." << endl;
				cin >>Red;

				if (Red > 1 && Red <= 25)
				{
					j++;
				} 
				
				else 
				{
					cout << "No." <<endl;
				}
			} while (j==0);
		} 
	} 
	
	else 
	{
		cout << "Please enter one number for the red ball." << endl;
		cout << "Your number should be between 1 and 26." << endl;
		//[CYB220] missing cin statement here
		cin >> Red;
		if (Red < 1 || Red > 26) 
		{
			do
			{
				cout << "Invalid number." << endl << "Try again. Please enter a number." << endl;
				cin >>Red;

				if (Red > 1 && Red <= 26)
				{
					j++;
				} 
				
				else 
				{
						cout << "No. " << endl;
				}
			} while (j==0);
		}
		
	}
	cout << "You have chosen for the white balls the numbers: " << White[0]<< " " << White[1] << " " << White[2]<<" " <<White[3] << " " << White[4] << "." << endl<< endl;
	cout << "You have chosen for the red ball: " << Red << "."<<endl;
	cout << "-----------------------------------------" << endl << endl;

	// Shuffle arrays

	// Megamillions
	if (choice == 1)
	{
		ShuffleArray(MegaMilW, 70);
	} 

	// Powerball
	else 
	{
		ShuffleArray(PowerBallW, 69);
	}

	cout << "********* Now the results are: **********" << endl;
	
	//check the first 5 elements of the array and compare them with the white balls
	if(choice == 1)
	{
	  cout << "The winning white balls are: ";
	  for(int i=0; i<5; i++)
	  {
	    cout << MegaMilW[i] << " ";
	    if (White[0] == MegaMilW[i] || White[1] == MegaMilW[i]||White[2] == MegaMilW[i]|| White[3] == MegaMilW[i]|| White[4] == MegaMilW[i])
	      correctWhite++;
	  }

	  //[CYB220] correct bounds on red
	  win_red = (rand() % 25) + 1;
	}

	else
	{  
	  cout << "The winning white balls are: ";
	  for(int i=0; i<5;i++)
	  {
	    cout << PowerBallW[i] << " ";
	    if (White[0] == PowerBallW[i] || White[1] == PowerBallW[i]||White[2] == PowerBallW[i]|| White[3] == PowerBallW[i]|| White[4] == PowerBallW[i])
	      correctWhite++;
	  }
	  //[CYB220] correct bounds on red
	  win_red = (rand() % 26) + 1;
	}
	
	cout << "\n\nYou have " << correctWhite << " White balls matched!" <<endl;

	cout << "The winning red ball is: " << win_red << endl;
	cout << "The red ball you guessed: " << Red << endl;
	if (Red == win_red)
	{
	  cout << "Your guessed correctly!" <<endl;
	}

	else 
	{
	  cout << "You missed the red ball..." <<endl;
	}
	
	//[CYB220] print statement only worked on MegaMillions array, not powerball array
	if(choice == 1)
	{
		printf("MegaMillions array:\n");
		for(int i=0; i<70;i++)
		{ // loop to see if shuffle worked.
			cout << MegaMilW[i] << " ";
		}
	}

	else
	{
		printf("Powerball array:\n");
		for(int i=0; i<69; i++)
		{ // loop to see if shuffle worked.
			cout << PowerBallW[i] << " ";
		}
	}

	cout << endl <<endl;
	return 0;
}

void ShuffleArray(int arr[], int arrSize)
{
	//set up arrays
	int buffer[arrSize];
	int usedIndecesInBuffer[arrSize];

	//init randindex value
	int randIndex = 0;

	bool validInput = false;

	//initialize usedindeces array
	for(int i = 0; i < arrSize; i++)
	{
		usedIndecesInBuffer[i] = 0;
	}

	//shuffle array
	for(int i = 0; i < arrSize; i++)
	{
		//set input flag to false
		validInput = false;

		//choose a valid index that hasn't been used
		while(validInput == false)
		{
			randIndex = rand() % arrSize;

			if(usedIndecesInBuffer[randIndex] == 0)
			{
				validInput = true;
			}
		}

		//set index to used
		usedIndecesInBuffer[randIndex] = 1;

		//fill buffer accordingly
		buffer[i] = arr[randIndex];
	}

	//copy buffer back to original
	for(int i = 0; i < arrSize; i++)
	{
		arr[i] = buffer[i];
	}
}


