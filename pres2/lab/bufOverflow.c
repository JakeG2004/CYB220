#include <stdio.h>

void FillArray() 
{
    char buffer[10];
    for (int i = 0; i <= 10; i++)  // Off-by-one error
    {
        buffer[i] = 'a';  // Buffer overflow on the last iteration
    }
}

int main() 
{
    FillArray();
    return 0;
}
