#include "Graph.h"
#include "Algorithms.h"
#include <iostream>

using namespace graph;

int main() {
    Graph g(3);

    // הוספת קשתות
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 3);
    g.addEdge(0, 2, 4);

    std::cout << "Original graph:\n";
    g.print_graph();

    // הרצת קרוסקל
    Graph mst = Algorithms::kruskal(g);

    std::cout << "\nMinimum Spanning Tree (Kruskal):\n";
    mst.print_graph();

    return 0;
}
