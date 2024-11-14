#include <limits.h>
#include <stdio.h>

int main()
{
    short int x = SHRT_MAX;
    x = x + 1;
    printf("%i\n", x);
}