cmake_minimum_required (VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)

project(stb_image)

add_library(stb_image INTERFACE)
target_sources(stb_image PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/stb_image.h")
target_include_directories(stb_image INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

