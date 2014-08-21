# Generated from: pcl_flags/cmake/pcl_flags-extras.cmake.em

if(_PCL_FLAGS_EXTRAS_INCLUDED_)
  return()
endif()
set(_PCL_FLAGS_EXTRAS_INCLUDED_ TRUE)

find_package(PCL REQUIRED)

include_directories(SYSTEM ${PCL_INCLUDE_DIRS})
