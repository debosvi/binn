
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_create(binn_t item, const binn_type_t type, const void const *ptr, const unsigned int size) {
    int _ret=1;
    binn_internal_t* _p=0;

	BINN_PRINT_DEBUG("%s: elem(%d)\n", __FUNCTION__, item);
    
    if(item==BINN_INVALID) goto exit;
    if((type<0) || (type>=BINN_TYPE_COUNT)) goto exit;
    if(ptr && !size) goto exit;

    BINN_PRINT_DEBUG("%s: start\n", __FUNCTION__);
	_p = binn_get_internal(item);
    if(!_p) goto exit;

    BINN_PRINT_DEBUG("%s: internal done\n", __FUNCTION__);
    (*_p)= binn_internal_zero;
    
    _p->magic = BINN_ITEM_MAGIC;
    _p->type = type;
    
    switch(type) {
        case BINN_TYPE_LIST:
        case BINN_TYPE_MAP:
        case BINN_TYPE_OBJECT:
            gensetdyn_init(&_p->data.container, sizeof(binn_t), 16, 3, 8);
			_ret=0;
            break;
			
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
        case BINN_TYPE_BOOL: 
        case BINN_TYPE_BLOB: 
        case BINN_TYPE_STRING: 
 			_ret=binn_copy_value(ptr, &_p->data, type, size);
            break;
			
        default:
            BINN_PRINT_ERROR("%s: type not managed (%d)\n", __FUNCTION__, type);            
            break;
    }    

exit:
    if(_ret) {
        BINN_PRINT_ERROR("%s: unable to create element!\n", __FUNCTION__);
    }
    return _ret;
}