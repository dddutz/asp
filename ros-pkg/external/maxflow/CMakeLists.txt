cmake_minimum_required(VERSION 2.8.3)
project(maxflow)
find_package(catkin_simple REQUIRED)
catkin_simple()

cs_add_library(maxflow src/lib/graph.cpp src/lib/maxflow.cpp)

set_target_properties(maxflow PROPERTIES COMPILE_FLAGS "-Wno-error")

cs_export()