cmake_minimum_required(VERSION 2.8.3)
project(eigen_flags)
find_package(catkin_simple REQUIRED)
catkin_simple()

find_package(Eigen REQUIRED)
cs_export(INCLUDE_DIRS ${EIGEN_INCLUDE_DIRS})

