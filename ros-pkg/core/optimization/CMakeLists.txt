cmake_minimum_required(VERSION 2.8.3)
project(optimization)
find_package(catkin_simple REQUIRED)
catkin_simple()

find_package(OpenMP)
add_definitions("-fopenmp")

cs_add_library(${PROJECT_NAME} src/${PROJECT_NAME}.cpp src/nips.cpp src/grid_search.cpp)
target_link_libraries(${PROJECT_NAME} gomp)
cs_add_library(common_functions src/common_functions.cpp)

# TODO:
#cs_add_compile_flags(${PROJECT_NAME} -fopenmp)
#cs_add_link_flags(${PROJECT_NAME} -fopenmp)

cs_add_executable(demo_nesterov src/demo_nesterov.cpp)
target_link_libraries(demo_nesterov ${PROJECT_NAME} common_functions)

catkin_add_gtest(test_optimization src/test_optimization.cpp)
target_link_libraries(test_optimization ${PROJECT_NAME} common_functions)

cs_export()