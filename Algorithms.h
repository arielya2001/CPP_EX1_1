/*
Mail - ariel.yaacobi@msmail.ariel.ac.il
*/
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.h"

namespace graph {

    class Algorithms {
    public:
        static Graph bfs(const Graph& g, int source);
        static Graph dfs(const Graph& g, int source);
        static Graph dijkstra(const Graph& g, int source);
        static Graph prim(const Graph& g);
        static Graph kruskal(const Graph& g);
    };

}

#endif // ALGORITHMS_H
