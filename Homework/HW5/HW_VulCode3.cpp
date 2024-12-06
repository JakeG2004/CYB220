
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    // Vulnerability 1: uninitialized variable
    int x;
    cout << "The value of x is: " << x << endl;

    // Vulnerability 2: buffer overflow
    char str[10];
    strcpy(str, "Hello, world!"); // this overflows the buffer
    cout << "The string is: " << str << endl;

    // Vulnerability 3: integer overflow
    int a = 2147483647;
    int b = 2;
    int c = a * b; // this causes an integer overflow
    cout << "The value of c is: " << c << endl;

    // Vulnerability 4: off-by-one index error
    char arr[10];
    arr[10] = 'a'; // this accesses an array element out of bounds
    cout << "The value is: " << arr[10] << endl;

    // Vulnerability 5: type mismatch error
    int d = 5;
    double e = 3.14;
    int f = d + e; // this causes a type mismatch error
    cout << "The value of f is: " << f << endl;

    // Vulnerability 6: use-after-free
    int *ptr = new int;
    *ptr = 5;
    delete ptr;
    cout << "The value is: " << *ptr << endl; // this is a use-after-free error

    // Vulnerability 7: double free
    int *ptr2 = new int;
    delete ptr2;
    delete ptr2; // this is a double free error

    // Vulnerability 8: unsafe string manipulation function
    char dest[10] = "hello";
    char src[10] = "world";
    strcat(dest, src); // this can cause a buffer overflow
    cout << "The string is: " << dest << endl;

    // Vulnerability 9: format string vulnerability
    char fmt[50];
    char user_input[100];
    cout << "Please enter an input: ";
    strcpy(fmt, "Entered input: ");
    cin >> user_input; // enter something like %x%x%x%x
    strcat(fmt, user_input);
    printf(fmt); // this can be used to execute a format string attack

    // Vulnerability 10: Out of Bounds Read
    cout << "\nOut of bounds memory: " << *(user_input + 110) << endl;

    return 0;
}
