
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_map_get(binn_t obj, const unsigned int id, const binn_type_t type, void *pvalue, unsigned int *psize) {
    int _ret=1;
    binn_internal_t* p=0;
    binn_type_t ltype=BINN_TYPE_INIT;
    unsigned int count=0;
    
    p = binn_get_internal(obj);
    if(!p) goto exit;
    
    if(binn_is_valid(p, &ltype, &count)) goto exit;
    fprintf(stderr, "%s: bin is valid, type(%d), count(%d)\n", __FUNCTION__, ltype, count);
    
    if(ltype!=BINN_TYPE_MAP) {
        fprintf(stderr, "%s: bad type, expected(%d), found(%d)!\n", __FUNCTION__, BINN_TYPE_MAP, ltype);
        goto exit;
    }

    if(binn_search_for_id(obj, id)==BINN_INVALID) {
        fprintf(stderr, "%s: id not found!\n", __FUNCTION__);
        goto exit;
    }
    
    if(binn_get_value_from_id(obj, id, type, pvalue, psize)) {
        fprintf(stderr, "%s: unable to add value!\n", __FUNCTION__);
        goto exit;
    }
    
    _ret=0;    
    
exit:
    if(_ret) {
        fprintf(stderr, "%s: unable to set object, binn(%d), id(%d)!\n", __FUNCTION__, obj, id);
    }
    return _ret;    
}