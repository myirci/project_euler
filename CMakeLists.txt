# This cmake file is used to build all the programs for all the problems

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(project_euler)

# compiler settings
SET(CMAKE_BUILD_TYPE Debug)
ADD_DEFINITIONS(-std=c++17)

#cmake settingss
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${project_euler_SOURCE_DIR}/cmake)

# configure a header file to pass some of the CMake settings to the source
CONFIGURE_FILE(
        "${PROJECT_SOURCE_DIR}/project_euler_config.h.in"
        "${PROJECT_BINARY_DIR}/project_euler_config.h")
INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR})

ADD_SUBDIRECTORY(utility)
ADD_SUBDIRECTORY(problem_001)
ADD_SUBDIRECTORY(problem_002)
ADD_SUBDIRECTORY(problem_003)
ADD_SUBDIRECTORY(problem_004)
ADD_SUBDIRECTORY(problem_006)
ADD_SUBDIRECTORY(problem_007)
ADD_SUBDIRECTORY(problem_008)
ADD_SUBDIRECTORY(problem_009)
ADD_SUBDIRECTORY(problem_010)
ADD_SUBDIRECTORY(problem_012)
ADD_SUBDIRECTORY(problem_013)
ADD_SUBDIRECTORY(problem_014)
ADD_SUBDIRECTORY(problem_016)
ADD_SUBDIRECTORY(problem_393)


