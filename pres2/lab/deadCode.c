#include <stdio.h>

int main() 
{
    int flag = 0;
    if (flag > 0) 
    {
        if (flag < 0)  // This inner condition will never be true
        {
            printf("This is dead code.\n");
        }
    }
    return 0;
}
