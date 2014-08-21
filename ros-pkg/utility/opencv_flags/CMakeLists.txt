cmake_minimum_required(VERSION 2.8.3)
project(opencv_flags)
find_package(catkin_simple REQUIRED)
catkin_simple()

find_package(OpenCV REQUIRED)

cs_export(INCLUDE_DIRS ${OpenCV_INCLUDE_DIRS}
          LIBRARIES ${OpenCV_LIBRARIES})
