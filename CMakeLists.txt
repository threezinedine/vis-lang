cmake_minimum_required(VERSION 3.10)

project(VizLang)

# options definitions
option(USE_OPENGL "Use OpenGL as the rendering API" ON) # currently only OpenGL is supported

if (MSVC)
    add_definitions(-DMSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
                PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    file(
        GLOB_RECURSE 
        VENDOR_SOURCES
        vendors/**/*.cpp
    )

    foreach(${VENDOR_SOURCE} ${VENDOR_SOURCES})
        set_source_files_properties(${VENDOR_SOURCE} PROPERTIES COMPILE_FLAGS /w) 
    endforeach()
endif()

if (MINGW)
    add_definitions(-DMINGW)

    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(-g)
        add_definitions(-D_DEBUG)
    else()
        add_compile_options(-O3)
    endif()
endif()

file(
    GLOB_RECURSE
    SOURCES
    src/*.cpp
)

file(
    GLOB
    WINDOW_RESOURCES
    src/**/windows/*.cpp
)

file(
    GLOB
    LINUX_RESOURCES
    src/**/linux/*.cpp
)

file(
    GLOB
    TEST_FILES 
    src/**/__tests__/*.cpp
    src/**/**/__tests__/*.cpp
)

file(
    GLOB_RECURSE
    NON_UNIT_TEST_FILES
    src/platforms/*.cpp
)

file (
    GLOB_RECURSE 
    PLATFORM_FILES_FOR_TEST
    src/platforms/test/*.cpp
)

# remove all windows resources, linux resources and test files from sources
list(REMOVE_ITEM SOURCES 
    ${WINDOW_RESOURCES} 
    ${LINUX_RESOURCES} 
    ${TEST_FILES} 
    ${PLATFORM_FILES_FOR_TEST})

# remove non unit test files from test files
set(UNIT_TEST_SOURCES ${SOURCES})
list(REMOVE_ITEM UNIT_TEST_SOURCES ${NON_UNIT_TEST_FILES})

# all shared vendors 
set(VENDOR_LIBS nlohmann_json)

set(GRAPHICS_API_LIBRARIES)

if (USE_OPENGL)
    message(STATUS "Using OpenGL as the rendering API")
    add_definitions(-DUSE_OPENGL)

    list(APPEND GRAPHICS_API_LIBRARIES glfw libglew_static)
    set(GLFW_LIBRARY_TYPE STATIC)
    set(GLFW_BUILD_EXAMPLES OFF)
    set(GLFW_BUILD_TESTS OFF)
    set(GLFW_BUILD_DOCS OFF)

    set(glew-CMAKE_BUILD_SHARED FALSE)
    set(ONLY_LIBS ON)
else()
    message(FATAL_ERROR "Only OpenGL is supported at the moment")
endif()

if (WIN32)
    add_definitions(-DWINDOWS)
    set(PLATFORM_RESOURCES ${WINDOW_RESOURCES})
    set(RESOURCE_FILES icon.rc)
    list(APPEND GRAPHICS_API_LIBRARIES opengl32)
elseif (UNIX)
    add_definitions(-DLINUX)
    set(PLATFORM_RESOURCES ${LINUX_RESOURCES})
    set(RESOURCE_FILES)
endif()

add_subdirectory(vendors)

foreach(SOURCE ${SOURCES})
    message(STATUS "Found source file: ${SOURCE}")
endforeach()

foreach(TEST_FILE ${TEST_FILES})
    message(STATUS "Found test file: ${TEST_FILE}")
endforeach()


add_executable(
    ${PROJECT_NAME}
    main.cpp
    ${SOURCES}
    ${PLATFORM_RESOURCES}
    ${RESOURCE_FILES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${GRAPHICS_API_LIBRARIES}
    STBImage
    ImGui
    ${VENDOR_LIBS}
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    src
)

# testing setup -> VizLang_Test
set(TEST_PROJECT_NAME ${PROJECT_NAME}_Test)
add_executable(
    ${TEST_PROJECT_NAME}
    test.cpp
    ${TEST_FILES}
    ${UNIT_TEST_SOURCES}
    ${PLATFORM_FILES_FOR_TEST}
)

target_include_directories(
    ${TEST_PROJECT_NAME}
    PRIVATE
    src
)

target_link_libraries(
    ${TEST_PROJECT_NAME}
    PRIVATE
    gtest
    gtest_main
    gmock
    gmock_main
    ${VENDOR_LIBS}
)

# copy the whole assets directory to the build directory (overwriting the existing one)
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_SOURCE_DIR}/assets 
    ${CMAKE_BINARY_DIR}/assets
)