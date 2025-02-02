cmake_minimum_required(VERSION 3.10)

project(VizLang)

add_subdirectory(vendors)

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

# remove all windows resources, linux resources and test files from sources
list(REMOVE_ITEM SOURCES ${WINDOW_RESOURCES} ${LINUX_RESOURCES} ${TEST_FILES})

if (WIN32)
    add_definitions(-DWINDOWS)
    set(PLATFORM_RESOURCES ${WINDOW_RESOURCES})
elseif (UNIX)
    add_definitions(-DLINUX)
    set(PLATFORM_RESOURCES ${LINUX_RESOURCES})
endif()

add_executable(
    ${PROJECT_NAME}
    main.cpp
    ${SOURCES}
    ${PLATFORM_RESOURCES}
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    src
)

set(TEST_PROJECT_NAME ${PROJECT_NAME}_Test)
add_executable(
    ${TEST_PROJECT_NAME}
    test.cpp
    ${TEST_FILES}
    ${SOURCES}
    ${PLATFORM_RESOURCES}
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