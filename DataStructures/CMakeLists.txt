add_library(DataStructures ${CMAKE_CURRENT_SOURCE_DIR}/source/DataStructures.cpp)

target_include_directories(
    DataStructures PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(
    DataStructures PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/source/BinaryTree.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/HashTable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/LinkedList.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/source/Stack.cpp
)