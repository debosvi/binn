
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_add_value(binn_t node, const char const *key, const binn_type_t type, const void const *pvalue, const unsigned int size) {
    int _ret=1;
    register gensetdyn *container=0;
    binn_internal_t *p=0;
    binn_t *elem=0;
    char *k=(char*)key;
    char *next=0;
    unsigned int nelems=0;
           
    p = binn_get_internal(node);
    if(!p) goto exit;
    
    fprintf(stderr, "%s: binn_add_value, key(%s)\n", __FUNCTION__, key);
    
    if(!k) goto exit;
    container=&p->data.container;  
    nelems=gensetdyn_n(container);    
    fprintf(stderr, "%s: nb elems(%d)\n", __FUNCTION__, nelems);
    
    next=strchr(k, '.');
    if(next) (*next)=0;    

    fprintf(stderr, "%s: single key(%s)\n", __FUNCTION__, k);
    
    if(next) {
        for(int i=0; i<(int)nelems; i++) {
            elem=GENSETDYN_P(binn_t, container, i);
            p = binn_get_internal(*elem);
            if(!strcmp(p->key, k)) 
                return binn_add_value(*elem, next+1, type, pvalue, size); 
            fprintf(stderr, "%s: should have found key(%s)\n", __FUNCTION__, k);
        }
    }
    else {
        unsigned int nc=0, ns=0;

        fprintf(stderr, "%s: key2(%s)\n", __FUNCTION__, k);
        
        if(!gensetdyn_new(&binn_storage_g, &ns)) {
            fprintf(stderr, "%s: no more space (storage)\n", __FUNCTION__);
            goto exit;
        }   
        fprintf(stderr, "%s: new binn created (%d)\n", __FUNCTION__, ns);
        p = binn_get_internal(ns);
        (*p)=binn_internal_zero;
        p->magic = BINN_ITEM_MAGIC;
        p->type=type;
        p->key=strdup(k);
        
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
        
        fprintf(stderr, "%s: key added (%s)\n", __FUNCTION__, k);
        _ret=0;
    }   
        
exit:
    if(_ret) {
        fprintf(stderr, "%s: unable to find key(%s)\n", __FUNCTION__, key);
    }
    return _ret;
}