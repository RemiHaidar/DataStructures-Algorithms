add_library(Algorithms ${CMAKE_CURRENT_SOURCE_DIR}/source/Algorithms.cpp)

target_include_directories(
    Algorithms PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)