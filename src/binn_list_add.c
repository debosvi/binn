
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_list_add(binn_t obj, const binn_type_t type, const void const *pvalue, const unsigned int size) {
    int _ret=1;
    binn_internal_t* p=0;
    binn_type_t ltype=BINN_TYPE_INIT;
    unsigned int count=0;
    
    p = binn_get_internal(obj);
    if(!p) goto exit;
    
    if(binn_is_valid(p, &ltype, &count)) goto exit;
    BINN_PRINT_DEBUG("%s: bin is valid, type(%d), count(%d)\n", __FUNCTION__, ltype, count);
    
    if(ltype!=BINN_TYPE_LIST) {
        BINN_PRINT_ERROR("%s: bad type, expected(%d), found(%d)!\n", __FUNCTION__, BINN_TYPE_OBJECT, ltype);
        goto exit;
    }
        
    if(binn_add_value_from_pos(obj, type, pvalue, size)) {
        BINN_PRINT_ERROR("%s: unable to add value!\n", __FUNCTION__);
        goto exit;
    }
    
    _ret=0;
    
exit:
    if(_ret) {
        BINN_PRINT_ERROR("%s: unable to add element, binn(%d)!\n", __FUNCTION__, obj);
    }
    return _ret;    
}