#include <stdio.h>

void ReadFile() 
{
    FILE* file = fopen("example.txt", "r");
    if (!file) return;

    // Simulate an early return for error
    if (1) return;  // File never closed

    fclose(file);
}

int main() 
{
    ReadFile();
    return 0;
}
