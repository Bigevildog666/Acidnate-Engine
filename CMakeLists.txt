cmake_minimum_required (VERSION 3.14)

project(Acidnate-Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Vulkan/Volk
add_subdirectory(External/volk)

# GLFW
add_subdirectory(External/glfw-3.4)

# GLM
add_subdirectory(External/glm)

# stb_image
add_subdirectory(External/stb_image)

# imgui
add_subdirectory(External/imgui-docking)

# plog
add_subdirectory(External/plog-1.1.10)


# set all Source Files 
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/Source/*.cpp")

# Add source to this project's executable
add_executable(${CMAKE_PROJECT_NAME})
target_sources(${CMAKE_PROJECT_NAME} PUBLIC ${MY_SOURCES} ${AngelscriptAddon})
target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Source")



if (MSVC) 
  SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/PROFILE")
endif()

# Add lbraries aka thirdparty stuff
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE volk glfw glm::glm stb_image imgui plog)
#target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE volk glfw stb_image plog imgui tomlplusplus::tomlplusplus glad glm::glm)







# tomlplusplus
# include(FetchContent)
# FetchContent_Declare(
#    tomlplusplus
#    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
#    GIT_TAG v3.4.0
# )
# FetchContent_MakeAvailable(tomlplusplus)

# AngelScript 
# add_subdirectory(Thirdparty/angelscript/sdk/angelscript/projects/cmake)
# include_directories(Thirdparty/angelscript/sdk/add_on/scriptstdstring
#					Thirdparty/angelscript/sdk/add_on/scriptbuilder)
# set(AngelscriptAddon 
# 	Thirdparty/angelscript/sdk/add_on/scriptstdstring/scriptstdstring.cpp    
#	Thirdparty/angelscript/sdk/add_on/scriptstdstring/scriptstdstring.h
#	Thirdparty/angelscript/sdk/add_on/scriptbuilder/scriptbuilder.cpp
#	Thirdparty/angelscript/sdk/add_on/scriptbuilder/scriptbuilder.h)





