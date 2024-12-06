#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uninitializedVariable() {
    int num; // uninitialized variable
    printf("Uninitialized variable: %d\n", num);
}

void bufferOverflow() {
    char buffer[5]; // buffer with a size of 5
    strcpy(buffer, "Buffer Overflow Example"); // buffer overflow
}

void integerOverflow() {
    int num1 = 2147483647; // maximum value for int
    int num2 = 1;
    int sum = num1 + num2; // integer overflow
    printf("Integer overflow: %d\n", sum);
}

void offByOne() {
    char buffer[5];
    strcpy(buffer, "Off-by-One Error"); // off-by-one error
}

void typeMismatch() {
    int num = 100;
    short smallNum = num; // type mismatch (int to short)
    printf("Type mismatch: %hd\n", smallNum);
}

void useAfterFree() {
    int* ptr = (int*)malloc(sizeof(int));
    free(ptr);
    *ptr = 10; // use-after-free error
}

void doubleFree() {
    int* ptr = (int*)malloc(sizeof(int));
    free(ptr);
    free(ptr); // double free error
}

void unsafeStringManipulation() {
    char source[] = "Unsafe String";
    char destination[5];
    strcpy(destination, source); // unsafe string manipulation
}

void formatStringVulnerability() {
    char input[10];
    printf("Enter your name: ");
    scanf("%s", input);
    printf(input); // format string vulnerability
}

void anotherVulnerability() {
    char buffer[10];
    gets(buffer); // another vulnerability (use of unsafe function gets())
}

int main() {
    uninitializedVariable();
    bufferOverflow();
    integerOverflow();
    offByOne();
    typeMismatch();
    useAfterFree();
    doubleFree();
    unsafeStringManipulation();
    formatStringVulnerability();
    anotherVulnerability();

    return 0;
}
