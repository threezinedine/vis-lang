file(
    GLOB
    VENDOR_FOLDERS
    *
)

foreach(VENDOR_FOLDER ${VENDOR_FOLDERS})
    if(IS_DIRECTORY ${VENDOR_FOLDER})
        add_subdirectory(${VENDOR_FOLDER})
    endif()
endforeach()