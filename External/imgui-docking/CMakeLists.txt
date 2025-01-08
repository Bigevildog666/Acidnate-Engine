cmake_minimum_required (VERSION 3.11)

project(imgui)

# Vulkan
find_package(Vulkan REQUIRED)

add_library(imgui)
target_sources(imgui PRIVATE 
"${CMAKE_CURRENT_SOURCE_DIR}/imgui.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui.h"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui_demo.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui_draw.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui_tables.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/imgui_widgets.cpp"
# backend
"${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_glfw.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_glfw.h"
"${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_vulkan.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/backends/imgui_impl_vulkan.h"
 )

target_include_directories(imgui PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


target_link_libraries(imgui PUBLIC glfw)
target_link_libraries(imgui PUBLIC Vulkan::Vulkan)
