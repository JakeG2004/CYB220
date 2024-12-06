#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	int var = 10;
	int uninitVar; //This variable is uninitialized.
	int userInt;
	int longInt = 2000000000;
	char userInput[8];
	char *buffer1;
	char *buffer2;
	char *buffer3;
	char *buffer4;
	char *buffer5;
	char *buffer6;
	char *buffer7;
	char *buffer8;
	char userString[1024];
	char string1[] = "This is code to be copied.";
	char string2[10];
	char printfError[10];
	char nullTerm[16];

	//In this section, our uninitialized variable is added to another variable 
	//with value 10. This will be random each time as uninitVar is uninitialized.
	cout << uninitVar + var << endl;
	cout << endl;
	
	//In this section, the userInput not having length checking may cause the password
	//to be subject to a buffer overflow attack.
	cout << "Enter the password (password): ";
	cin >> userInput; //This user input method allows buffer overflow attacks.
	if (strcmp(userInput, "password") == 0)
	{
		cout << "You entered the password!" << endl;
	}
	else
	{
		cout << "You did not enter the password." << endl;
	}
	cout << endl;

	//In this section, the longInt variable is subject to an integer overflow attack
	//when userInt is added to it.
	cout << "Enter any number: ";
	cin >> userInt;
	cout << userInt << " + " << longInt << " = " << userInt + longInt << endl;
	cout << endl;
	
	//This section contains an off-by-one error in the for loop where var should
	//add up to 20, but only makes it to 19 due to poor formatting of code.
	cout << "var = 10" << endl;
	for(int i = 1; i < 10; ++i)
	{
		var++;
	}
	cout <<"For loop: " << endl;
	cout << "var should now = 20" << endl;
	cout << var << endl;
	cout << endl;

	//This section features a type mismatch when adding an int and a short and then
	//storing the data in another int.
	int x = 5;
	short a = 5;
	int z;
	z = x+a;
	cout << "int x = 5, short a = 5, z = x+a, z = " << z << endl;
	cout << endl;

	//This section contains a Use-after-free error where the char pointer buffer2 is freed after 
	//being declared, but is called after it is freed.
	buffer1 = (char *) malloc(512);
	buffer2 = (char *) malloc(512);
	free(buffer2);
	buffer3 = (char *) malloc(248);
	buffer4 = (char *) malloc(248);
	strncpy(buffer2, "a", 511);
	free(buffer1);
	free(buffer3);
	free(buffer4);
	
	//In this section, the char pointer buffer6 is accidentally freed twice, causing a 
	//Double-free error
	buffer5 = (char *) malloc(248);
	buffer6 = (char *) malloc(248);
	free(buffer5);
	free(buffer6);
	buffer7 = (char *) malloc(512);
	strncpy(buffer7, "a", 511);
	free(buffer6);
	free(buffer7);	

	//This section features an unsafe use of the function strcpy. Since this function does not
	//do any length checking, if string1 is too long it will lead to buffer overflow.
	strcpy(string2, string1);
	cout << "String 2 is now: " << string2 << endl;
	cout << endl;

	//This section contains a format string vulnerability using printf. As the printf in this chunk
	//of code does not specify type, it is subject to code injection.
	cout << "Enter any word: " << endl;
	cin >> printfError;
	cout << "Your word is: ";
	printf(printfError);
	
	//This section contains a dead variable error.
	buffer8 = (char *) malloc(1024);

	return 0;

}
