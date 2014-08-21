cmake_minimum_required(VERSION 2.8.3)
project(eigen_extensions)
find_package(catkin_simple REQUIRED)
catkin_simple()

cs_add_library(${PROJECT_NAME}
  src/random.cpp
  )

catkin_add_gtest(test_random src/test_random.cpp)
target_link_libraries(test_random ${PROJECT_NAME})

catkin_add_gtest(test_eigen_extensions src/test_eigen_extensions.cpp)
target_link_libraries(test_eigen_extensions ${PROJECT_NAME})

cs_add_executable(cat src/cat.cpp)
cs_add_executable(convert src/convert.cpp)
cs_add_executable(scratch src/throwaway/scratch.cpp)

cs_export()
