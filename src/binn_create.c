
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_create(binn_t item, const binn_type_t type, const void const *ptr, const unsigned int size) {
    int _ret=1;
    binn_internal_t* _p=0;
    
    if(item==BINN_INVALID) goto exit;
    if((type<0) || (type>=BINN_TYPE_COUNT)) goto exit;
    if(ptr && !size) goto exit;
    
    switch (type) {
        case BINN_TYPE_LIST:
        case BINN_TYPE_MAP:
        case BINN_TYPE_OBJECT:
            break;
        default:
            goto exit;
    }

    _p = GENSETDYN_P(binn_internal_t, &binn_storage_g, item);
    if(!_p) goto exit;

    (*_p)= binn_internal_zero;
    
    _p->magic = BINN_ITEM_MAGIC;
    _p->type = type;
    
    switch(type) {
        case BINN_TYPE_LIST:
        case BINN_TYPE_MAP:
        case BINN_TYPE_OBJECT:
            gensetdyn_init(&_p->data.container, sizeof(binn_t), 16, 3, 8);
            break;
        default:
            BINN_PRINT_ERROR("%s: type not managed (%d)\n", __FUNCTION__, type);            
            break;
    }
    
      // if (pointer) {
        // item->pre_allocated = TRUE;
        // item->pbuf = pointer;
        // item->alloc_size = size;
      // } else {
        // item->pre_allocated = FALSE;
        // if (size == 0) size = CHUNK_SIZE;
        // pointer = binn_malloc(size);
        // if (pointer == 0) return INVALID_BINN;
        // item->pbuf = pointer;
        // item->alloc_size = size;
      // }

    _ret=0;

exit:
    if(_ret) {
        BINN_PRINT_ERROR("%s: unable to create element!\n", __FUNCTION__);
    }
    return _ret;
}