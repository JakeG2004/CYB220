#include <stdio.h>

void g(int* ptr)
{
    printf("Value: %i\n", *ptr);
}

int main()
{
    int x = 9;
    int* ptr = &x;
    g(ptr);
    return 0;
}