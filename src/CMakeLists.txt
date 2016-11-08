
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/gen)

include(gen_macros.cmake)

GEN_BINN_ALL_XXX("int8"      "int8_t"    "BINN_TYPE_INT8")
GEN_BINN_ALL_XXX("uint8"     "uint8_t"   "BINN_TYPE_UINT8")
GEN_BINN_ALL_XXX("int16"     "int16_t"   "BINN_TYPE_INT16")
GEN_BINN_ALL_XXX("uint16"    "uint16_t"  "BINN_TYPE_UINT16")
GEN_BINN_ALL_XXX("int32"     "int32_t"   "BINN_TYPE_INT32")
GEN_BINN_ALL_XXX("uint32"    "uint32_t"  "BINN_TYPE_UINT32")
GEN_BINN_ALL_XXX("int64"     "int64_t"   "BINN_TYPE_INT64")
GEN_BINN_ALL_XXX("uint64"    "uint64_t"  "BINN_TYPE_UINT64")

file(GLOB_RECURSE LOCAL_GEN_FILES ${CMAKE_CURRENT_BINARY_DIR}/gen/*.c)

set(LOCAL_SOURCES
    binn_add_value.c
    binn_get_value.c
    binn_create.c
    binn_free.c
    binn_init.c
    binn_internal.c
    binn_is_valid.c
    binn_list.c
    binn_map.c
    binn_new.c
    binn_object.c
    binn_object_get.c
    binn_object_set.c
    binn_search_for_key.c
    
    # binn_json.c 

    ## generated
    ${LOCAL_GEN_FILES})

add_library(binn STATIC ${LOCAL_SOURCES})
target_link_libraries(binn skarnet)
