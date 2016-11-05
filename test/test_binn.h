
#ifndef TEST_BINN
#define TEST_BINN

#include "binn.h"

#define BINN_MAGIC            0x1F22B11F

#define MAX_BINN_HEADER       9  // [1:type][4:size][4:count]
#define MIN_BINN_SIZE         3  // [1:type][1:size][1:count]
#define CHUNK_SIZE            256  // 1024

extern void* (*malloc_fn)(int len);
extern void* (*realloc_fn)(void *ptr, int len);
extern void  (*free_fn)(void *ptr);

extern int CalcAllocation(int needed_size, int alloc_size);

uint64 htonll(uint64 input);
#define ntohll htonll

extern void test_binn2();

extern BOOL IsValidBinnHeader(void *pbuf, int *ptype, int *pcount, int *psize, int *pheadersize);

#ifdef _WIN32
 // we will not use these functions from the winsock
 #define htons _none_1
 #define htonl _none_2
 #include <windows.h>
#endif

#ifdef htons
#undef htons
#endif
#ifdef ntohs
#undef ntohs
#endif
#ifdef htonl
#undef htonl
#endif
#ifdef ntohl
#undef ntohl
#endif

unsigned short htons(unsigned short input);
unsigned int htonl(unsigned int input);

#define ntohs htons
#define ntohl htonl

#endif // TEST_BINN

