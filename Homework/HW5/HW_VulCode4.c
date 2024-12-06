#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void get_date(float d);

int main() {
    	printf("The following program performs several activities related to the singer Sinatra.\n");

    	//Uninitialized variable, called "age"
    	int age;  
    	printf("Frank Sinatra's age is: %d\n", age);

    	//Buffer overflow, in first_name if input is longer than 5
    	char first_name[5];
    	char input[] = "Frankie";
    	char full_name[] = "Sinatra"; //Full name will be "Frank Sinatra"
    	strcpy(first_name, "Frankie");

    	printf("Mr. Sinatra's first name is: %s\n", first_name);  

    	//strcat() does not check the final length of the string and overflows full_name's bounds

    	strcat(input, full_name); //input makes the concatenated string too long    	 

    	//type mistmatch, from int to float in get_date
    	int year_born = 1915;
    	get_date(year_born);

    	//format string vulnerability
    	char last_concert[10] = "04/16/1994";
    	printf("Sinatra's last concert was on %ld\n", last_concert);

    	//integer overflow, going beyond MAX_INT of 2147483647
    	int tickets_sold = 2147483646;
    	tickets_sold = tickets_sold + 100;
    	printf("Over Sinatra's career, he's sold a lot of tickets...and he just sold 100 more. Total sold = %d\n", tickets_sold);

    	//off-by-one
    	printf("Sinatra's three top songs are: \n");
    	char *songs[] = {"Strangers in the Night", "Somethin' Stupid", "Three Coins in the Fountain"};
    	int i = 0;
    	for (i = 0; i < 4; i++) { //should be 3, not 4  
            	printf("%d. %s\n", i, songs[i]);
    	}

    	//double free, on array that is not meaningful to program
    	int *arr2 = (int *)malloc(sizeof(int));
            *arr2 = 0; 
    	free(arr2);
    	free(arr2);

    	//another vulnerability: null pointer dereference
    	int *ptr = NULL;
    	int val = 10;
    	*ptr = val;
    	printf("Frank Sinatra has %d awards.\n", *ptr);  

    	//user-after-free, on array used for count-down  
    	int *arr = (int *)malloc(4 * sizeof(int));
    	int j = 0;
    	for (j = 1; j <=3; j++) {
            	arr[j] = j;
    	}
    	free(arr);
    	printf("All done, program will exit in...\n");
    	for (j = 3; j >= 1; j--) {
            	sleep(1);
            	printf("%d\n", arr[j]);
    	}

    	return 0;
}

void get_date(float d) {
    	printf("He was born in %f \n", d);
}
