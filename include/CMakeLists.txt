
file(REMOVE_RECURSE ${CMAKE_CURRENT_BINARY_DIR}/binn)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/binn.h
    ${CMAKE_CURRENT_BINARY_DIR}/binn/binn.h
    COPYONLY
    )