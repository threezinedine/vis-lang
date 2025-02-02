cmake_minimum_required(VERSION 3.10)

project(VizLang)

enable_testing()

# options definitions
option(USE_OPENGL "Use OpenGL as the rendering API" ON) # currently only OpenGL is supported

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g)
    add_definitions(-D_DEBUG)
else()
    add_compile_options(-O3)
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
)

file(
    GLOB_RECURSE
    NON_UNIT_TEST_FILES
    src/platforms/*.cpp
)

# remove all windows resources, linux resources and test files from sources
list(REMOVE_ITEM SOURCES ${WINDOW_RESOURCES} ${LINUX_RESOURCES} ${TEST_FILES})

# remove non unit test files from test files
set(UNIT_TEST_SOURCES ${SOURCES})
list(REMOVE_ITEM UNIT_TEST_SOURCES ${NON_UNIT_TEST_FILES})

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
)

# copy the whole assets directory to the build directory (overwriting the existing one)
add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory 
    ${CMAKE_SOURCE_DIR}/assets 
    ${CMAKE_BINARY_DIR}/assets
)

# Add test
add_test(
    NAME ${TEST_PROJECT_NAME}
    COMMAND ${TEST_PROJECT_NAME}
)