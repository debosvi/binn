
#ifndef PRIVATE_BINN_H
#define PRIVATE_BINN_H

#include <stdio.h>

#include <skalibs/gensetdyn.h>
#include <binn/binn.h>

#define BINN_ITEM_MAGIC     ((int)0xA55A1234)

typedef enum {
    BINN_TYPE_LIST=0,
    BINN_TYPE_MAP,
    BINN_TYPE_OBJECT,

    BINN_TYPE_NULL,
    BINN_TYPE_TRUE,
    BINN_TYPE_FALSE,

    BINN_TYPE_UINT8,
    BINN_TYPE_INT8,
    BINN_TYPE_UINT16,
    BINN_TYPE_INT16,
    BINN_TYPE_UINT32,
    BINN_TYPE_INT32,
    BINN_TYPE_UINT64,
    BINN_TYPE_INT64,

    BINN_TYPE_STRING,
    BINN_TYPE_FLOAT,
    BINN_TYPE_DOUBLE,
    
    BINN_TYPE_BLOB,
    BINN_TYPE_COUNT,
    BINN_TYPE_INIT=255
} binn_type_t;

typedef union {
    void*           pbuf;   // used for list, map, object, blob
    gensetdyn       container;  // storage type is 'binn_t'
    
    // integers
    int8_t      vint8;
    int16_t     vint16;
    int32_t     vint32;
    int64_t     vint64;
    uint8_t     vuint8;
    uint16_t    vuint16;
    uint32_t    vuint32;
    uint64_t    vuint64;

    // decimals
    float       vfloat;
    double      vdouble;
    
    //
    char        vbool;
} binn_data_t;
#define BINN_DATA_ZERO  { 0 }

typedef struct {
    int             magic;
    binn_type_t     type; 
    union {
        char*           key;
        unsigned int    id;
    };        
    binn_data_t     data;
} binn_internal_t;
#define BINN_INTERNAL_ZERO  { .magic=0, .type=BINN_TYPE_INIT, .key=0, .data= BINN_DATA_ZERO }
extern const binn_internal_t binn_internal_zero;

extern int binn_initialized;

extern gensetdyn binn_storage_g;
#define BINN_STORAGE_ZERO   GENSETDYN_ZERO 

extern void binn_init(void);

extern binn_type_t binn_type(binn_t node);
extern int binn_is_valid(binn_internal_t *item, binn_type_t *ptype, unsigned int *pcount);
extern binn_internal_t* binn_get_internal(binn_t node);

extern binn_t binn_search_for_key(binn_t node, const char const *key);
extern binn_t binn_search_for_id(binn_t node, const unsigned int id);
extern binn_t binn_search_for_pos(binn_t node, const unsigned int pos);

extern int binn_add_value_from_key(binn_t node, const char const *key, const binn_type_t type, const void const *pvalue, const unsigned int size);
extern int binn_add_value_from_id(binn_t node, const unsigned int id, const binn_type_t type, const void const *pvalue, const unsigned int size);
extern int binn_add_value_from_pos(binn_t node, const binn_type_t type, const void const *pvalue, const unsigned int size);

extern int binn_get_value_from_key(binn_t node, const char const *key, const binn_type_t type, void **pvalue, unsigned int *psize);
extern int binn_get_value_from_id(binn_t node, const unsigned int id, const binn_type_t type, void **pvalue, unsigned int *psize);
extern int binn_get_value_from_pos(binn_t node, const unsigned int pos, const binn_type_t type, void **pvalue, unsigned int *psize);

extern binn_t binn_new(const binn_type_t type, const void const *ptr, const unsigned int size);
extern int binn_create(binn_t item, const binn_type_t type, const void const *ptr, const unsigned int size);

extern int binn_list_add(binn_t obj, const binn_type_t type, const void *pvalue, const unsigned int size);
extern int binn_list_get(binn_t obj, const unsigned int pos, const binn_type_t type, void *pvalue, unsigned int *psize);
extern int binn_map_get(binn_t obj, const unsigned int id, const binn_type_t type, void *pvalue, unsigned int *psize);
extern int binn_map_set(binn_t obj, const unsigned int id, const binn_type_t type, const void const *pvalue, const unsigned int size);
extern int binn_object_get(binn_t obj, const char const *key, const binn_type_t type, void *pvalue, unsigned int *psize);
extern int binn_object_set(binn_t obj, const char const *key, const binn_type_t type, const void const *pvalue, const unsigned int size);

extern int binn_copy_value(const void const *psource, void *pdest, const binn_type_t type, const unsigned int size);
extern int binn_get_value(const void const *psource, void *pdest, const binn_type_t type);

// debug

#ifdef __DEBUG__
#define BINN_PRINT_DEBUG(...)   fprintf(stderr, __VA_ARGS__)
#else
#define BINN_PRINT_DEBUG(...)
#endif

#define BINN_PRINT_ERROR(...)   fprintf(stderr, __VA_ARGS__)

#endif // PRIVATE_BINN_H
