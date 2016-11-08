
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_object_get(binn_t obj, const char const *key, const binn_type_t type, void *pvalue, unsigned int *psize) {
    int _ret=1;
    binn_internal_t* p=0;
    binn_type_t ltype=BINN_TYPE_INIT;
    unsigned int count=0;
    
    p = binn_get_internal(obj);
    if(!p) goto exit;
    
    if(!key) goto exit;
    
    if(binn_is_valid(p, &ltype, &count)) goto exit;
    fprintf(stderr, "%s: bin is valid, type(%d), count(%d)\n", __FUNCTION__, ltype, count);
    
    if(ltype!=BINN_TYPE_OBJECT) {
        fprintf(stderr, "%s: bad type, expected(%d), found(%d)!\n", __FUNCTION__, BINN_TYPE_OBJECT, ltype);
        goto exit;
    }

    if(binn_search_for_key(obj, key)==BINN_INVALID) {
        fprintf(stderr, "%s: key not found!\n", __FUNCTION__);
        goto exit;
    }
    
    if(binn_get_value(obj, key, type, pvalue, psize)) {
        fprintf(stderr, "%s: unable to add value!\n", __FUNCTION__);
        goto exit;
    }
    
    _ret=0;    
    
exit:
    if(_ret) {
        fprintf(stderr, "%s: unable to set object, binn(%d), key(%s)!\n", __FUNCTION__, obj, key);
    }
    return _ret;    
}