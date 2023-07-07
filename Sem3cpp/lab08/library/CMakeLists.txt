#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(ComplexVector)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(LIB_SOURCE_DIR ${PROJECT_SOURCE_DIR}/dbg)
else()
    set(LIB_SOURCE_DIR ${PROJECT_SOURCE_DIR}/release)
endif()

message(INFO " SOURCE_DIR: " ${LIB_SOURCE_DIR})


set(HEADERS_DIR ${LIB_SOURCE_DIR}/include/)
file(GLOB SOURCES "${LIB_SOURCE_DIR}/src/*.cpp")

include_directories(${HEADERS_DIR})

# This needs to be done universally to any static library
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Define the library
add_library(${PROJECT_NAME} STATIC ${SOURCES})

#----------------------------------------------------------------------------
# Expose project's public includes to other subprojects through cache variable.
set(${PROJECT_NAME}_INCLUDE_DIR ${HEADERS_DIR} CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)