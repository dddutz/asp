cmake_minimum_required(VERSION 2.8.3)
project(dst)
find_package(catkin_simple REQUIRED)
catkin_simple()

cs_add_library(dst
  src/lib/realtime_interface.cpp
  src/lib/potentials_cache.cpp
  src/lib/kinect_sequence.cpp
  src/lib/seed_npg.cpp
  src/lib/color_histogram_npg.cpp
  src/lib/seed_image_distance_npg.cpp
  src/lib/canny_epg.cpp
  src/lib/color_delta_epg.cpp
  src/lib/depth_epg.cpp
  src/lib/depth_epg_velodyne.cpp
  src/lib/node_potential_aggregator.cpp
  src/lib/edge_potential_aggregator.cpp
  src/lib/node_potential_generator.cpp
  src/lib/edge_potential_generator.cpp
  src/lib/depth_projector.cpp
  src/lib/optical_flow_node.cpp
  src/lib/label_flow_npg.cpp
  src/lib/kdtree_node.cpp
  src/lib/scene_alignment_node.cpp
  src/lib/scene_alignment_npg.cpp
  src/lib/surface_normal_node.cpp
  src/lib/surface_normal_epg.cpp
  src/lib/flow_clustering_epg.cpp
  src/lib/edge_potential_product_epg.cpp
  src/lib/bilateral_npg.cpp
  src/lib/helper_functions.cpp
  src/lib/organized_surface_normal_node.cpp
  src/lib/segmentation_visualizer.cpp
  src/lib/patch_classifier.cpp
  src/lib/depth_npg.cpp
  src/lib/icp_npg.cpp
  src/lib/prior_npg.cpp
  src/lib/foreground_kdtree_node.cpp
  src/lib/distance_npg.cpp
  src/lib/template_matcher_npg.cpp
  src/lib/image_processing_nodes.cpp
  src/lib/cie-xyz-image-node.cpp
#  src/lib/sobel-image-node.cpp
  src/lib/boundary_mask_node.cpp
  src/lib/sequence_segmentation_view_controller.cpp
  src/lib/segmentation_pipeline.cpp
  src/lib/struct_svm.cpp
  src/lib/evaluator.cpp
  )
set_target_properties(dst PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")
##rosbuild_link_boost(dst system)

cs_add_executable(image_cut src/program/image_cut.cpp)
cs_add_executable(kinect_cut src/program/kinect_cut.cpp)
target_link_libraries(kinect_cut dst)


cs_add_executable(train src/program/train.cpp)
target_link_libraries(train dst)
set_target_properties(train PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")


cs_add_executable(generate_houghtrack_input src/program/generate_houghtrack_input.cpp)
target_link_libraries(generate_houghtrack_input dst)
set_target_properties(generate_houghtrack_input PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")

cs_add_executable(evaluate_houghtrack src/program/evaluate_houghtrack.cpp)
target_link_libraries(evaluate_houghtrack dst)
set_target_properties(evaluate_houghtrack PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")

cs_add_executable(sequence_stats src/program/sequence_stats.cpp)
target_link_libraries(sequence_stats dst)
set_target_properties(sequence_stats PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")

cs_add_executable(variance src/program/variance.cpp)
target_link_libraries(variance dst)
set_target_properties(variance PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")

cs_add_executable(segmentation_visualizer src/program/segmentation_visualizer.cpp)
target_link_libraries(segmentation_visualizer dst)
set_target_properties(segmentation_visualizer PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable")

cs_add_executable(kinect_cut_interactive src/program/kinect_cut_interactive.cpp)
target_link_libraries(kinect_cut_interactive dst)
set_target_properties(kinect_cut_interactive PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable")

cs_add_executable(openni_viewer_simple src/program/openni_viewer_simple.cpp)
target_link_libraries(openni_viewer_simple dst)
set_target_properties(openni_viewer_simple PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")

cs_add_executable(realtime_interface src/program/realtime_interface.cpp)
target_link_libraries(realtime_interface dst)
##rosbuild_link_boost(realtime_interface filesystem program_options)
set_target_properties(realtime_interface PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")

cs_add_executable(translate_sequence src/program/translate_sequence.cpp)
target_link_libraries(translate_sequence dst)
set_target_properties(translate_sequence PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")

cs_add_executable(evaluate src/program/evaluate.cpp)
target_link_libraries(evaluate dst)
set_target_properties(evaluate PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")

cs_add_executable(generate_random_weights src/program/generate_random_weights.cpp)
target_link_libraries(generate_random_weights)
##rosbuild_link_boost(generate_random_weights filesystem program_options)
set_target_properties(generate_random_weights PROPERTIES COMPILE_FLAGS "-Wno-deprecated -Wno-unused-but-set-variable -Wno-unknown-pragmas")

catkin_add_gtest(test_maxflow src/test/test_maxflow.cpp)
target_link_libraries(test_maxflow dst)

cs_export()