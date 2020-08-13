cmake_minimum_required(VERSION 3.10)

project(rrt)

#set(CMAKE_CXX_STANDARD 11)
add_definitions(-std=c++17)
#add_compile_options("-std=libc++")

find_package(OpenCV 4.1 REQUIRED)


include_directories(
  include
  ${OpenCV_INCLUDE_DIRS}
)

link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

add_executable(quadtree src/main src/quadtree.cpp)
target_link_libraries(quadtree vizquad)


add_library(vizquad src/visualize.cpp)
target_link_libraries(vizquad ${OpenCV_LIBRARIES})
