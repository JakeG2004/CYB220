#include "request.h"
int main()
{
    char buffer[256];

    // Read input from stdin, simulating a piped file
    size_t bytesRead = fread(buffer, 1, sizeof(buffer), stdin);
    // Call parse_request with the input
    printf("Processing input from file...\n");
    parse_request(buffer);

    return 0;
}