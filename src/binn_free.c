
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
static void binn_free_internal_storage(binn_t item) {
    register gensetdyn *container=0;
    binn_internal_t* p=0;
    binn_t *elem=0;
    unsigned int nelems=0;
    
    p = binn_get_internal(item);
    container=&p->data.container;    
    nelems=gensetdyn_n(container);
    fprintf(stderr, "%s: nb elems (%d)\n", __FUNCTION__, nelems);
    
    for(int i=0; i<(int)nelems; i++) {
        elem=GENSETDYN_P(binn_t, container, i);
        binn_free(*elem);
    }  
}

///////////////////////////////////////////////////////////////////////////////
void binn_free(binn_t item) {
    binn_internal_t* _p=0;
    
    if(item==BINN_INVALID) goto exit;
    
    fprintf(stderr, "%s: binn (%d)\n", __FUNCTION__, item);            
    
    _p = GENSETDYN_P(binn_internal_t, &binn_storage_g, item);
    if(!_p) goto exit;
    
    // internal frees
    switch(_p->type) {
        case BINN_TYPE_LIST:
        case BINN_TYPE_MAP:
        case BINN_TYPE_OBJECT:
            binn_free_internal_storage(item);   
            break;
            
        case BINN_TYPE_NULL:
        case BINN_TYPE_TRUE:
        case BINN_TYPE_FALSE:
        case BINN_TYPE_UINT8:
        case BINN_TYPE_INT8:
        case BINN_TYPE_UINT16:
        case BINN_TYPE_INT16:
        case BINN_TYPE_UINT32:
        case BINN_TYPE_INT32:
        case BINN_TYPE_UINT64:
        case BINN_TYPE_INT64:
        case BINN_TYPE_FLOAT:
        case BINN_TYPE_DOUBLE:
            break;
            
        case BINN_TYPE_STRING:
        case BINN_TYPE_BLOB:
            fprintf(stderr, "%s: type not managed (%d)\n", __FUNCTION__, _p->type);            
            break;
            
        default:
            fprintf(stderr, "%s: should not happen, type (%d)\n", __FUNCTION__, _p->type);            
    }
    
    // last reset
    (*_p)= binn_internal_zero;
    if(gensetdyn_delete (&binn_storage_g, item)) goto exit;
    

exit:
    return ;
}