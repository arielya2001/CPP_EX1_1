#include <iostream>
#include "Graph.h"
using namespace graph;

int main() {
    Graph g(5); // גרף עם 5 קודקודים

    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(3, 4, 2);

    g.print_graph();

    g.removeEdge(1, 3);
    std::cout << "\nאחרי הסרת הקשת (1, 3):\n";
    g.print_graph();

    return 0;
}
