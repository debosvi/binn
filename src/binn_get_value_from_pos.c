
#include "priv/binn.h"

typedef struct {
    unsigned int pos;
    binn_internal_t* p;
} sid_stuff_t;

///////////////////////////////////////////////////////////////////////////////
static int binn_get_value_from_pos_iter_func(char *item, void *stuff) {
    int _ret=1;
    binn_t *elem=(binn_t*)item;
    sid_stuff_t* owned = (sid_stuff_t*)stuff;
    binn_internal_t* p=binn_get_internal(*elem);  
    BINN_PRINT_DEBUG("%s: ids, expected (%d), current(%d)\n", __FUNCTION__, owned->pos, p->id);    
    if(p->id == owned->pos) { 
        BINN_PRINT_DEBUG("%s: match ids (%d)\n", __FUNCTION__, p->id);   
        owned->p=p;
        _ret=0;
    }    
    return _ret;
}

///////////////////////////////////////////////////////////////////////////////
int binn_get_value_from_pos(binn_t node, const unsigned int pos, const binn_type_t type, void **pvalue, unsigned int *psize) {
    int _ret=1;
    binn_internal_t* p=0;
    sid_stuff_t stuff = { .p=0, .pos=pos };
    
    (void)psize;
           
    p = binn_get_internal(node);
    if(!p) goto exit;
    
    BINN_PRINT_DEBUG("%s: pos(%d)\n", __FUNCTION__, pos);
    
    gensetdyn_iter(&p->data.container, binn_get_value_from_pos_iter_func, &stuff);
        
    if(stuff.p) {
        if(stuff.p->type==type) {        
            binn_get_value(&stuff.p->data, pvalue, type);            
            _ret=0;
        }
        else {
            BINN_PRINT_ERROR("%s: bad type, expected(%d), current(%d)\n", __FUNCTION__, type, stuff.p->type);
        }
    }
        
exit:
    if(_ret) {
        BINN_PRINT_ERROR("%s: unable to find pos(%d)\n", __FUNCTION__, pos);
    }
    return _ret;
}