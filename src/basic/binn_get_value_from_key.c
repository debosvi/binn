
#include "priv/binn.h"

typedef struct {
    char *key;
    binn_type_t type;
    void **pvalue;
    unsigned int *psize;
    binn_internal_t* p;
} sid_stuff_t;

///////////////////////////////////////////////////////////////////////////////
static int binn_get_value_from_key_iter_func(char *item, void *stuff) {
    int _ret=1;
    binn_t *elem=(binn_t*)item;
    sid_stuff_t* owned = (sid_stuff_t*)stuff;
    char *k=owned->key;
    char *next=0;
    binn_internal_t* p=0;
    
    next=strchr(k, '.');
    if(next) (*next)=0;

    p=binn_get_internal(*elem);     
    if(!strcmp(p->key, owned->key)) { 
        if(next) return binn_get_value_from_key(*elem, next+1, owned->type, owned->pvalue, owned->psize);          
        owned->p=p;
        _ret=0;
    }    
    return _ret;
}

///////////////////////////////////////////////////////////////////////////////
int binn_get_value_from_key(binn_t node, const char const *key, const binn_type_t type, void **pvalue, unsigned int *psize) {
    int _ret=1;
    binn_internal_t* p=0;
    sid_stuff_t stuff = { .p=0, .key=(char*)key, .type=type, .pvalue=pvalue, .psize=psize };
           
    p = binn_get_internal(node);
    if(!p) goto exit;
    
    BINN_PRINT_DEBUG("%s: key(%s)\n", __FUNCTION__, key);
    
    if(!key) goto exit;    
    
    gensetdyn_iter(&p->data.container, binn_get_value_from_key_iter_func, &stuff);
        
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
        BINN_PRINT_ERROR("%s: unable to find key(%s)\n", __FUNCTION__, key);
    }
    return _ret;
}