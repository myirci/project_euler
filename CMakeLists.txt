# This cmake file is used to build all the programs for all the problems

cmake_minimum_required(VERSION 2.8)

project(project_euler)

# compiler settings
set(CMAKE_BUILD_TYPE Debug)
add_definitions(-std=c++11)

#cmake settingss
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${project_euler_SOURCE_DIR}/cmake)

# configure a header file to pass some of the CMake settings to the source
configure_file(
        "${PROJECT_SOURCE_DIR}/project_euler_config.h.in"
        "${PROJECT_BINARY_DIR}/project_euler_config.h")
include_directories(${PROJECT_BINARY_DIR})

add_subdirectory(utility)
add_subdirectory(problem_001)
add_subdirectory(problem_002)
add_subdirectory(problem_003)
add_subdirectory(problem_004)
add_subdirectory(problem_006)
add_subdirectory(problem_007)
add_subdirectory(problem_008)
add_subdirectory(problem_009)
add_subdirectory(problem_010)
add_subdirectory(problem_012)
add_subdirectory(problem_393)


