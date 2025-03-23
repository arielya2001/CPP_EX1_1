#ifndef GRAPH_H
#define GRAPH_H

namespace graph {

    struct Neighbor {
        int id;
        int weight;
    };

    class Graph {
    private:
        int numVertices;
        Neighbor** adjacencyList;
        int* listSizes;

    public:
        Graph(int numVertices); //בנאי המחלקה
        ~Graph(); //destructor

        void addEdge(int src, int dst, int weight = 1);
        void removeEdge(int src, int dst);
        void print_graph() const;
        int getNumVertices() const;
        Neighbor* getNeighbors(int vertex) const;
        int getNeighborCount(int vertex) const;
        void addDirectedEdge(int src, int dst, int weight = 1);

    private: //פונקציות פנימיות - רלוונטיות לכל פונקציות חיצונית
        void addToList(int vertex, int neighbor, int weight);
        void removeFromList(int vertex, int neighbor);
        bool edgeExists(int vertex, int neighbor) const;
    };

}

#endif // GRAPH_H
