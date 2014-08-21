cmake_minimum_required(VERSION 2.8.3)
project(pipeline2)
find_package(catkin_simple REQUIRED)
catkin_simple()

#common commands for building c++ executables and libraries
cs_add_library(pipeline2 src/pipeline2.cpp)
target_link_libraries(pipeline2 pthread)

catkin_add_gtest(test_pipeline2 test/test_pipeline2.cpp)
target_link_libraries(test_pipeline2 pipeline2)

cs_export()