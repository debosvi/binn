
## save globally this script location
set(BOZ_EXT_BUILD_DIR ${CMAKE_CURRENT_LIST_DIR})

set(DEFAULT_INSTALL_DIR ${CMAKE_BINARY_DIR}/.built)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DEFAULT_INSTALL_DIR}/lib/static)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DEFAULT_INSTALL_DIR}/lib)
#     set(LINK_FLAGS -Xlinker -rpath-link -Xlinker ${DEFAULT_INSTALL_DIR}/lib )
set (EXECUTABLE_OUTPUT_PATH ${DEFAULT_INSTALL_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DEFAULT_INSTALL_DIR}/bin)

include_directories (${CMAKE_BINARY_DIR}/include/public/)
include_directories (${CMAKE_BINARY_DIR}/include)

list(APPEND CMAKE_MODULE_PATH ${BOZ_EXT_BUILD_DIR}/Modules)

set(CMAKE_INCLUDE_DIRECTORIES_PROJECT_BEFORE ON) 
include(${CMAKE_CURRENT_LIST_DIR}/boz-find-comps.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/boz-vars.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/boz-install.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/boz-incgen.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/boz-test-macros.cmake)

