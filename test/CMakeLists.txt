
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

###############################################################################
set(LOCAL_SOURCES
    test_basic.c
)

add_executable(test_basic ${LOCAL_SOURCES})
target_link_libraries(test_basic binn)

install(TARGETS test_basic
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_PREFIX}/share/binn/test
)

###############################################################################
set(LOCAL_SOURCES
    test_integers.c
)

add_executable(test_integers ${LOCAL_SOURCES})
target_link_libraries(test_integers binn)

install(TARGETS test_integers
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_PREFIX}/share/binn/test
)

###############################################################################
set(LOCAL_SOURCES
    test_json.c
)

add_executable(test_json ${LOCAL_SOURCES})
target_link_libraries(test_json binn_json)

install(TARGETS test_json
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_PREFIX}/share/binn/test
)