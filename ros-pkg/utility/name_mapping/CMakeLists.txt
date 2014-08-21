cmake_minimum_required(VERSION 2.8.3)
project(name_mapping)
find_package(catkin_simple REQUIRED)
catkin_simple()

cs_add_library(name_mapping
  src/lib/name_mapping.cpp
  src/lib/common_name_mappables.cpp
  )

catkin_add_gtest(test_name_mapping src/test/test_name_mapping.cpp)
target_link_libraries(test_name_mapping name_mapping)

cs_export()
