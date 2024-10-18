#include <iostream>
#include <limits>
#include <limits.h>
using namespace std;


int main(){

  //know the range of data types 
  /*cout << "short: sizeof(short) is " << sizeof(short) << " bytes" << endl;
  cout << "\tmax is " << SHRT_MAX << ", min is " <<SHRT_MIN << endl;
  cout << "int: sizeof(int) is " << sizeof(int) << " bytes" << endl;
  cout << "\tmax is " << INT_MAX << ", min is " <<INT_MIN << endl;
  cout << "long: sizeof(long int) is " << sizeof(long int) << " bytes" << endl;
  cout << "\tmax is " << LONG_MAX << ", min is " <<LONG_MIN << endl;
  cout << "long long: sizeof(long long int) is " << sizeof(long long int) << " bytes" << endl;
  cout << "\tmax is " << LLONG_MAX << ", min is " <<LLONG_MIN << endl;*/

  cout << "---------- Task 1-------------" <<endl;
  /* Task 1: explain why you got correct or overflowed value in the following 10 examples.
     Note: Your answer should focus on what type conversions happened.
  */
  
  //for example
  //1a, x and y are first integer promoted to be int before the addition. Then the result of x+y (int) is stored in a register, the register is big enough to hold the result of 20000+20000, so output value is the correct value.
  short x = 20000;
  short y = 20000;
  cout << "x + y = " << x+y << endl;

	//this scenario does not work. The result is stored in a short, which cannot fit x + y.
  x = 20000; 
  y = 20000; 
  short z = x + y; //z is out of range now 
  cout << "z = " << z << endl; 

  //this scenario works because the result is an int, which can hold x + y.
  x = 20000; 
  y = 20000; 
  int z1 = x + y; 
  cout << "int z1 = " << z1 << endl; 

  //this scenario also works for the same reasons, it's just that the typecasting is done explicitely rather than by the compiler.
  x = 20000; 
  y = 20000;
  int z2 = (int)x + (int)y; 
  cout << "int z2 = " << z2 << endl;

	printf("\n=======================LONG===================\n\n");

  //this scenario does not work because x_int + y_int cannot fit in an int, which is what the result is stored as
  int x_int = 2000000000; 
  int y_int = 2000000000; 
  cout << "x_int + y_int = " << x_int + y_int << endl;

  //this scenario works because the operands are long long, meaning that the resulting type is also a long long
  long long  x_int_ll = 2000000000; 
  long long  y_int_ll = 2000000000; 
  cout << "x_int_ll + y_int_ll = " << x_int_ll + y_int_ll << endl;

  //this scenario also does not work since the solution is stored in an int, which cannot hold x_int + y_int
  x_int = 2000000000; 
  y_int = 2000000000; 
  int z_int = x_int + y_int; //z is out of range now 
  cout << "z_int = " << z_int << endl; 
  
  //this example works because the resulting is automatically cast to a long long, since that is what the return type is
  x_int = 2000000000; 
  y_int = 2000000000; 
  long long z1_ll = x_int + y_int; 
  cout << "long z1_ll = " << z1_ll << endl;

  //This example works because x_int gets promoted to a long long during arithmetic, and the result is stored in a long long.
  x_int = 2000000000; 
  long long y_ll = 2000000000;
  long long z2_ll = x_int + y_ll; 
  cout << "long long z2_ll = " << z2_ll << endl;

  //This example works for the same reason as above, except the typecasting is explicit instead of handled by the compiler
  x_int = 2000000000; 
  y_int = 2000000000;
  long long z2_llong = (long long)x_int + (long long)y_int; 
  cout << "long long z2_llong = " << z2_llong << endl;




  cout << "---------------Task 2-------------" <<endl;
  //-----task2: add in checks---------
  //for addition, subtruction, and division operations
  //for example, for addition operation
  
  int num1, num2, result_add, result_sub, result_div;
  cout << "For addition operation: " <<endl;
  cout << "    Enter integer1: ";
  cin >> num1;
  cout << "    Enter integer2: ";
  cin >> num2;

  //checks for addition operation
  if ((num1 > 0) && (num2 >0) && (num1 > (INT_MAX - num2)))
  {
    printf("Integer overflow!\n");
    exit(-1);
  }

	if((num1 < 0) && (num2 < 0) && (num1 < (INT_MIN - num2)))
  {
    cout << "Integer underflow!" <<endl;
    exit(1);
  }

  else 
	{
    result_add = num1+num2;
    cout << "sum of integer1 and integer2 is: " << result_add <<endl;
  }

  //Your turn, for subtraction operation, add checks

  cout << "For subtraction operation: " <<endl;
  cout << "Enter integer1: ";
  cin >> num1;
  cout << "Enter integer2: ";
  cin >> num2;

	//check subtraction
	//will get underflow if num1 is negative, num2 is positive, and num1-num2 < INT_MIN -> num1 < INT_MIN + num2
	if((num1 < 0) && (num2 > 0) && (num1 < (INT_MIN + num2)))
	{
		printf("Integer underflow!\n");
		exit(-1);
	}

	//will get overflow if num1 is positive, num2 is negative, and num1-num2 > INT_MAX -> num1 > INT_MAX - (-1 * num2)
	if((num1 > 0) && (num2 < 0) && (num1 > (INT_MAX + num2)))
	{
		printf("Integer overflow!\n");
		exit(-1);
	}

  result_sub = num1-num2;
	printf("Resultof subtraction: %i\n", result_sub);

  //for division operation, add checks
  //HINTS:(1) we talked about when integer overflow could happen in division :)
  //          you need to check for that specific condition
  //      (2) your code should also check for the divide by 0 problem!
  cout << "For division operation: " <<endl;
  cout << "Enter integer1: ";
  cin >> num1;
  cout << "Enter integer2: ";
  cin >> num2;

	//check overflow
  if(num1 == INT_MIN && num2 == -1)
	{
		printf("Integer overflow!\n");
		exit(-1);
	}

	//check divide by 0
	if(num2 == 0)
	{
		printf("Divide by 0\n");
		exit(-1);
	}

  result_div = num1/num2; 
	printf("Result of division: %i\n", result_div);




  //Don't forget to run your program to test whether your checks can catch the integer overflows/underflow.
  
  //For lab 4, you only need to turn in this .cpp file.
  //your explanations should be written as comments in this .cpp file
}
