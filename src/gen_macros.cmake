
macro (GEN_BINN_LIST_ADD_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_list_add_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_list_add_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_LIST_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_list_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_list_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_LIST_GET_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_list_get_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_list_get_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_OBJECT_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_object_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_object_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_OBJECT_GET_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_object_get_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_object_get_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_OBJECT_SET_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_object_set_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_object_set_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_MAP_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_map_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_map_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_MAP_GET_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_map_get_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_map_get_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_MAP_SET_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_map_set_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_map_set_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_ALL_XXX name type binn)
    GEN_BINN_LIST_ADD_XXX(${name} ${type} ${binn})
    GEN_BINN_LIST_GET_XXX(${name} ${type} ${binn})

    GEN_BINN_MAP_GET_XXX(${name} ${type} ${binn})
    GEN_BINN_MAP_SET_XXX(${name} ${type} ${binn})

    GEN_BINN_OBJECT_GET_XXX(${name} ${type} ${binn})
    GEN_BINN_OBJECT_SET_XXX(${name} ${type} ${binn})
endmacro()
