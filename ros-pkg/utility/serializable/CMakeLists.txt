cmake_minimum_required(VERSION 2.8.3)
project(serializable)
find_package(catkin_simple REQUIRED)
catkin_simple()

cs_add_library(serializable src/lib/serializable.cpp)
find_package(Boost REQUIRED COMPONENTS filesystem system)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(serializable ${Boost_LIBRARIES})

catkin_add_gtest(test_serializable src/test/test_serializable.cpp)
target_link_libraries(test_serializable serializable ${Boost_LIBRARIES})

cs_export()
