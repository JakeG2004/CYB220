#include "request.h"
#include <unistd.h>
#include <stdint.h>
int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    return parse_request((char *)data);
}