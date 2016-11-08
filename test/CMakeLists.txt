
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

###############################################################################
set(LOCAL_SOURCES
    test_basic.c
)

add_executable(test_basic ${LOCAL_SOURCES})
target_link_libraries(test_basic binn)

###############################################################################
set(LOCAL_SOURCES
    test_integers.c
)

add_executable(test_integers ${LOCAL_SOURCES})
target_link_libraries(test_integers binn)
