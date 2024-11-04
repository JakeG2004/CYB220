

#include "stdlib.h"

unsigned long str_token( char *str) {
	
	unsigned long tmp_token;
	int i;

	if (str==0)
		return 0;

	// seed the token algorithm
	tmp_token = 5381;

	while (*str) { 

		tmp_token = ((tmp_token << 5)+ tmp_token) + *str;

		++str;

	}

	return tmp_token;
}
