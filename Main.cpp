/*
Mail - ariel.yaacobi@msmail.ariel.ac.il
*/
#include "Graph.h"
#include "Algorithms.h"
#include <iostream>

using namespace graph;

void runAllAlgorithms(const Graph& g, const std::string& name, int source = 0) {
    std::cout << "\n=== " << name << " ===\n";
    std::cout << "Original Graph:" << std::endl;
    g.print_graph();

    std::cout << "\n--- BFS (from " << source << ") ---\n";
    Graph bfsTree = Algorithms::bfs(g, source);
    bfsTree.print_graph();

    std::cout << "\n--- DFS (from " << source << ") ---\n";
    Graph dfsTree = Algorithms::dfs(g, source);
    dfsTree.print_graph();

    std::cout << "\n--- Dijkstra (from " << source << ") ---\n";
    Graph dijkstraTree = Algorithms::dijkstra(g, source);
    dijkstraTree.print_graph();

    std::cout << "\n--- Prim ---\n";
    Graph primTree = Algorithms::prim(g);
    primTree.print_graph();

    std::cout << "\n--- Kruskal ---\n";
    Graph kruskalTree = Algorithms::kruskal(g);
    kruskalTree.print_graph();
}

int main() {
    // גרף קשיר
    Graph connectedGraph(5);
    connectedGraph.addEdge(0, 1, 2);
    connectedGraph.addEdge(0, 2, 4);
    connectedGraph.addEdge(1, 2, 1);
    connectedGraph.addEdge(1, 3, 7);
    connectedGraph.addEdge(2, 4, 3);
    connectedGraph.addEdge(3, 4, 1);
    runAllAlgorithms(connectedGraph, "Connected Graph", 0);

    // גרף לא קשיר
    Graph disconnectedGraph(6);
    disconnectedGraph.addEdge(0, 1);
    disconnectedGraph.addEdge(0, 2);
    disconnectedGraph.addEdge(3, 4);
    runAllAlgorithms(disconnectedGraph, "Disconnected Graph", 0);

    // גרף עם הרבה קודקודים
    Graph largerGraph(8);
    largerGraph.addEdge(0, 1, 3);
    largerGraph.addEdge(1, 2, 5);
    largerGraph.addEdge(2, 3, 2);
    largerGraph.addEdge(3, 4, 4);
    largerGraph.addEdge(4, 5, 1);
    largerGraph.addEdge(5, 6, 6);
    largerGraph.addEdge(6, 7, 2);
    largerGraph.addEdge(0, 7, 9);
    runAllAlgorithms(largerGraph, "Large Graph", 0);

    // גרף עם מעגל
    Graph cyclicGraph(4);
    cyclicGraph.addEdge(0, 1);
    cyclicGraph.addEdge(1, 2);
    cyclicGraph.addEdge(2, 3);
    cyclicGraph.addEdge(3, 0); // סוגר מעגל
    runAllAlgorithms(cyclicGraph, "Cyclic Graph", 0);

    return 0;
}
