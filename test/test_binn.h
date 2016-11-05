
#ifndef TEST_BINN
#define TEST_BINN

#include "priv/binn.h"

#define BINN_MAGIC            0x1F22B11F

#define MAX_BINN_HEADER       9  // [1:type][4:size][4:count]
#define MIN_BINN_SIZE         3  // [1:type][1:size][1:count]
#define CHUNK_SIZE            256  // 1024

extern void* (*malloc_fn)(int len);
extern void* (*realloc_fn)(void *ptr, int len);
extern void  (*free_fn)(void *ptr);


extern void test_binn1(void);
extern void test_binn2(void);

extern int CalcAllocation(int needed_size, int alloc_size);
extern BOOL copy_int_value(void *psource, void *pdest, int source_type, int dest_type);
extern BOOL AlmostEqualFloats(float A, float B, int maxUlps);
extern char * i64toa(int64_t value, char *buf, int radix);
extern void * memdup(void *src, int size);

#endif // TEST_BINN

