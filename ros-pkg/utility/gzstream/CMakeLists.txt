cmake_minimum_required(VERSION 2.8.3)
project(gzstream)
find_package(catkin_simple REQUIRED)
catkin_simple()

cs_add_library(gzstream src/gzstream.cpp)
target_link_libraries(gzstream z)

cs_add_executable(test_gzip src/test_gzip.cpp)
target_link_libraries(test_gzip gzstream)

cs_add_executable(test_gunzip src/test_gunzip.cpp)
target_link_libraries(test_gunzip gzstream)

cs_export(LIBRARIES z)
