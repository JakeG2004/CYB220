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
  cout << "--------------------------TASK 1----------------------------------------\n";
  
    cout << " -------- singed int ------------\n";
    int num;
    cout << "num is declared as a signed int (" << sizeof(int) << "  bytes - MAX: " << INT_MAX << " MIN: " << INT_MIN << " )" << endl;
    cout << "The default assignment is: num = 2147483999 \n";
    num = 2147483999;
    cout << "After the assignment, the value stored in num is: " << num << endl;
    cout << "Now give it a value, first run? just type 2147483999" << endl;
    cout << "You input is: ";
    cin >> num;
    cout << "The value stored in num is: " << num << endl;
    clearbuffer();

  
    cout << "\n -------- unsinged int ------------\n";
    unsigned int u_num;    
    cout << "u_num is declared as a unsigned int( " << sizeof(unsigned int) << " bytes - MAX: " << UINT_MAX << " MIN: 0 )" << endl;
    cout << "The default assignment is: u_num = 5000000000 \n";
    u_num =5000000000;
    cout << "After the assignment, the value stored in u_num is: " << u_num << endl;
    cout << "Now it is your turn, your input is: ";
    cin >> u_num;
    cout << "The value stored in u_num is: " << u_num << endl;
    clearbuffer();

    cout << "\n -------- singed short ------------\n";
    short short_num; 
    cout << "short_num is declared as a signed short ( " << sizeof(short) << " bytes - MAX: " << SHRT_MAX << " MIN: " << SHRT_MIN << " )" << endl;
    cout << "The default assignment is: short_num = -50000 \n";
    short_num = -50000;
    cout << "After the assignment, the value stored in short_num is: " << short_num << endl;
    cout << "Now give it a value, your input is: ";
    cin >> short_num;
    cout << "The value stored in short_num is: " << short_num << endl;
    clearbuffer();

    cout << "\n -------- unsinged short ------------\n";
    unsigned short u_short_num;
    cout << "u_short_num is declared as a unsigned short ( " << sizeof(unsigned short) << " bytes - MAX: " << USHRT_MAX << " MIN: 0 )" << endl;
    cout << "The default assignment is: u_short_num = -50 \n";
    u_short_num = -50;
    cout << "After the assignment, the value stored in u_short_num is: " << u_short_num << endl;
    cout << "Now you give a value to it: ";
    cin >> u_short_num;
    cout << "The value stored in u_short_num is: " << u_short_num << endl;
    clearbuffer();

  

  cout << "-----------------------------TASK 2.1------------------------------\n";
  //example 2.1a
  short x = 20000; 
  short y = 20000; 
  cout << "x + y = " << x + y << endl;
 
  
  //YOUR CODE HERE - EXAMPLES 2.1b, c, d
  short z = x + y;
  cout << "z=" << z << endl;

  int z1 = x + y;
  int z2 = (int)x + (int)y;

  cout << "int z1 = " << z1 << endl << "int z2 = " << z2 << endl;
			      
  cout << "-----------------------------TASK 2.2------------------------------\n";	      

  //YOUR CODE HERE - EXAMPLES 2.2a, b, c, d

  int longx = 2000000000;
  int longy = 2000000000;

  cout << "long x + y = " << longx + longy << endl;

  int longz = longx + longy;
  cout << "long z= " << longz << endl;

  long long longz1 = longx + longy;
  long long longz2 = (long long)longx + (long long)longy;

  cout << "long long z1 = " << longz1 << endl << "long long z2 = " << longz2 << endl;
  
  cout << "--------------------------TASK 3---------------------------------------\n";
  // signed int
  cout << "int min is = " << INT_MIN << " & size of = " << sizeof(INT_MIN) << endl;  
  cout << "int max is = " << INT_MAX << " & size of = " << sizeof(INT_MAX) << endl; 
    
  //unsigned int 
  cout << "unsigned int max is = " << UINT_MAX << " & size of = " << sizeof(UINT_MAX) << endl <<endl; //min is 0 
  cout << "uint min is = 0" << endl;
    
  //char 
  printf("char min is %i and size of %li\n", CHAR_MIN, sizeof(CHAR_MIN));
  printf("char max is %i with size %li\n", CHAR_MAX, sizeof(CHAR_MAX));
    
  //unsigned char  
  printf("unsigned char has min 0\n");
  printf("unsigned char has max %i and size %li\n", UCHAR_MAX, sizeof(UCHAR_MAX));
    
  //short 
  printf("short min is %i with size %li\n", SHRT_MIN, sizeof(SHRT_MIN));
  printf("short max is %i with size %li\n", SHRT_MAX, sizeof(SHRT_MAX));
    
  //unsigned short 
  printf("unsigned short min 0\n");
  printf("unsigned short max is %i with size %li\n", USHRT_MAX, sizeof(USHRT_MAX));
    
  //long 
  printf("long min is %li with size %li\n", LONG_MIN, sizeof(LONG_LONG_MIN));
  printf("long max is %li with size %li\n", LONG_MAX, sizeof(LONG_MAX));
    
  //unsigned long
  printf("ulong has min 0\n");
  printf("ulong has max %li with size %li\n", ULONG_MAX, sizeof(ULONG_MAX));

  //long long
  printf("long long has min %lli and size %li\n", LLONG_MIN, sizeof(LLONG_MIN));
  printf("long long has max %lli with size %li\n", LLONG_MAX, sizeof(LLONG_MAX));
    
  //unsigned long long
  printf("ulong long has min 0\n");
  printf("ulong long has max %lli and size %li\n", ULLONG_MAX, sizeof(ULLONG_MAX));

}//close the main function
