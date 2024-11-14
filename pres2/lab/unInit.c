#include <stdio.h>

int main() 
{
    int x;
    int y = 10;

    if (y > 5 && x == 0)  // x is uninitialized but used in a condition
    {
        printf("Condition met\n");
    }

    return 0;
}
