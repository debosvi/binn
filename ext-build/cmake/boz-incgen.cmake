
macro (BOZ_INCLUDE_GEN name prefix major minor patch)
    set(${name}_VERSION ${major}.${minor} CACHE INTERNAL "")
    set(${name}_SOVERSION ${major}.${minor}.${patch} CACHE INTERNAL "")
    set(header ${name}.h)
    message(STATUS "Generates header ${header}, version (${${name}_VERSION})")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${header} ${CMAKE_BINARY_DIR}/include/${prefix}/${header} @ONLY)
    BOZ_INSTALL_HEADER(${prefix}/${header})
endmacro()


