#include <iostream>
using namespace std;

int main()
{
  char ptr[20];
  fgets(ptr, sizeof(ptr), stdin);
  if(ptr[0] == 'C'){
    if(ptr[1] == 'Y') {
      if(ptr[2] == 'B'){
	if(ptr[3] == '2') {
	  if(ptr[4] == '2'){
	    if(ptr[5] == '0') {
	      abort();
	    }
	  }
	}
      }
    }
  }
      

}
