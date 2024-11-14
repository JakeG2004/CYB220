#include <stdio.h>

void ProcessData(int* ptr) 
{
    if (ptr != NULL || *ptr == 0)  // Misleading condition
    {
        printf("Value: %d\n", *ptr);
    }
}

int main() 
{
    int* ptr = NULL;
    ProcessData(ptr);  // NULL dereference happens here
    return 0;
}
