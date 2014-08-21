cmake_minimum_required(VERSION 2.8.3)
project(bag_of_tricks)
find_package(catkin_simple REQUIRED)
catkin_simple()

find_package(Boost REQUIRED COMPONENTS thread filesystem system)
include_directories(${Boost_INCLUDE_DIRS})

find_package(OpenCV REQUIRED COMPONENTS core highgui)
include_directories(${OpenCV_INCLUDE_DIRS})

cs_add_library(${PROJECT_NAME}
  src/image_region_iterator.cpp
  src/connected_components.cpp
  src/next_path.cpp
  src/recursive_find.cpp
  src/relative_path.cpp
  )
target_link_libraries(${PROJECT_NAME}
  ${Boost_LIBRARIES}
  ${OpenCV_LIBRARIES}
  )

catkin_add_gtest(test_next_path src/test_next_path.cpp)
target_link_libraries(test_next_path ${PROJECT_NAME})

catkin_add_gtest(test_image_indexer src/test_image_indexer.cpp)
target_link_libraries(test_image_indexer ${PROJECT_NAME})

cs_add_executable(print_relative_paths src/program/throwaway/print_relative_paths.cpp)
target_link_libraries(print_relative_paths ${PROJECT_NAME})

cs_export(INCLUDE_DIRS ${Boost_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS}
          LIBRARIES ${Boost_LIBRARIES} ${OpenCV_LIBRARIES})
