
macro(BOZ_INSTALL_HEADER arg)
	get_filename_component(prefix ${arg} DIRECTORY )
	get_filename_component(name ${arg} NAME )
	message(STATUS "Install header: ${name}")
	install(FILES ${CMAKE_BINARY_DIR}/include/${arg}
		DESTINATION ${HEADER_INSTALL_DIR}/${prefix}
		)
endmacro()

macro(BOZ_INSTALL_ITEM target)
    message(STATUS "Install target ${target}")
    install(TARGETS ${target}
        RUNTIME DESTINATION ${BINARY_INSTALL_DIR}
        LIBRARY DESTINATION ${LIBRARY_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIBRARY_INSTALL_DIR}/static
    )
endmacro()

macro(BOZ_INSTALL_ITEM_WITH_PREFIX target prefix)
    message(STATUS "Install target ${target}")
    install(TARGETS ${target}
        RUNTIME DESTINATION ${BINARY_INSTALL_DIR}/${prefix}
        LIBRARY DESTINATION ${LIBRARY_INSTALL_DIR}/${prefix}
        ARCHIVE DESTINATION ${LIBRARY_INSTALL_DIR}/${prefix}/static
    )
endmacro()

