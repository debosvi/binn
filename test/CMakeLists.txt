
###############################################################################
set(LOCAL_SOURCES
    test_basic.c
)

add_executable(test_basic ${LOCAL_SOURCES})
target_link_libraries(test_basic binn)

BOZ_INSTALL_ITEM(test_basic "test")

###############################################################################
set(LOCAL_SOURCES
    test_blob.c
)

add_executable(test_blob ${LOCAL_SOURCES})
target_link_libraries(test_blob binn)

BOZ_INSTALL_ITEM(test_blob "test")

###############################################################################
set(LOCAL_SOURCES
    test_string.c
)

add_executable(test_string ${LOCAL_SOURCES})
target_link_libraries(test_string binn)

BOZ_INSTALL_ITEM(test_string "test")

###############################################################################
set(LOCAL_SOURCES
    test_json.c
)

add_executable(test_json ${LOCAL_SOURCES})
target_link_libraries(test_json binn_json)

BOZ_INSTALL_ITEM(test_json "test")

###############################################################################
set(LOCAL_SOURCES
    test_sublist.c
)

add_executable(test_sublist ${LOCAL_SOURCES})
target_link_libraries(test_sublist binn)

BOZ_INSTALL_ITEM(test_sublist "test")

###############################################################################
set(LOCAL_SOURCES
    test_submap.c
)

add_executable(test_submap ${LOCAL_SOURCES})
target_link_libraries(test_submap binn)

BOZ_INSTALL_ITEM(test_submap "test")

###############################################################################
set(LOCAL_SOURCES
    test_subobjects.c
)

add_executable(test_subobjects ${LOCAL_SOURCES})
target_link_libraries(test_subobjects binn)

BOZ_INSTALL_ITEM(test_subobjects "test")
