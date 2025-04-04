#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"

namespace graph {

    //helper struct only for kruskal
    struct Edge {
        int u, v, weight;
    };

    class Algorithms {
    public:
        static Graph bfs(const Graph& g, int source);
        static Graph dfs(const Graph& g, int source);
        static Graph dijkstra(const Graph& g, int source);
        static Graph prim(const Graph& g);
        static Graph kruskal(const Graph& g);
    };

    Edge* collectEdges(const Graph& g, int& edgeCount);
    void sortEdgesByWeight(Edge* edges, int edgeCount);

}

#endif // ALGORITHMS_H
