
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
static int binn_get_int_value(const void const *psource, void *pdest, const binn_type_t type) {
    int _ret=0;

    switch(type) {
        case BINN_TYPE_UINT8: *(uint8_t*)pdest = *(uint8_t*)psource; break;
        case BINN_TYPE_INT8: *(int8_t*)pdest = *(int8_t*)psource; break; 
        case BINN_TYPE_UINT16: *(uint16_t*)pdest = *(uint16_t*)psource; break; 
        case BINN_TYPE_INT16: *(int16_t*)pdest = *(int16_t*)psource; break; 
        case BINN_TYPE_UINT32: *(uint32_t*)pdest = *(uint32_t*)psource; break; 
        case BINN_TYPE_INT32: *(int32_t*)pdest = *(int32_t*)psource; break; 
        case BINN_TYPE_UINT64: *(uint64_t*)pdest = *(uint64_t*)psource; break; 
        case BINN_TYPE_INT64: *(int64_t*)pdest = *(int64_t*)psource; break; 
       
        default:
            fprintf(stderr, "%s: type not allowed (%d)\n", __FUNCTION__, type);
    }    

    return _ret;  
}

///////////////////////////////////////////////////////////////////////////////
static int binn_get_float_value(const void const *psource, void *pdest, const binn_type_t type) {
    int _ret=0;

    switch(type) {
        case BINN_TYPE_FLOAT: *(float*)pdest = *(float*)psource; break;
        case BINN_TYPE_DOUBLE: *(double*)pdest = *(double*)psource; break; 
               
        default:
            fprintf(stderr, "%s: type not allowed (%d)\n", __FUNCTION__, type);
    }    

    return _ret;  
}

///////////////////////////////////////////////////////////////////////////////
static int binn_get_raw_value(const void const *psource, void *pdest, const binn_type_t type) {
    int _ret=0;

    switch(type) {
        case BINN_TYPE_BLOB: *(float*)pdest = *(float*)psource; break;
        case BINN_TYPE_STRING: *(double*)pdest = *(double*)psource; break; 
               
        default:
            fprintf(stderr, "%s: type not allowed (%d)\n", __FUNCTION__, type);
    }    

    return _ret;  
}

///////////////////////////////////////////////////////////////////////////////
int binn_get_value(const void const *psource, void *pdest, const binn_type_t type) {
    int _ret=0;

    switch(type) {
        case BINN_TYPE_UINT8: 
        case BINN_TYPE_INT8: 
        case BINN_TYPE_UINT16: 
        case BINN_TYPE_INT16: 
        case BINN_TYPE_UINT32: 
        case BINN_TYPE_INT32: 
        case BINN_TYPE_UINT64: 
        case BINN_TYPE_INT64: 
            _ret=binn_get_int_value(psource, pdest, type);
            break;
        
        case BINN_TYPE_FLOAT: 
        case BINN_TYPE_DOUBLE: 
            _ret=binn_get_float_value(psource, pdest, type);
            break;

        case BINN_TYPE_BLOB: 
        case BINN_TYPE_STRING: 
            _ret=binn_get_raw_value(psource, pdest, type);
            break;

        
        default:
            fprintf(stderr, "%s: type not managed (%d)\n", __FUNCTION__, type);
    }    

    return _ret;
}