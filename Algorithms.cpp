/*
Mail - ariel.yaacobi@msmail.ariel.ac.il
*/
#include "Algorithms.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "UnionFind.h"
#include "EdgePriorityQueue.h"
#include <limits>
#include <stdexcept>

namespace graph {

    // === BFS ===
    Graph Algorithms::bfs(const Graph& g, int source) {
        int n = g.getNumVertices();
        if (n == 0)
            throw std::invalid_argument("bfs: Graph is empty.");
        if (source < 0 || source >= n)
            throw std::invalid_argument("BFS: Source vertex out of range.");

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
        if (n == 0)
            throw std::invalid_argument("dfs: Graph is empty.");
        if (source < 0 || source >= n)
            throw std::invalid_argument("DFS: Source vertex out of range.");

        Graph dfsTree(n);
        bool* visited = new bool[n]();

        dfs_visit(g, dfsTree, visited, source);

        for (int u = 0; u < n; ++u) {
            if (!visited[u]) {
                dfs_visit(g, dfsTree, visited, u);
            }
        }

        delete[] visited;
        return dfsTree;
    }

    Graph Algorithms::dijkstra(const Graph& g, int source) {
        int n = g.getNumVertices();
        if (n == 0)
            throw std::invalid_argument("dijkstra: Graph is empty.");
        if (source < 0 || source >= n)
            throw std::invalid_argument("Dijkstra: Source vertex out of range.");

        Graph shortestPaths(n);
        const int INF = std::numeric_limits<int>::max();
        int* distance = new int[n];
        int* parent = new int[n];

        for (int i = 0; i < n; ++i) {
            distance[i] = INF;
            parent[i] = -1;
        }
        distance[source] = 0;

        PriorityQueue pq(n);
        for (int i = 0; i < n; ++i) {
            pq.insert(i, distance[i]);
        }

        while (!pq.isEmpty()) {
            int u = pq.extractMin();
            Neighbor* current = g.getNeighbors(u);
            while (current != nullptr) {
                int v = current->id;
                int w = current->weight;

                if (w < 0) {
                    delete[] distance;
                    delete[] parent;
                    throw std::invalid_argument("Dijkstra: Negative edge weight detected.");
                }


                if (distance[u] != INF && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    parent[v] = u;
                    pq.decreaseKey(v, distance[v]);
                }
                current = current->next;
            }
        }

        for (int v = 0; v < n; ++v) {
            if (parent[v] != -1) {
                int u = parent[v];
                int w = distance[v] - distance[u];
                shortestPaths.addDirectedEdge(u, v, w);
            }
        }

        delete[] distance;
        delete[] parent;
        return shortestPaths;
    }

    Graph Algorithms::prim(const Graph& g) {
        int n = g.getNumVertices();
        if (n == 0)
            throw std::invalid_argument("Kruskal: Graph is empty.");
        Graph mst(n);

        const int INF = std::numeric_limits<int>::max();
        int* key = new int[n];
        int* parent = new int[n];
        bool* inMST = new bool[n]();

        for (int i = 0; i < n; ++i) {
            key[i] = INF;
            parent[i] = -1;
        }
        key[0] = 0;

        PriorityQueue pq(n);
        for (int i = 0; i < n; ++i) {
            pq.insert(i, key[i]);
        }

        while (!pq.isEmpty()) {
            int u = pq.extractMin();
            inMST[u] = true;

            Neighbor* current = g.getNeighbors(u);
            while (current != nullptr) {
                int v = current->id;
                int w = current->weight;
                if (!inMST[v] && w < key[v]) {
                    parent[v] = u;
                    key[v] = w;
                    pq.decreaseKey(v, w);
                }
                current = current->next;
            }
        }

        for (int v = 0; v < n; ++v) {
            if (parent[v] != -1) {
                int u = parent[v];
                int w = key[v];
                mst.addEdge(u, v, w);
            }
        }

        delete[] key;
        delete[] parent;
        delete[] inMST;
        return mst;
    }

    Graph Algorithms::kruskal(const Graph& g) {
        int n = g.getNumVertices();
        if (n == 0)
            throw std::invalid_argument("Kruskal: Graph is empty.");
        Graph mst(n);

        int maxEdges = 0;
        for (int u = 0; u < n; ++u) {
            Neighbor* current = g.getNeighbors(u);
            while (current != nullptr) {
                if (u < current->id) maxEdges++;
                current = current->next;
            }
        }
        if (maxEdges == 0) return mst;

        EdgePriorityQueue pq(maxEdges);
        for (int u = 0; u < n; ++u) {
            Neighbor* current = g.getNeighbors(u);
            while (current != nullptr) {
                int v = current->id;
                int w = current->weight;
                if (u < v) {
                    pq.insert({u, v, w});
                }
                current = current->next;
            }
        }

        UnionFind uf(n);

        while (!pq.isEmpty()) {
            Edge e = pq.extractMin();
            int u = e.u;
            int v = e.v;
            int w = e.weight;

            if (uf.find(u) != uf.find(v)) {
                mst.addEdge(u, v, w);
                uf.unionSets(u, v);
            }
        }

        return mst;
    }

} // namespace graph