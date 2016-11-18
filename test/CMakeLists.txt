
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
    test_blob.c
)

add_executable(test_blob ${LOCAL_SOURCES})
target_link_libraries(test_blob binn)

install(TARGETS test_blob
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_PREFIX}/share/binn/test
)

###############################################################################
set(LOCAL_SOURCES
    test_string.c
)

add_executable(test_string ${LOCAL_SOURCES})
target_link_libraries(test_string binn)

install(TARGETS test_string
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

###############################################################################
set(LOCAL_SOURCES
    test_sublist.c
)

add_executable(test_sublist ${LOCAL_SOURCES})
target_link_libraries(test_sublist binn)

install(TARGETS test_sublist
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_PREFIX}/share/binn/test
)

###############################################################################
set(LOCAL_SOURCES
    test_submap.c
)

add_executable(test_submap ${LOCAL_SOURCES})
target_link_libraries(test_submap binn)

install(TARGETS test_submap
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_PREFIX}/share/binn/test
)

###############################################################################
set(LOCAL_SOURCES
    test_subobjects.c
)

add_executable(test_subobjects ${LOCAL_SOURCES})
target_link_libraries(test_subobjects binn)

install(TARGETS test_subobjects
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_PREFIX}/share/binn/test
)
