/*
Mail - ariel.yaacobi@msmail.ariel.ac.il
*/
#ifndef GRAPH_H
#define GRAPH_H

namespace graph {

    struct Neighbor {
        int id;
        int weight;
        Neighbor* next = nullptr;

        Neighbor(int id, int weight, Neighbor* next = nullptr)
            : id(id), weight(weight), next(next) {}
    };

    class Graph {
    private:
        int numVertices;
        Neighbor** adjacencyList; // כל קודקוד מצביע לראש רשימת שכנים מקושרת

    public:
        Graph(int numVertices);
        ~Graph();

        void addEdge(int src, int dst, int weight = 1);
        void removeEdge(int src, int dst);
        void print_graph() const;
        int getNumVertices() const;
        Neighbor* getNeighbors(int vertex) const;
        int getNeighborCount(int vertex) const;
        void addDirectedEdge(int src, int dst, int weight = 1);

    private:
        void addToList(int vertex, int neighbor, int weight);
        void removeFromList(int vertex, int neighbor);
        bool edgeExists(int vertex, int neighbor) const;
    };

}

#endif // GRAPH_H
