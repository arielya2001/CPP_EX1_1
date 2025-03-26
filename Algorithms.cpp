#include "Algorithms.h"
#include "Queue.h"

namespace graph {

    // === BFS ===
    Graph Algorithms::bfs(const Graph& g, int source) {
        int n = g.getNumVertices();
        Graph bfsTree(n);

        bool* visited = new bool[n]();
        Queue q;
        q.enqueue(source);
        visited[source] = true;

        while (!q.isEmpty()) {
            int u = q.dequeue();

            Neighbor* current = g.getNeighbors(u);
            while (current != nullptr) {
                int v = current->id;
                if (!visited[v]) {
                    visited[v] = true;
                    bfsTree.addDirectedEdge(u, v, current->weight);
                    q.enqueue(v);
                }
                current = current->next;
            }
        }

        delete[] visited;
        return bfsTree;
    }

    // DFS - פונקציית עזר רקורסיבית
    void dfs_visit(const Graph& g, Graph& dfsTree, bool* visited, int u) {
        visited[u] = true;

        Neighbor* current = g.getNeighbors(u);
        while (current != nullptr) {
            int v = current->id;
            if (!visited[v]) {
                dfsTree.addDirectedEdge(u, v, current->weight);
                dfs_visit(g, dfsTree, visited, v);
            }
            current = current->next;
        }
    }

    // DFS - פונקציה ראשית
    Graph Algorithms::dfs(const Graph& g, int source) {
        int n = g.getNumVertices();
        Graph dfsTree(n);
        bool* visited = new bool[n]();

        dfs_visit(g, dfsTree, visited, source);

        // המשך לרכיבים לא קשורים
        for (int u = 0; u < n; ++u) {
            if (!visited[u]) {
                dfs_visit(g, dfsTree, visited, u);
            }
        }

        delete[] visited;
        return dfsTree;
    }

}
