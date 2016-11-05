
#ifndef PRIVATE_BINN_H
#define PRIVATE_BINN_H

#include <math.h>
#include <netinet/in.h>

#include <binn.h>

#define FLOAT_COMP(f1,f2) (fabs(f1-f2) < 0.00001)

#ifndef htonll
extern uint64_t htonll(uint64_t x) ;
#endif

#ifndef ntohll
#define ntohll      htonll
#endif

extern BOOL IsValidBinnHeader(const void const *pbuf, int *ptype, int *pcount, int *psize, int *pheadersize);
extern int CalcAllocation(int needed_size, int alloc_size);
extern BOOL copy_int_value(void *psource, void *pdest, int source_type, int dest_type);

#endif // PRIVATE_BINN_H
