cmake_minimum_required(VERSION 3.0)
project(binn)

include(CTest)

# add_definitions(-std=c99)
add_definitions(-Wall -Wextra)

set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_C_FLAGS_RELEASE "-O2 -Werror")

set(CMAKE_C_FLAGS "-Wmissing-prototypes -Wbad-function-cast -Wshadow -Wfloat-equal")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wswitch-default -Wno-unused-result")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-but-set-variable -Wno-unused-variable -Wno-unused-parameter")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wdeclaration-after-statement")
add_definitions(-Wmissing-declarations -Wwrite-strings )
add_definitions(-Wunknown-pragmas)
add_definitions(-Wformat-security)
add_definitions(-Wstrict-aliasing -Wreturn-type -Wmissing-noreturn)


# set (CMAKE_VERBOSE_MAKEFILE ON)

include_directories($ENV{HOME}/usr/include BEFORE)
link_directories($ENV{HOME}/usr/lib/skalibs)

include_directories(${CMAKE_BINARY_DIR}/include)

add_subdirectory(include)

add_subdirectory(src)
add_subdirectory(test)
