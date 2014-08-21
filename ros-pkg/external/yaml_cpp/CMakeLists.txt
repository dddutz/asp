cmake_minimum_required(VERSION 2.8.3)
project(yaml_cpp)
find_package(catkin_simple REQUIRED)
catkin_simple()

cs_add_library(yaml_cpp
  src/binary.cpp
  src/convert.cpp
  src/directives.cpp
  src/emit.cpp
  src/emitfromevents.cpp
  src/emitter.cpp
  src/emitterstate.cpp
  src/emitterutils.cpp
  src/exp.cpp
  src/memory.cpp
  src/nodebuilder.cpp
  src/node.cpp
  src/node_data.cpp
  src/nodeevents.cpp
  src/null.cpp
  src/ostream_wrapper.cpp
  src/parse.cpp
  src/parser.cpp
  src/regex.cpp
  src/scanner.cpp
  src/scanscalar.cpp
  src/scantag.cpp
  src/scantoken.cpp
  src/simplekey.cpp
  src/singledocparser.cpp
  src/stream.cpp
  src/tag.cpp
  )

cs_export()