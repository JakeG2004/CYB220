

#include "stdlib.h"


int parse_command(char *buffer, char separator, char ***args) {
	
	int arg_count;
	char *tmp;
	int i;

	
	if (*buffer != 0) {

		// there is at least 1 because this function was called with a string
		arg_count = 1;
		tmp=buffer;
	}
	else
		return -1;

	// count how many fields are on the command so memory can be allocated for the pointers
	while(*tmp++ != 0) {

		if (*tmp==separator)
			++arg_count;
	} // while

	// allocate one char pointer for each field in the command
	*args=calloc(arg_count, sizeof(char *));

	// failed to allocate the memory
	if (*args==0) {
		return -1;
	}

	// start back from the beginning of the buffer
	tmp=buffer;

	// for each field, store a pointer to the first char
	for (i=0;i< arg_count; ++i) {

		(*args)[i]=tmp;

		while (*tmp!= separator && *tmp != 0)
			++tmp;

		// if we found the separator, overwrite it with a null so our args will be properly terminated
		if (*tmp !=0) {

			*tmp=0;
			++tmp;
		}


	} //for 

	return (arg_count);

}
