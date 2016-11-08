
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/gen)

include(gen_macros.cmake)

GEN_BINN_ALL_XXX("int8"      "int8_t"    "BINN_TYPE_INT8")
GEN_BINN_ALL_XXX("uint8"     "uint8_t"   "BINN_TYPE_UINT8")

file(GLOB_RECURSE LOCAL_GEN_FILES ${CMAKE_CURRENT_BINARY_DIR}/gen/*.c)

set(LOCAL_SOURCES
    binn_internal.c
    binn_init.c
    binn_new.c
    binn_create.c
    binn_free.c
    binn_list.c
    binn_map.c
    binn_object.c
    binn_is_valid.c
    binn_object_set.c
    binn_search_for_key.c
    binn_add_value.c
    
    # binn_json.c 

    ## generated
    ${LOCAL_GEN_FILES})

add_library(binn STATIC ${LOCAL_SOURCES})
target_link_libraries(binn skarnet)
