#include <iostream>
#include <climits>
#include <limits>

using namespace std;

//clear the buffer used for cin
void clearbuffer()
{
  cin.clear();  //clear the error flag on cin
  cin.ignore(numeric_limits<streamsize>::max(), '\n');  //skips up to numeric_limits<streamsize>::max() characters or until a new line is encountered
}

int main()
{
  cout << "-----------------------------TASK 1.1------------------------------\n";
  //This scenario returns the correct result because the two shorts are promoted to ints in the cout statement, and the result is also an int
  short x = 20000; 
  short y = 20000; 
  cout << "x + y = " << x + y << endl;
 
  //this scenario returns an incorrect result because the result is a short, which cannot hold x + y.
  short z = x + y;
  cout << "z=" << z << endl;

  //this scenario works because the result is an int, which can hold x + y.
  int z1 = x + y;
  cout << "z1 = " << z1 << endl;

  //this scenario also works for the same reasons, it's just that the typecasting is done explicitely rather than by the compiler.
  int z2 = (int)x + (int)y;
  cout << "z2 = " << z2 << endl;
			      
  cout << "-----------------------------TASK 1.2------------------------------\n";	      

  //YOUR CODE HERE - EXAMPLES 2.2a, b, c, d

  //this scenario does not work because longx + longy cannot fit in an int, which is what the result is stored as
  int longx = 2000000000;
  int longy = 2000000000;
  cout << "long x + y = " << longx + longy << endl;

  //this scenario also does not work, for the same reason as above
  int longz = longx + longy;
  cout << "long z = " << longz << endl;

  //this scenario also does not work since the arithmetic is automatically store in an int, which cannot hold longx + longy
  long long longz1 = longx + longy;
  cout << "longz = " << longz1 << endl;

  //this scenario does work since the two operands are typecast, indicating that the result should be a long long
  long long longz2 = (long long)longx + (long long)longy;
  cout <<  "long long z2 = " << longz2 << endl;
  
 
}//close the main function
