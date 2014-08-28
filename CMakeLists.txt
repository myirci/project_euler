# This cmake file is used to build all the programs for all the problems

cmake_minimum_required(VERSION 2.8)

project(project_euler)

# compiler settings
set(CMAKE_BUILD_TYPE Debug)
add_definitions(-std=c++0x)

#cmake settingss
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${project_euler_SOURCE_DIR}/cmake)

add_subdirectory(utility)
add_subdirectory(problem_1)
add_subdirectory(problem_2)
add_subdirectory(problem_3)

