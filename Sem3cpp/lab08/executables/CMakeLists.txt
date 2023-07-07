#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(Exec)

#----------------------------------------------------------------------------
add_definitions( ${ComplexVector_DEFINITIONS} )
include_directories(${ComplexVector_INCLUDE_DIR} )

#---------------------------------------------------------------------------
add_executable(vector main/vector.cpp)
target_link_libraries(vector ComplexVector)

#---------------------------------------------------------------------------
add_executable(complex main/complex.cpp)
target_link_libraries(complex ComplexVector)