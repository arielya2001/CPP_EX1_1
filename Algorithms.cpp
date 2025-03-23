#include "Algorithms.h"
#include "Queue.h"

namespace graph {

    Graph Algorithms::bfs(const Graph& g, int source) {
        int n = g.getNumVertices();
        Graph bfsTree(n);

        bool* visited = new bool[n](); //
        Queue q;
        q.enqueue(source);
        visited[source] = true;

        while (!q.isEmpty()) {
            int u = q.dequeue();

            Neighbor* neighbors = g.getNeighbors(u);
            int neighborCount = g.getNeighborCount(u);

            for (int i = 0; i < neighborCount; ++i) {
                int v = neighbors[i].id;
                if (!visited[v]) {
                    visited[v] = true;
                    bfsTree.addEdge(u, v, neighbors[i].weight); // שומר את המשקל המקורי
                    q.enqueue(v);
                }
            }
        }

        delete[] visited;
        return bfsTree;
    }

}
