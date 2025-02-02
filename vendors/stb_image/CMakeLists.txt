cmake_minimum_required(VERSION 3.10)

project(STBImage)

add_library(
    ${PROJECT_NAME}
    STATIC 
    stb_image.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    .
)