cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

project(nodes)

find_package(Qt5 5.15 COMPONENTS Widgets CONFIG REQUIRED)

add_executable(nodes
  graphics.cpp
  main.cpp
  node.h
  nodedatamodel.h)

target_link_libraries(nodes
  Qt5::Widgets)
