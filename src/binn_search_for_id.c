
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
binn_t binn_search_for_id(binn_t node, const unsigned int id) {
    binn_t _ret=BINN_INVALID;
    register gensetdyn *container=0;
    binn_internal_t* p=0;
    binn_t *elem=0;
    unsigned int nelems=0;
            
    p = binn_get_internal(node);
    if(!p) goto exit;
    
    fprintf(stderr, "%s: id (%d)\n", __FUNCTION__, id);
    
    container=&p->data.container;    
    
    nelems=gensetdyn_n(container);
    fprintf(stderr, "%s: nb elems (%d)\n", __FUNCTION__, nelems);
    
    if(!nelems) goto exit;
    
    for(int i=0; i<(int)nelems; i++) {       
        elem=GENSETDYN_P(binn_t, container, i);
        p = binn_get_internal(*elem);        
    
        if(p->id == id) { 
            _ret=(*elem);
            break;
        }
    }
    
exit:
    if(_ret==BINN_INVALID) {
        fprintf(stderr, "%s: unable to find id(%d)\n", __FUNCTION__, id);
    }
    return _ret;
}