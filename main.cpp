#include "Graph.h"
#include "Algorithms.h"
#include <iostream>

using namespace graph;

int main() {
    // יצירת גרף עם 3 קודקודים
    Graph g(3);

    // הוספת קשתות עם משקלים
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);

    std::cout << "Original graph:\n";
    g.print_graph();

    Graph mst = Algorithms::prim(g);

    std::cout << "\nMinimum Spanning Tree (Prim):\n";
    mst.print_graph();

    return 0;
}
