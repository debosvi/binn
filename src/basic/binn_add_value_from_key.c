
#include "priv/binn.h"

///////////////////////////////////////////////////////////////////////////////
int binn_add_value_from_key(binn_t node, const char const *key, const binn_type_t type, const void const *pvalue, const unsigned int size) {
    int _ret=1;
    register gensetdyn *container=0;
    binn_internal_t *p=0;
    binn_t *elem=0;
    char *k=(char*)key;
    char *next=0;
    unsigned int nelems=0;
           
    p = binn_get_internal(node);
    if(!p) goto exit;
    
    BINN_PRINT_DEBUG("%s: long key(%s), type(%d)\n", __FUNCTION__, key, type);
    
    if(!k) goto exit;
    container=&p->data.container;  
    nelems=gensetdyn_n(container);    
    BINN_PRINT_DEBUG("%s: nb elems(%d)\n", __FUNCTION__, nelems);
    
    next=strchr(k, '.');
    if(next) (*next)=0;    

    BINN_PRINT_DEBUG("%s: single key(%s)\n", __FUNCTION__, k);
    
    if(next) {
        for(int i=0; i<(int)nelems; i++) {
            elem=GENSETDYN_P(binn_t, container, i);
            p = binn_get_internal(*elem);
            if(!strcmp(p->key, k)) 
                return binn_add_value_from_key(*elem, next+1, type, pvalue, size); 
            BINN_PRINT_ERROR("%s: should have found key(%s)\n", __FUNCTION__, k);
        }
    }
    else {
        unsigned int nc=0, ns=0;
        
        if( (type!=BINN_TYPE_LIST) &&
            (type!=BINN_TYPE_MAP) &&
            (type!=BINN_TYPE_OBJECT) 
            ) {

            if(!gensetdyn_new(&binn_storage_g, &ns)) {
                BINN_PRINT_ERROR("%s: no more space (storage)\n", __FUNCTION__);
                goto exit;
            }   
            BINN_PRINT_DEBUG("%s: new binn created (%d)\n", __FUNCTION__, ns);
            p = binn_get_internal(ns);
            (*p)=binn_internal_zero;
            p->magic = BINN_ITEM_MAGIC;
            p->type=type;
            p->key=strdup(k);

            binn_copy_value(pvalue, &p->data, type, size);
        }
        else {
            p = binn_get_internal(*(binn_t*)pvalue);
            p->key = strdup(k);
        }

        if(!gensetdyn_new(container, &nc)) {
            BINN_PRINT_ERROR("%s: no more space (container)\n", __FUNCTION__);
            goto exit;
        }   
        BINN_PRINT_DEBUG("%s: new container element created (%d)\n", __FUNCTION__, nc);
        elem=GENSETDYN_P(binn_t, container, nc);
        
        if( (type!=BINN_TYPE_LIST) &&
            (type!=BINN_TYPE_MAP) &&
            (type!=BINN_TYPE_OBJECT) 
            ) {
            (*elem)=ns;
        }
        else {
            (*elem)=*(binn_t*)pvalue;
        }            
        
        BINN_PRINT_DEBUG("%s: key added (%s)\n", __FUNCTION__, k);
        _ret=0;
    }   
        
exit:
    if(_ret) {
        BINN_PRINT_ERROR("%s: unable to find key(%s)\n", __FUNCTION__, key);
    }
    return _ret;
}