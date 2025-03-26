#include "Graph.h"
#include "Algorithms.h"
#include <iostream>

using namespace graph;

int main() {
    // גרף של משולש (3 קודקודים מחוברים ביניהם)
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    std::cout << "Original graph:\n";
    g.print_graph();

    // BFS
    Graph bfsTree = Algorithms::bfs(g, 0);
    std::cout << "\nBFS tree from node 0:\n";
    bfsTree.print_graph();

    // DFS
    Graph dfsTree = Algorithms::dfs(g, 0);
    std::cout << "\nDFS tree (or forest) from node 0:\n";
    dfsTree.print_graph();

    return 0;
}
