
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_add_value_from_id(binn_t node, const unsigned int id, const binn_type_t type, const void const *pvalue, const unsigned int size) {
    int _ret=1;
    register gensetdyn *container=0;
    binn_internal_t *p=0;
    binn_t *elem=0;
    // unsigned int nelems=0;
    unsigned int nc=0, ns=0;
    
    (void)size;
           
    p = binn_get_internal(node);
    if(!p) goto exit;
    
    fprintf(stderr, "%s: id(%d)\n", __FUNCTION__, id);
    
    container=&p->data.container;  
    // nelems=gensetdyn_n(container);    
    // fprintf(stderr, "%s: nb elems(%d)\n", __FUNCTION__, nelems);
        
    if(!gensetdyn_new(&binn_storage_g, &ns)) {
        fprintf(stderr, "%s: no more space (storage)\n", __FUNCTION__);
        goto exit;
    }   
    fprintf(stderr, "%s: new binn created (%d)\n", __FUNCTION__, ns);
    p = binn_get_internal(ns);
    (*p)=binn_internal_zero;
    p->magic = BINN_ITEM_MAGIC;
    p->type=type;
    p->id=id;
    
    switch(type) {
        case BINN_TYPE_UINT8: p->data.vuint8 = *(uint8_t*)pvalue; break;
        case BINN_TYPE_INT8: p->data.vint8 = *(int8_t*)pvalue; break;
        case BINN_TYPE_UINT16: p->data.vuint16 = *(uint16_t*)pvalue; break;
        case BINN_TYPE_INT16: p->data.vint16 = *(int16_t*)pvalue; break;
        case BINN_TYPE_UINT32: p->data.vuint32 = *(uint32_t*)pvalue; break;
        case BINN_TYPE_INT32: p->data.vint32 = *(int32_t*)pvalue; break;
        case BINN_TYPE_UINT64: p->data.vuint64 = *(uint64_t*)pvalue; break;
        case BINN_TYPE_INT64: p->data.vint64 = *(int64_t*)pvalue; break;
        
        default:
            fprintf(stderr, "%s: type not managed (%d)\n", __FUNCTION__, type);
    }

    if(!gensetdyn_new(container, &nc)) {
        fprintf(stderr, "%s: no more space (container)\n", __FUNCTION__);
        goto exit;
    }   
    fprintf(stderr, "%s: new container element created (%d)\n", __FUNCTION__, nc);
    elem=GENSETDYN_P(binn_t, container, nc);
    (*elem)=ns;
    
    fprintf(stderr, "%s: id added (%d)\n", __FUNCTION__, id);
    _ret=0;
        
exit:
    if(_ret) {
        fprintf(stderr, "%s: unable to find id(%d)\n", __FUNCTION__, id);
    }
    return _ret;
}