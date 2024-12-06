

/*@ignore@*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>



/*@end@*/
int main(int argc, char**argv){

   //--------Uninitialized variable
   int s, o, p;

   p = 5;

   p = s;  //  s is unintialized here

//   cout << "P: " << p << endl;
    printf("P: %d\n", p);

   //--------Buffer Overflow, and unsafe use of strcpy()
   

   char* test = "Hello";
   char buffer[5];
   strcpy(buffer, test);  // buffer is too small for test, overflow with unsafe use of strcpy
                   
//   cout << "buffer: " << buffer << endl;
   
    printf("buffer: %s\n", buffer);

   
   //--------Integer overflow
   
   int a = INT_MAX;
   a++;
//   cout << "INT_MAX: " << a << endl; 
//   cout << "INT_MAX+1: " << a+1 << endl;  // THis should overflow

    printf("INT_MAX: %d\n", a);
    printf("INT_MAX+1: %d\n", a+1);

   //--------Off by one
   
   int array[5] = {1,2,3,4,5};
   int i;
   for( i=0; i <=5; i++){
      printf("array[%d]: %d\n", i, array[i]);
   } 

   //-----------Type Mismatch
   
   int z = INT_MAX;
   short y;
   y = z;

  // cout << "y: " << y << endl;

    printf("y: %d\n", y);

   //-----------Use After Free
   
   int k = 0;
   int* j = (int*) malloc(sizeof(int));

      *j = 10;
 //  cout << "j: " << *j << endl;
   
   k = *j;
 //  cout << "k: " << k << endl;
   free(j);
   
   k = *j;
   
 //  cout << "after freeing j ....  k: " << k << endl;


   //-----------Double Freee
   
   free(j);


   //-----------Format string vulnerability

   printf(argv[1]);

}

 
