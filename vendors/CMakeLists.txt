file(
    GLOB
    VENDOR_FOLDERS
    *
)

set(glew-cmake_BUILD_SHARED OFF)

foreach(VENDOR_FOLDER ${VENDOR_FOLDERS})
    if(IS_DIRECTORY ${VENDOR_FOLDER})
        message(STATUS "Adding vendor: ${VENDOR_FOLDER}")
        add_subdirectory(${VENDOR_FOLDER})
    endif()
endforeach()