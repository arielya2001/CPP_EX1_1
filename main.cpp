#include "Graph.h"
#include "Algorithms.h"
#include <iostream>

using namespace graph;

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    std::cout << "Original graph:\n";
    g.print_graph();

    Graph tree = Algorithms::dfs(g, 0);
    std::cout << "\nDFS result (tree or forest):\n";
    tree.print_graph();



    return 0;
}
