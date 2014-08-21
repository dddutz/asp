cmake_minimum_required(VERSION 2.8.3)
project(pipeline3)
find_package(catkin_simple REQUIRED)
catkin_simple()

cs_add_library(${PROJECT_NAME}
  src/pipeline.cpp
  src/params.cpp
  src/pod.cpp
  src/example_pods.cpp
  src/twiddler.cpp
  src/common.cpp
  )
catkin_add_gtest(test_pipeline src/test_pipeline.cpp)
target_link_libraries(test_pipeline pipeline3)

#catkin_add_gtest(test_twiddler src/test_twiddler.cpp)
#catkin_add_compile_flags(test_twiddler -std=c++0x)
#target_link_libraries(test_twiddler pipeline3)

cs_add_executable(yaml_experiment src/yaml_experiment.cpp)
target_link_libraries(yaml_experiment ${PROJECT_NAME})

cs_add_executable(yaml_clone src/yaml_clone.cpp)
target_link_libraries(yaml_clone ${PROJECT_NAME})

cs_add_executable(write_graphviz src/prog/write_graphviz.cpp)
target_link_libraries(write_graphviz ${PROJECT_NAME})

cs_export()
