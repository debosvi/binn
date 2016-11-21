
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

BOZ_INSTALL_ITEM_WITH_PREFIX(binn_json "binn")
