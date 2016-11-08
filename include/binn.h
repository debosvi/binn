
// TO ENABLE INLINE FUNCTIONS:
//   ON MSVC: enable the 'Inline Function Expansion' (/Ob2) compiler option, and maybe the
//            'Whole Program Optimitazion' (/GL), that requires the
//            'Link Time Code Generation' (/LTCG) linker option to be enabled too

#ifndef __BINN_H__
#define __BINN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

typedef int binn_t;
#define BINN_INVALID    ((binn_t)-1)

// --- GENERAL FUNCTIONS  ----------------------------------------------------------
extern binn_t binn_list(void);
extern binn_t binn_map(void);
extern binn_t binn_object(void);

extern void binn_free(binn_t item);

// --- ALLOCATION FUNCTIONS  ----------------------------------------------------------
typedef void* (*binn_malloc_f)(size_t);
typedef void* (*binn_realloc_f)(void*,size_t);
typedef void (*binn_free_f)(void*);

extern void binn_set_alloc_functions(binn_malloc_f bm, binn_realloc_f br, binn_free_f bf);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// WRITE ACCESSES //////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// set into list
extern int binn_list_add_list(binn_t list, const binn_t list2);
extern int binn_list_add_map(binn_t list, const binn_t map);
extern int binn_list_add_object(binn_t list, const binn_t obj);
extern int binn_list_INIT_TEST_COMPLEX8(binn_t list, const int8_t value);
extern int binn_list_INIT_TEST_COMPLEX16(binn_t list, const int16_t value);
extern int binn_list_INIT_TEST_COMPLEX32(binn_t list, const int32_t value);
extern int binn_list_INIT_TEST_COMPLEX64(binn_t list, const int64_t value);
extern int binn_list_add_uint8(binn_t list, const uint8_t value);
extern int binn_list_add_uint16(binn_t list, const uint16_t value);
extern int binn_list_add_uint32(binn_t list, const uint32_t value);
extern int binn_list_add_uint64(binn_t list, const uint64_t value);
extern int binn_list_add_float(binn_t list, const float value);
extern int binn_list_add_double(binn_t list, const double value);
extern int binn_list_add_bool(binn_t list, const char value);
extern int binn_list_add_null(binn_t list);
extern int binn_list_add_blob(binn_t list, const void const *ptr, const size_t size);
extern int binn_list_add_string(binn_t list, const char const *str);

// set into map
extern int binn_map_set_list(binn_t map, const int id, const binn_t list);
extern int binn_map_set_map(binn_t map, const int id, const binn_t map2);
extern int binn_map_set_object(binn_t map, const int id, const binn_t obj);
extern int binn_map_set_int8(binn_t map, const int id, const int8_t value);
extern int binn_map_set_int16(binn_t map, const int id,const int16_t value);
extern int binn_map_set_int32(binn_t map, const int id,const int32_t value);
extern int binn_map_set_int64(binn_t map, const int id,const int64_t value);
extern int binn_map_set_uint8(binn_t map, const int id,const uint8_t value);
extern int binn_map_set_uint16(binn_t map, const int id,const uint16_t value);
extern int binn_map_set_uint32(binn_t map, const int id,const uint32_t value);
extern int binn_map_set_uint64(binn_t map, const int id,const uint64_t value);
extern int binn_map_set_float(binn_t map, const int id,const float value);
extern int binn_map_set_double(binn_t map, const int id,const double value);
extern int binn_map_set_bool(binn_t map, const int id,const char value);
extern int binn_map_set_null(binn_t map, const int id);
extern int binn_map_set_blob(binn_t map, const int id,const void const *ptr, const size_t size);
extern int binn_map_set_string(binn_t map, const int id,const char const *str);

// set into object
extern int binn_object_set_list(binn_t object, const char const *key, const binn_t list2);
extern int binn_object_set_map(binn_t object, const char const *key, const binn_t map);
extern int binn_object_set_object(binn_t object, const char const *key, const binn_t obj);
extern int binn_object_set_int8(binn_t object, const char const *key, const int8_t value);
extern int binn_object_set_int16(binn_t object, const char const *key, const int16_t value);
extern int binn_object_set_int32(binn_t object, const char const *key, const int32_t value);
extern int binn_object_set_int64(binn_t object, const char const *key, const int64_t value);
extern int binn_object_set_uint8(binn_t object, const char const *key, const uint8_t value);
extern int binn_object_set_uint16(binn_t object, const char const *key, const uint16_t value);
extern int binn_object_set_uint32(binn_t object, const char const *key, const uint32_t value);
extern int binn_object_set_uint64(binn_t object, const char const *key, const uint64_t value);
extern int binn_object_set_float(binn_t object, const char const *key, const float value);
extern int binn_object_set_double(binn_t object, const char const *key, const double value);
extern int binn_object_set_bool(binn_t object, const char const *key, const char value);
extern int binn_object_set_null(binn_t object, const char const *key);
extern int binn_object_set_blob(binn_t object, const char const *key, const void const *ptr, const size_t size);
extern int binn_object_set_string(binn_t object, const char const *key, const char const *str);

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// READ ACCESSES ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// get from list
extern int binn_list_get_list(binn_t list, const int pos, binn_t const *plist);
extern int binn_list_get_map(binn_t list, const int pos, binn_t const *pmap);
extern int binn_list_get_object(binn_t list, const int pos, binn_t const *pobject);
extern int binn_list_get_int8(binn_t list, const int pos, int8_t const *pvalue);
extern int binn_list_get_int16(binn_t list, const int pos, int16_t const *pvalue);
extern int binn_list_get_int32(binn_t list, const int pos, int32_t const *pvalue);
extern int binn_list_get_int64(binn_t list, const int pos, int64_t const *pvalue);
extern int binn_list_get_uint8(binn_t list, const int pos, uint8_t const *pvalue);
extern int binn_list_get_uint16(binn_t list, const int pos, uint16_t const *pvalue);
extern int binn_list_get_uint32(binn_t list, const int pos, uint32_t const *pvalue);
extern int binn_list_get_uint64(binn_t list, const int pos, uint64_t const *pvalue);
extern int binn_list_get_float(binn_t list, const int pos, float const *pvalue);
extern int binn_list_get_double(binn_t list, const int pos, double const *pvalue);
extern int binn_list_get_bool(binn_t list, const int pos, char const *pvalue);
extern int binn_list_get_blob(binn_t list, const int pos, void const const **ptr, size_t const *psize);
extern int binn_list_get_string(binn_t list, const int pos, char const **str);

// get from map
extern int binn_map_get_list(binn_t map, const int id, binn_t const *plist);
extern int binn_map_get_map(binn_t map, const int id, binn_t const *pmap);
extern int binn_map_get_object(binn_t map, const int id, binn_t const *pobject);
extern int binn_map_get_int8(binn_t map, const int id, const int8_t const *pvalue);
extern int binn_map_get_int16(binn_t map, const int id, const int16_t const *pvalue);
extern int binn_map_get_int32(binn_t map, const int id, const int32_t const *pvalue);
extern int binn_map_get_int64(binn_t map, const int id, const int64_t const *pvalue);
extern int binn_map_get_uint8(binn_t map, const int id, const uint8_t const *pvalue);
extern int binn_map_get_uint16(binn_t map, const int id, const uint16_t const *pvalue);
extern int binn_map_get_uint32(binn_t map, const int id, const uint32_t const *pvalue);
extern int binn_map_get_uint64(binn_t map, const int id, const uint64_t const *pvalue);
extern int binn_map_get_float(binn_t map, const int id, const float const *pvalue);
extern int binn_map_get_double(binn_t map, const int id, const double const *pvalue);
extern int binn_map_get_bool(binn_t map, const int id, const char const *pvalue);
extern int binn_map_get_blob(binn_t map, const int id, const void const **ptr, const size_t size);
extern int binn_map_get_string(binn_t map, const int id, const char const *str);

// get from object
extern int binn_object_get_list(binn_t object, const char const *key, binn_t *plist);
extern int binn_object_get_map(binn_t object, const char const *key, binn_t *pmap);
extern int binn_object_get_object(binn_t object, const char const *key, binn_t *pobject);
extern int binn_object_get_int8(binn_t object, const char const *key, int8_t *pvalue);
extern int binn_object_get_int16(binn_t object, const char const *key, int16_t *pvalue);
extern int binn_object_get_int32(binn_t object, const char const *key, int32_t *pvalue);
extern int binn_object_get_int64(binn_t object, const char const *key, int64_t *pvalue);
extern int binn_object_get_uint8(binn_t object, const char const *key, uint8_t *pvalue);
extern int binn_object_get_uint16(binn_t object, const char const *key, uint16_t *pvalue);
extern int binn_object_get_uint32(binn_t object, const char const *key, uint32_t *pvalue);
extern int binn_object_get_uint64(binn_t object, const char const *key, uint64_t *pvalue);
extern int binn_object_get_float(binn_t object, const char const *key, float *pvalue);
extern int binn_object_get_double(binn_t object, const char const *key, double *pvalue);
extern int binn_object_get_bool(binn_t object, const char const *key, char *pvalue);
extern int binn_object_get_blob(binn_t object, const char const *key, void **ptr, size_t *psize);
extern int binn_object_get_string(binn_t object, const char const *key, char **str);

#ifdef __cplusplus
}
#endif

#endif //__BINN_H__
