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

            Neighbor* neighbors = g.getNeighbors(u);
            int neighborCount = g.getNeighborCount(u);

            for (int i = 0; i < neighborCount; ++i) {
                int v = neighbors[i].id;
                if (!visited[v]) {
                    visited[v] = true;
                    bfsTree.addDirectedEdge(u, v, neighbors[i].weight); // עץ BFS: צלע חד-כיוונית
                    q.enqueue(v);
                }
            }
        }

        delete[] visited;
        return bfsTree;
    }

    // פונקציה עזר רקורסיבית - מבקרת את הצומת u ואת שכניו
    void dfs_visit(const Graph& g, Graph& dfsTree, bool* visited, int u) {
        visited[u] = true; // סמן את הקודקוד כבוקר

        Neighbor* neighbors = g.getNeighbors(u); // קבל את רשימת השכנים של u
        int neighborCount = g.getNeighborCount(u); // קבל את מספר השכנים של u

        for (int i = neighborCount - 1; i >= 0; --i) {
            int v = neighbors[i].id;
            if (!visited[v]) {
                dfsTree.addDirectedEdge(u, v, neighbors[i].weight);
                dfs_visit(g, dfsTree, visited, v);
            }
        }

    }

    // פונקציית DFS ראשית
    Graph Algorithms::dfs(const Graph& g, int source) {
        int n = g.getNumVertices(); // מספר הקודקודים בגרף
        Graph dfsTree(n); // צור עץ DFS ריק
        bool* visited = new bool[n](); // מערך לביקורי קודקודים (מאותחל ל-false)

        // בצע DFS מהקודקוד ההתחלתי
        dfs_visit(g, dfsTree, visited, source);

        // עבור על כל הקודקודים כדי לטפל ברכיבים לא מחוברים
        for (int u = 0; u < n; ++u) {
            if (!visited[u]) { // אם הקודקוד לא בוקר
                dfs_visit(g, dfsTree, visited, u); // בצע DFS מהקודקוד
            }
        }

        delete[] visited; // שחרר את הזיכרון של מערך הביקורים
        return dfsTree; // החזר את עץ ה-DFS
    }

}
hello