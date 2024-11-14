#include <stdlib.h>
#include <stdio.h>

void AllocateAndReassign() 
{
    int* ptr = (int*)malloc(10 * sizeof(int));
    if (!ptr) return;

    ptr = (int*)malloc(20 * sizeof(int));  // Original allocation is lost
    free(ptr);
}

int main() 
{
    AllocateAndReassign();
    return 0;
}
