
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_add_value_from_pos(binn_t node, const binn_type_t type, const void const *pvalue, const unsigned int size) {
    int _ret=1;
    register gensetdyn *container=0;
    binn_internal_t *p=0;
    binn_t *elem=0;
    unsigned int nc=0, ns=0;
           
    p = binn_get_internal(node);
    if(!p) goto exit;
    
    BINN_PRINT_DEBUG("%s: new position, type (%d)\n", __FUNCTION__, type);
    
    container=&p->data.container;  
        
    if(!gensetdyn_new(&binn_storage_g, &ns)) {
        BINN_PRINT_ERROR("%s: no more space (storage)\n", __FUNCTION__);
        goto exit;
    }   
    BINN_PRINT_DEBUG("%s: new binn created (%d)\n", __FUNCTION__, ns);
    p = binn_get_internal(ns);
    (*p)=binn_internal_zero;
    p->magic = BINN_ITEM_MAGIC;
    p->type=type;
    
    binn_copy_value(pvalue, &p->data, type, size);

    if(!gensetdyn_new(container, &nc)) {
        BINN_PRINT_ERROR("%s: no more space (container)\n", __FUNCTION__);
        goto exit;
    }   
    BINN_PRINT_DEBUG("%s: new container element created (%d)\n", __FUNCTION__, nc);
    elem=GENSETDYN_P(binn_t, container, nc);
    (*elem)=ns;

    p->id=nc;
    
    BINN_PRINT_DEBUG("%s: value added in pos (%d)\n", __FUNCTION__, nc);
    _ret=0;
        
exit:
    if(_ret) {
        BINN_PRINT_ERROR("%s: unable add new position\n", __FUNCTION__);
    }
    return _ret;
}