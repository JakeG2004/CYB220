
#ifndef __MALLOC_H__
#define __MALLOC_H__

// In our case the lower 2-bits of the alloc_size are flags
// we enforce minimum allocation sizes of 4-bytes which frees
// up these lower 2-bits as flags
#define MALLOC_INUSE_FLAG_BIT       (1)
#define MALLOC_NEXT_FLAG_BIT        (2)
#define MALLOC_BUCKET_COUNT         (16)

typedef struct MALLOC_ALLOC_HDR
{
    size_t  alloc_size;
} tMallocAllocHdr;

// Only free blocks have these headers (minimum allocation size is therefore 8-bytes)
typedef struct MALLOC_ALLOC_FTR
{
    struct MALLOC_ALLOC_HDR *pNext;
    struct MALLOC_ALLOC_HDR *pPrev;
} tMallocAllocFtr;

typedef struct MALLOC_MANAGER
{
    void *pFreeList;
} tMallocManager;

void* calloc( size_t count, size_t obj_size );
void* malloc( size_t alloc_size );
void free( void *pMem );

#endif // __MALLOC_H__
