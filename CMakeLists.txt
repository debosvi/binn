cmake_minimum_required (VERSION 3.0)
project (binn)

include(project_ver.cmake)
include(ext-build/boz-build.cmake)
include(CTest)

include(tools.cmake)

#set (CMAKE_VERBOSE_MAKEFILE ON)

include_directories(${CMAKE_BINARY_DIR}/include)

add_subdirectory(include)
add_subdirectory(src)

add_test_if_enable(test BOZ_GLOBAL_TEST)
