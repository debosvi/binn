
macro (GEN_BINN_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_TO_XXX name type binn)
    set(FUNCTION_NAME ${name})
    set(ARG_TYPE ${type})
    set(BINN_TYPE ${binn})
    
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen)
    
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/binn_to_xxx.c.tmpl
        ${CMAKE_CURRENT_BINARY_DIR}/gen/binn_to_${name}.c
        @ONLY)
endmacro()

macro (GEN_BINN_ALL_XXX name type binn)
    GEN_BINN_XXX(${name} ${type} ${binn})
    GEN_BINN_TO_XXX(${name} ${type} ${binn})
endmacro()
