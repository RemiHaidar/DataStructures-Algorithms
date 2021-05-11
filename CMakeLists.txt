cmake_minimum_required(VERSION 3.12)

project(DataStructures&Algorithms)

set(DATA_STRUCTURES_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/DataStructures/include)
set(ALGORITHMS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Algorithms/include)

add_subdirectory(app)

add_subdirectory(Algorithms)

add_subdirectory(DataStructures)
