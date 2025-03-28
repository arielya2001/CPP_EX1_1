cmake_minimum_required(VERSION 3.31)
project(proj1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj1
        Algorithms.cpp
        Algorithms.h
        doctest.h
        Graph.cpp
        Graph.h
        Main.cpp
        Queue.cpp
        Queue.h
        PriorityQueue.cpp
        PriorityQueue.h
        UnionFind.cpp
        UnionFind.h
        EdgePriorityQueue.cpp
        EdgePriorityQueue.h
        test.cpp
)
