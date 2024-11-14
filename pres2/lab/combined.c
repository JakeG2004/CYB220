/*
YOU WILL RECEIVE AN INFORMATION WARNING REGARDING CPPCHECK NOT BEING ABLE TO FIND ALL THE INCLUDED FILES. THIS IS NOT AN ERROR THAT NEEDS TO BE ADDRESSED.

Use cppcheck to identify all of the issues in this file. There are 15 issues in total, some are linked and some are not. Identify each of them and leave a comment in
the corresponding problem area.

cppcheck's default arguments will NOT catch every issue. You must enable other error messages to catch them all.
*/
#include <stdio.h>
#include <stdlib.h>

void f1()
{
    int x;
    if (x == 5)
    {
        printf("[Example 1] x is 5.\n");
    }
}

void f2(int* ptr)
{
    if (ptr == NULL)
    {
        printf("[Example 2] Pointer is NULL.\n");
    }
    printf("[Example 2] Value: %d\n", *ptr);
}

void f3()
{
    char* tmp = "Testing!\n";

    for(int i = 0; i < 5; i++)
    {
        if(tmp[i] == 'g')
        {
            printf("found!\n");
        }
    }

    printf("no found :(\n");
}

void f4(int flag)
{
    int* ptr = (int*)malloc(sizeof(int));
    *ptr = 42;

    if (flag == 1)
    {
        return;
    }
    free(ptr);
}

void f5()
{
    int numbers[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i <= 5; i++)
    {
        printf("[Example 4] %d\n", numbers[i]);
    }
}


void f6()
{
    FILE* file = fopen("example.txt", "r");
    fprintf(file, "[Example 5] Writing to file.\n");
    fclose(file);
}

void f7(int x)
{
    if(x < 10)
    {
        printf("x < 10\n");
    }

    else if(x == 10)
    {
        pritnf("x == 1-\n");
    }

    else
    {
        printf("x > 10\n");
    }
}

void f8(int x)
{
    if (x >= 0 || x < 0)
    {
        printf("[Example 6] This will always print.\n");
    }
}

void f9(int x)
{
    x++;
    printf("X: %i\n", x);
}

void f10()
{
    printf("Hello, world!\n");
    int* p = (int*)malloc(sizeof(int) * 10);
    free(p);
}

int main()
{
    f1();

    int* ptr = NULL;
    f2(ptr);

    f3();

    f4(1);

    f5();

    f6();

    f7(3);

    f8(5);

    f9(10);

    f1O();
}
