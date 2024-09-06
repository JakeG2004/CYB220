/* vul_prog.c */

#include<stdio.h>
#include<stdlib.h>

#define SECRET1 0x44
#define SECRET2 0x55



int main(int argc, char *argv[])
{
    char user_input[100];
    
    //int *secret;
    int secret[2];
    int int_input1 = 0;
    int int_input2 = 0;
    int a = 1;
    int b = 2; /* other variables, not used here.*/
    
    /* The secret value is stored on the heap */
    //secret = (int *) malloc(2*sizeof(int));
    
    /* getting the secret */
    secret[0] = SECRET1; secret[1] = SECRET2;
    
    printf("The variable secret's address is 0x%8x (on stack)\n", (unsigned int)&secret);
    printf("The variable secret's value is 0x%8x (on stack)\n", (unsigned int)secret);
    printf("The variable int_input1's address is 0x%8x (on stack)\n", (unsigned int)&int_input1);
    printf("The variable int_input2's address is 0x%8x (on stack)\n", (unsigned int)&int_input2);
    printf("secret[0]'s address is 0x%8x (on stack)\n", (unsigned int)&secret[0]);
    printf("secret[1]'s address is 0x%8x (on stack)\n", (unsigned int)&secret[1]);
    
    printf("Please enter a decimal integer\n");
    scanf("%d", &int_input1);  /* getting an input from user */
    printf("Please enter a decimal integer for integer2\n");
    scanf("%d", &int_input2);  /* getting an input2 from user */
    printf("Please enter a string\n");
    scanf("%s", user_input); /* getting a string from user */
    
    /* Vulnerable place */
    printf(user_input);
    printf("\n");

    return 0;
}
