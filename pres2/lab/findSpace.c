#include <stdio.h>

void FindChar(char* myStr, int len, char** a);

int main()
{
    char* myStr = "Hello, World";

    char* a = NULL;
    FindChar(myStr, sizeof(myStr), &a);

    printf("Character: %c\n", *a);
}

void FindChar(char* myStr, int len, char** a)
{
    for(int i = 0; i < len; i++)
    {
        if(myStr[i] < 0 && myStr[i] >= 0)
        {
            *a = &(myStr[i]);
        }
    }
}