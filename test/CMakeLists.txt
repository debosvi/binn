
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

set(LOCAL_SOURCES
    test_binn.c
    test_binn2.c    
)

add_executable(test_binn ${LOCAL_SOURCES})
target_link_libraries(test_binn binn)
