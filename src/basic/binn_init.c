
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
void binn_init(void) {
    if(!binn_initialized) {
        gensetdyn_init (&binn_storage_g, sizeof(binn_internal_t), 16, 3, 8) ;
        binn_initialized=1;
    }
}