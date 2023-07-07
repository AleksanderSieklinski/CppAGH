#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(NestedProject)

#----------------------------------------------------------------------------
# global configuration
#set(CMAKE_BUILD_TYPE Debug ) # Release
set(CMAKE_BUILD_TYPE Release ) # Release
message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

set(CMAKE_POSITION_INDEPENDENT_CODE ON) # This needs to be done universally to any static library

#----------------------------------------------------------------------------
# prevent for in-source building
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

#----------------------------------------------------------------------------
add_definitions(-DDATAPATH=\"${PROJECT_SOURCE_DIR}/data\")
add_compile_definitions("DEBUG=$<CONFIG:Debug>") # gives 1 or 0
add_compile_definitions("RELEASE=$<CONFIG:Release>")
#----------------------------------------------------------------------------
# Configure the components (subprojects)
# NOTE: The order matters! The most independent ones should go first.
#       If A and B really depend on each other, CMake  can build such correctly,
#       if you specify full path to the include directory
add_subdirectory(library)
add_subdirectory(executables)