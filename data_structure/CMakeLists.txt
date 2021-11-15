cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(window VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(single  single_number.cpp)
add_executable(major  major_element.cpp)
add_executable(three_sum  three_sum.cpp)
add_executable(merge  merge_intervals.cpp)
add_executable(hash_map  hash_map.cpp)
add_executable(triangle  yanghui_triangle.cpp)
add_executable(rotate  rotate.cpp)
add_executable(spiral  spiral_matrix.cpp)
add_executable(search  matrix_search.cpp)
add_executable(erase_overlap  erase_overlap_intervals.cpp)
add_executable(product  multi_export_self.cc)
add_executable(sum_k  sum_k.cpp)
add_executable(word_pattern  word_pattern.cpp)
add_executable(cycle  cycle_list.cpp)
add_executable(k_group  25_k_group_reverse.cpp)
add_executable(avg_tree  108_avg_binary_tree.cpp)
add_executable(build_tree  105_build_tree.cpp)


include_directories ("${PROJECT_SOURCE_DIR}/tree_lib")
add_subdirectory (tree_lib)

add_executable(zigzagLevelOrder  103_zigzagLevelOrder.cpp)
target_link_libraries (zigzagLevelOrder PUBLIC TreeLib)

target_include_directories(zigzagLevelOrder PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/tree_lib"
                          )

add_executable(pural_matrix_dot  pural_matrix_dot.cpp)