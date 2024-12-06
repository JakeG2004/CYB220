#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

void double_free_function(const uint8_t *data, size_t size) 
{
    if (size < sizeof(int)) return;

        int *ptr = (int *)malloc(sizeof(int));
    if (!ptr) return;
        *ptr = *(int *)data;

    // Simulate some operations
    if (*ptr == 42) {
        free(ptr);
    }

    // Potential double free
    free(ptr);
}

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) 
{
    double_free_function(data, size);
    return 0;
}
