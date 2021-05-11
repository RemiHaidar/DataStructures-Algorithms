add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)

target_include_directories(
    main PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
    main PRIVATE
    Algorithms
    DataStructures
)