
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
void binn_free(binn_t item) {
    binn_internal_t* _p=0;
    
    if(item==BINN_INVALID) goto exit;
    
    _p = GENSETDYN_P(binn_internal_t, &binn_storage_g, item);
    if(!_p) goto exit;
    
    // internal frees
    // TODO
    
    // last reset
    (*_p)= binn_internal_zero;
    if(gensetdyn_delete (&binn_storage_g, item)) goto exit;
    

exit:
    return ;
}