
###############################################################################
set(LOCAL_SOURCES
    binn_to_json.c
    binn_to_json_str.c
)

add_library(binn_json STATIC ${LOCAL_SOURCES})
target_link_libraries(binn_json 
    binn 
    jansson
)

install(TARGETS binn_json
    ARCHIVE
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/binn
)