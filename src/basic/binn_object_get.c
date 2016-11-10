
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_object_get(binn_t obj, const char const *key, const binn_type_t type, void *pvalue, unsigned int *psize) {
    int _ret=1;
    binn_internal_t* p=0;
    binn_type_t ltype=BINN_TYPE_INIT;
    unsigned int count=0;
        
    BINN_PRINT_DEBUG("%s: binn, type(%d)\n", __FUNCTION__, type);
    
    p = binn_get_internal(obj);
    if(!p) goto exit;
    
    if(!key) goto exit;
    
    if(binn_is_valid(p, &ltype, &count)) goto exit;
    BINN_PRINT_DEBUG("%s: bin is valid, type(%d), count(%d)\n", __FUNCTION__, ltype, count);
    
    if(ltype!=BINN_TYPE_OBJECT) {
        BINN_PRINT_ERROR("%s: bad type, expected(%d), found(%d)!\n", __FUNCTION__, BINN_TYPE_OBJECT, ltype);
        goto exit;
    }

    if(binn_search_for_key(obj, key)==BINN_INVALID) {
        BINN_PRINT_ERROR("%s: key not found!\n", __FUNCTION__);
        goto exit;
    }
    
    if(binn_get_value_from_key(obj, key, type, pvalue, psize)) {
        BINN_PRINT_ERROR("%s: unable to get value!\n", __FUNCTION__);
        goto exit;
    }
    
    _ret=0;    
    
exit:
    if(_ret) {
        BINN_PRINT_ERROR("%s: unable to get object, binn(%d), key(%s)!\n", __FUNCTION__, obj, key);
    }
    return _ret;    
}