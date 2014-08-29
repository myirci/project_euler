# This cmake file is used to build all the programs for all the problems

cmake_minimum_required(VERSION 2.8)

project(project_euler)

# compiler settings
set(CMAKE_BUILD_TYPE Debug)
add_definitions(-std=c++0x)

#cmake settingss
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${project_euler_SOURCE_DIR}/cmake)

# configure a header file to pass some of the CMake settings to the source
configure_file(
        "${PROJECT_SOURCE_DIR}/project_euler_config.h.in"
        "${PROJECT_BINARY_DIR}/project_euler_config.h")
include_directories(${PROJECT_BINARY_DIR})

add_subdirectory(utility)
add_subdirectory(test)
add_subdirectory(problem_1)
add_subdirectory(problem_2)
add_subdirectory(problem_3)
add_subdirectory(problem_4)

