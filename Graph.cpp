#include "Graph.h"
#include <iostream>
#include <stdexcept>

namespace graph {

Graph::Graph(int numVertices){
    this->numVertices = numVertices;
    adjacencyList = new int*[numVertices];
    listSizes = new int[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjacencyList[i] = nullptr;
        listSizes[i] = 0;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i)
        delete[] adjacencyList[i];
    delete[] adjacencyList;
    delete[] listSizes;
}

void Graph::addEdge(int src, int dst, int weight) {
    addToList(src, dst, weight);
    addToList(dst, src, weight); // כי הגרף לא מכוון
}

void Graph::removeEdge(int src, int dst) {
    if (!edgeExists(src, dst))
        throw std::runtime_error("Edge does not exist.");
    removeFromList(src, dst);
    removeFromList(dst, src);
}

void Graph::print_graph() const {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ": ";
        for (int j = 0; j < listSizes[i]; ++j)
            std::cout << adjacencyList[i][j] << " ";
        std::cout << std::endl;
    }
}

// מימוש של פונקציות עזר (תוכל לשפר/לשנות לפי הצורך)
void Graph::addToList(int vertex, int neighbor, int weight) {
    int* newList = new int[listSizes[vertex] + 1];
    for (int i = 0; i < listSizes[vertex]; ++i)
        newList[i] = adjacencyList[vertex][i];
    newList[listSizes[vertex]] = neighbor;
    delete[] adjacencyList[vertex];
    adjacencyList[vertex] = newList;
    listSizes[vertex]++;
}

void Graph::removeFromList(int vertex, int neighbor) {
    int index = -1;
    for (int i = 0; i < listSizes[vertex]; ++i) {
        if (adjacencyList[vertex][i] == neighbor) {
            index = i;
            break;
        }
    }
    if (index == -1) return;
    for (int i = index; i < listSizes[vertex] - 1; ++i)
        adjacencyList[vertex][i] = adjacencyList[vertex][i + 1];
    listSizes[vertex]--;
}

bool Graph::edgeExists(int vertex, int neighbor) const {
    for (int i = 0; i < listSizes[vertex]; ++i)
        if (adjacencyList[vertex][i] == neighbor)
            return true;
    return false;
}

}