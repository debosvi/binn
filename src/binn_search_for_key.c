
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
binn_t binn_search_for_key(binn_t node, const char const *key) {
    binn_t _ret=BINN_INVALID;
    register gensetdyn *container=0;
    binn_internal_t* p=0;
    binn_t *elem=0;
    unsigned int nelems=0;
    char *k=(char*)key;
    char *next=0;
            
    p = binn_get_internal(node);
    if(!p) goto exit;
    
    fprintf(stderr, "%s: key (%s)\n", __FUNCTION__, key);
    
    if(!k) goto exit;
    container=&p->data.container;    
    
    nelems=gensetdyn_n(container);
    fprintf(stderr, "%s: nb elems (%d)\n", __FUNCTION__, nelems);
    
    if(!nelems) goto exit;
    
    next=strchr(k, '.');
    if(next) (*next)=0;
    
    for(int i=0; i<(int)nelems; i++) {       
        elem=GENSETDYN_P(binn_t, container, i);
        p = binn_get_internal(*elem);        
    
        if(!strcmp(p->key, k)) { 
            if(next) return binn_search_for_key(*elem, next+1);          
            _ret=(*elem);
            break;
        }
    }
    
exit:
    if(_ret==BINN_INVALID) {
        fprintf(stderr, "%s: unable to find key(%s)\n", __FUNCTION__, key);
    }
    return _ret;
}