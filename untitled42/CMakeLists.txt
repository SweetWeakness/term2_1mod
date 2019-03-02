cmake_minimum_required(VERSION 3.12)
project(untitled42)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled42 main.cpp ListGraph.cpp ListGraph.h MatrixGraph.cpp MatrixGraph.h SetGraph.cpp SetGraph.h ArcGraph.cpp ArcGraph.h IGraph.h)