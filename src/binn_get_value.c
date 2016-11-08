
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_get_value(binn_t node, const char const *key, const binn_type_t type, void **pvalue, unsigned int *psize) {
    int _ret=1;
    register gensetdyn *container=0;
    binn_internal_t *p=0;
    binn_t *elem=0;
    char *k=(char*)key;
    char *next=0;
    unsigned int nelems=0;
           
    p = binn_get_internal(node);
    if(!p) goto exit;
    
    fprintf(stderr, "%s: key(%s)\n", __FUNCTION__, key);
    
    if(!k) goto exit;
    container=&p->data.container;  
    nelems=gensetdyn_n(container);    
    fprintf(stderr, "%s: nb elems(%d)\n", __FUNCTION__, nelems);
    
    next=strchr(k, '.');
    if(next) (*next)=0;    

    fprintf(stderr, "%s: single key(%s)\n", __FUNCTION__, k);
    
    for(int i=0; i<(int)nelems; i++) {
        elem=GENSETDYN_P(binn_t, container, i);
        fprintf(stderr, "%s: binn (%d)\n", __FUNCTION__, *elem);
        p = binn_get_internal(*elem);
        fprintf(stderr, "%s: key (%s)\n", __FUNCTION__, p->key);
        if(!strcmp(p->key, k)) {
            if(next) return binn_get_value(*elem, next+1, type, pvalue, psize); 
    
            // local container
            fprintf(stderr, "%s: look at type (%d)\n", __FUNCTION__, type);
            switch(type) {
                case BINN_TYPE_UINT8: (*(uint8_t*)pvalue) = p->data.vuint8; break;
                case BINN_TYPE_INT8: (*(int8_t*)pvalue) = p->data.vint8; break;
                case BINN_TYPE_UINT16: (*(uint16_t*)pvalue) = p->data.vuint16; break;
                case BINN_TYPE_INT16: (*(int16_t*)pvalue) = p->data.vint16; break;
                case BINN_TYPE_UINT32: (*(uint32_t*)pvalue) = p->data.vuint32; break;
                case BINN_TYPE_INT32: (*(int32_t*)pvalue) = p->data.vint32; break;
                case BINN_TYPE_UINT64: (*(uint64_t*)pvalue) = p->data.vuint64; break;
                case BINN_TYPE_INT64: (*(int64_t*)pvalue) = p->data.vint64; break;
                
                default:
                    fprintf(stderr, "%s: type not managed (%d)\n", __FUNCTION__, type);
            }
            
            _ret=0;
        }
    }

        
exit:
    if(_ret) {
        fprintf(stderr, "%s: unable to find key(%s)\n", __FUNCTION__, key);
    }
    return _ret;
}