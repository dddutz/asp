cmake_minimum_required(VERSION 2.8.3)
project(pcl_flags)
find_package(catkin_simple REQUIRED)
catkin_simple()

find_package(PCL REQUIRED)

cs_export(LIBRARIES ${PCL_LIBRARIES}
          CFG_EXTRAS pcl_flags-extras.cmake)
