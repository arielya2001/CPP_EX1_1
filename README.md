# Graph Algorithms in C++
# Mail - ariel.yaacobi@msmail.ariel.ac.il
## Overview

This project implements a graph structure and several classical graph algorithms in C++, without using STL containers (as required by the assignment).
The project includes unit tests using the `doctest` framework, and supports memory leak checks using `valgrind`.

---

## Project Structure

```
.
├── Graph.h / Graph.cpp           # Graph class with adjacency list representation  
├── Algorithms.h / Algorithms.cpp # Static class with BFS, DFS, Dijkstra, Prim, Kruskal  
├── Queue.h / Queue.cpp           # Custom queue used in BFS  
├── PriorityQueue.h / .cpp        # Min-priority queue for Dijkstra and Prim    
├── UnionFind.h / .cpp            # Union-Find structure for Kruskal  
├── Main.cpp                      # Demo code that runs the algorithms on sample graphs  
├── test.cpp                      # Unit tests using doctest  
├── Makefile                      # Compilation, testing, valgrind, cleanup  
└── README.md                     # This file  
```

---

## Classes and Their Roles

### `Graph`
- Uses adjacency list (`Neighbor*`) for storing undirected or directed weighted edges(using Struct)
- Supports adding/removing edges and querying neighbors.

### `Algorithms` (Static)
Implements the following algorithms:
- `bfs(Graph, source)`
- `dfs(Graph, source)`
- `dijkstra(Graph, source)`
- `prim(Graph)`
- `kruskal(Graph)`

Each algorithm throws `std::invalid_argument` when given an invalid input (e.g., invalid source vertex, negative weights, or empty graph).

### `Queue`
- Implements a basic queue using a linked list.
- Used by BFS algorithm.

### `PriorityQueue`
- Min-priority queue for integers (vertices).
- Used in Dijkstra and Prim algorithms.

### `UnionFind`
- Disjoint-set structure with path compression and union by rank.
- Detects cycles in Kruskal’s algorithm.

---

## Unit Testing

Tests are located in `test.cpp` using [doctest](https://github.com/doctest/doctest).

### To run the tests:
```
make test  
./graph_test
```

Tests include:
- Basic graph operations
- Validity and correctness of each algorithm
- Edge cases such as empty graphs, disconnected graphs, and isolated vertices
- Exception handling for invalid inputs

---

## Memory Leak Detection

Memory is manually managed (new/delete). Use `valgrind` to check for leaks.

### To check for memory leaks:
```
make valgrind
```

Valgrind will run both the test executable and the demo (`graph_demo`) and print a memory usage summary.

---

## Running the Demo

The demo file `Main.cpp` shows usage of all algorithms on various example graphs.

### To build and run:
```
make Main  
./graph_demo
```

---

## Clean Build Files

To remove all compiled output files and object files:
```
make clean
```

---

## Notes

- STL containers were avoided intentionally, using custom data structures only.
- Algorithms are designed with robustness in mind.
- Valgrind results confirm no memory leaks.
- Proper exception handling is in place for all critical input checks.

---

## Author & Date

- Developed by: Ariel Ya'acobi
- Assignment: Systems programming 2 – Graph Algorithms (CPP_EX1_1)  
- Date: April 2025
