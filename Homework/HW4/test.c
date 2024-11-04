#include <stdio.h>
#include <stdlib.h>

void* GetPointer()
{
    return NULL;
}

int main()
{
    void* vp = GetPointer();
    printf("%p\n", vp);
}