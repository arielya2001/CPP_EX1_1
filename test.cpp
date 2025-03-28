#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.h"
#include "Algorithms.h"
#include "PriorityQueue.h"
#include "EdgePriorityQueue.h"
#include "UnionFind.h"
#include <stdexcept>

using namespace graph;

bool hasIncomingEdgeTo(const Graph& g, int target) {
    for (int u = 0; u < g.getNumVertices(); ++u) {
        Neighbor* curr = g.getNeighbors(u);
        while (curr != nullptr) {
            if (curr->id == target) return true;
            curr = curr->next;
        }
    }
    return false;
}

TEST_CASE("Graph basic operations") {
    Graph g(4);

    CHECK_NOTHROW(g.addEdge(0, 1));
    CHECK_NOTHROW(g.addEdge(2, 3));
    CHECK(g.getNeighborCount(0) == 1);
    CHECK(g.getNeighborCount(1) == 1);
    CHECK(g.getNeighborCount(2) == 1);
    CHECK(g.getNeighborCount(3) == 1);

    CHECK_THROWS_AS(g.removeEdge(0, 2), std::runtime_error);
    CHECK_NOTHROW(g.removeEdge(0, 1));
    CHECK(g.getNeighborCount(0) == 0);
    CHECK(g.getNeighborCount(1) == 0);

    g.addDirectedEdge(0, 1, 5);
    CHECK(g.getNeighborCount(0) == 1);
    CHECK(g.getNeighborCount(1) == 0);

    Neighbor* n = g.getNeighbors(0);
    REQUIRE(n != nullptr);
    CHECK(n->id == 1);
    CHECK(n->weight == 5);
    CHECK(n->next == nullptr);
}

TEST_CASE("Graph with isolated and empty vertices") {
    SUBCASE("Empty graph") {
        Graph g(0);
        CHECK(g.getNumVertices() == 0);

        CHECK_THROWS_AS(Algorithms::bfs(g, 0), std::invalid_argument);
        CHECK_THROWS_AS(Algorithms::dfs(g, 0), std::invalid_argument);
        CHECK_THROWS_AS(Algorithms::dijkstra(g, 0), std::invalid_argument);
        CHECK_THROWS_AS(Algorithms::prim(g), std::invalid_argument);
        CHECK_THROWS_AS(Algorithms::kruskal(g), std::invalid_argument);
    }


    SUBCASE("Graph with isolated vertices") {
        Graph g(3);  // כל הקודקודים מבודדים
        CHECK(g.getNeighborCount(0) == 0);
        CHECK(g.getNeighborCount(1) == 0);
        CHECK(g.getNeighborCount(2) == 0);

        CHECK_NOTHROW(Algorithms::bfs(g, 0));
        CHECK_NOTHROW(Algorithms::dfs(g, 0));
        CHECK_NOTHROW(Algorithms::dijkstra(g, 0));
        CHECK_NOTHROW(Algorithms::prim(g));
        CHECK_NOTHROW(Algorithms::kruskal(g));
    }

    SUBCASE("Graph with one vertex and no edges") {
        Graph g(1);
        CHECK(g.getNeighborCount(0) == 0);

        CHECK_NOTHROW(Algorithms::bfs(g, 0));
        CHECK_NOTHROW(Algorithms::dfs(g, 0));
        CHECK_NOTHROW(Algorithms::dijkstra(g, 0));
        CHECK_NOTHROW(Algorithms::prim(g));
        CHECK_NOTHROW(Algorithms::kruskal(g));
    }
}

TEST_CASE("BFS and DFS on disconnected graph") {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(2, 3);

    Graph bfsTree = Algorithms::bfs(g, 0);
    CHECK(hasIncomingEdgeTo(bfsTree, 1));
    CHECK_FALSE(hasIncomingEdgeTo(bfsTree, 2));
    CHECK_FALSE(hasIncomingEdgeTo(bfsTree, 3));

    Graph dfsTree = Algorithms::dfs(g, 0);
    CHECK(hasIncomingEdgeTo(dfsTree, 1));
    CHECK(hasIncomingEdgeTo(dfsTree, 3));
}

TEST_CASE("Dijkstra throws on negative weights") {
    Graph g(3);
    g.addEdge(0, 1, -5);
    g.addEdge(1, 2, 3);
    CHECK_THROWS_AS(Algorithms::dijkstra(g, 0), std::invalid_argument);
}

TEST_CASE("Invalid source vertex") {
    Graph g(3);
    CHECK_THROWS_AS(Algorithms::bfs(g, 5), std::invalid_argument);
    CHECK_THROWS_AS(Algorithms::dfs(g, -1), std::invalid_argument);
    CHECK_THROWS_AS(Algorithms::dijkstra(g, 3), std::invalid_argument);
}

TEST_CASE("Kruskal and Prim basic correctness") {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 4);

    Graph kruskalTree = Algorithms::kruskal(g);
    Graph primTree = Algorithms::prim(g);

    int totalEdgesKruskal = 0;
    for (int i = 0; i < 4; ++i)
        totalEdgesKruskal += kruskalTree.getNeighborCount(i);
    CHECK(totalEdgesKruskal / 2 == 3);

    int totalEdgesPrim = 0;
    for (int i = 0; i < 4; ++i)
        totalEdgesPrim += primTree.getNeighborCount(i);
    CHECK(totalEdgesPrim / 2 == 3);
}

TEST_CASE("PriorityQueue operations") {
    PriorityQueue pq(5);
    pq.insert(0, 10);
    pq.insert(1, 5);
    pq.insert(2, 8);

    CHECK(pq.contains(1));
    CHECK(pq.extractMin() == 1);
    CHECK(pq.contains(2));
    pq.decreaseKey(2, 3);
    CHECK(pq.extractMin() == 2);
    CHECK_THROWS_AS(pq.decreaseKey(3, 1), std::runtime_error);

    pq.extractMin();
    CHECK(pq.isEmpty());
    CHECK_THROWS_AS(pq.extractMin(), std::runtime_error);
}

TEST_CASE("EdgePriorityQueue operations") {
    EdgePriorityQueue epq(3);
    epq.insert({0, 1, 5});
    epq.insert({2, 3, 2});
    epq.insert({1, 3, 4});

    Edge e = epq.extractMin();
    CHECK((e.u == 2 && e.v == 3 && e.weight == 2));
    e = epq.extractMin();
    CHECK((e.u == 1 && e.v == 3 && e.weight == 4));
    e = epq.extractMin();
    CHECK((e.u == 0 && e.v == 1 && e.weight == 5));
    CHECK(epq.isEmpty());
    CHECK_THROWS_AS(epq.extractMin(), std::runtime_error);
}

TEST_CASE("UnionFind operations") {
    UnionFind uf(5);
    CHECK(uf.find(0) == 0);
    uf.unionSets(0, 1);
    CHECK(uf.find(0) == uf.find(1));

    uf.unionSets(2, 3);
    uf.unionSets(3, 4);
    CHECK(uf.find(2) == uf.find(4));

    uf.unionSets(0, 4);
    for (int i = 0; i < 5; ++i)
        CHECK(uf.find(i) == uf.find(0));
}
//NOW JUST A REGULAR TEST FOR CONNECTED GRAPH!

TEST_CASE("Run all algorithms on a regular connected graph") {
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, 2);
    g.addEdge(5, 0, 7);
    g.addEdge(1, 4, 6);

    int source = 2;

    SUBCASE("BFS from vertex 2") {
        Graph bfsTree = Algorithms::bfs(g, source);
        // מצפים לכל הקודקודים להיות מחוברים כי הגרף מחובר
        for (int v = 0; v < g.getNumVertices(); ++v) {
            if (v != source) {
                CHECK(hasIncomingEdgeTo(bfsTree, v));
            }
        }
    }

    SUBCASE("DFS from vertex 2") {
        Graph dfsTree = Algorithms::dfs(g, source);
        // כמו ב־BFS, מצפים לכל הקודקודים להיות מחוברים
        for (int v = 0; v < g.getNumVertices(); ++v) {
            if (v != source) {
                CHECK(hasIncomingEdgeTo(dfsTree, v));
            }
        }
    }

    SUBCASE("Dijkstra from vertex 2") {
        Graph dijkstraTree = Algorithms::dijkstra(g, source);
        // לוודא שיש קשתות מהתוצאה
        int count = 0;
        for (int v = 0; v < g.getNumVertices(); ++v)
            count += dijkstraTree.getNeighborCount(v);
        CHECK(count > 0);
    }

    SUBCASE("Prim's algorithm") {
        Graph primTree = Algorithms::prim(g);
        int edgeCount = 0;
        for (int v = 0; v < g.getNumVertices(); ++v)
            edgeCount += primTree.getNeighborCount(v);
        CHECK(edgeCount / 2 == g.getNumVertices() - 1);  // עץ פורש מינימלי
    }

    SUBCASE("Kruskal's algorithm") {
        Graph kruskalTree = Algorithms::kruskal(g);
        int edgeCount = 0;
        for (int v = 0; v < g.getNumVertices(); ++v)
            edgeCount += kruskalTree.getNeighborCount(v);
        CHECK(edgeCount / 2 == g.getNumVertices() - 1);  // עץ פורש מינימלי
    }
}
