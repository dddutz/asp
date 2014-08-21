cmake_minimum_required(VERSION 2.8.3)
project(timer)
find_package(catkin_simple REQUIRED)
catkin_simple()

cs_add_library(timer src/lib/timer.cpp src/lib/profile.cpp)
target_link_libraries(timer rt)

catkin_add_gtest(test_timer src/test/test_timer.cpp)
target_link_libraries(test_timer timer)
set_target_properties(test_timer PROPERTIES COMPILE_FLAGS -Wno-unused-but-set-variable)

cs_export()





