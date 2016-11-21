
## find SKALIBS
find_package(Skalibs REQUIRED)

message(STATUS "Skalibs found: " ${Skalibs_VERSION_STRING})
message(STATUS "Skalibs include dirs: " ${Skalibs_INCLUDE_DIRS})
message(STATUS "Skalibs library dirs: " ${Skalibs_LIBRARY_DIRS})
include_directories(${Skalibs_INCLUDE_DIRS})
link_directories(${Skalibs_LIBRARY_DIRS})

## find JANSSON
find_package(Jansson REQUIRED)

message(STATUS "Jansson found: " ${Jansson_VERSION_STRING})
message(STATUS "Jansson include dirs: " ${Jansson_INCLUDE_DIRS})
message(STATUS "Jansson library dirs: " ${Jansson_LIBRARY_DIRS})
include_directories(${Jansson_INCLUDE_DIRS})
link_directories(${Jansson_LIBRARY_DIRS})
