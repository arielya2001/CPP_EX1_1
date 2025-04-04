/*
Mail - ariel.yaacobi@msmail.ariel.ac.il
*/
#include "Graph.h"
#include <iostream>
#include <stdexcept>

namespace graph {

Graph::Graph(int numVertices) {
    if (numVertices < 0)
        throw std::invalid_argument("Graph size cannot be negative.");

    this->numVertices = numVertices;
    adjacencyList = new Neighbor*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjacencyList[i] = nullptr;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        Neighbor* current = adjacencyList[i];
        while (current != nullptr) {
            Neighbor* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjacencyList;
}

void Graph::addToList(int vertex, int neighbor, int weight) {
    if (vertex < 0 || vertex >= numVertices || neighbor < 0 || neighbor >= numVertices)
        throw std::out_of_range("addToList: vertex or neighbor out of bounds.");

    Neighbor* newNeighbor = new Neighbor{neighbor, weight, adjacencyList[vertex]};
    adjacencyList[vertex] = newNeighbor;
}

void Graph::removeFromList(int vertex, int neighbor) {
    if (vertex < 0 || vertex >= numVertices || neighbor < 0 || neighbor >= numVertices)
        throw std::out_of_range("removeFromList: vertex or neighbor out of bounds.");

    Neighbor* current = adjacencyList[vertex];
    Neighbor* prev = nullptr;

    while (current != nullptr) {
        if (current->id == neighbor) {
            if (prev == nullptr)
                adjacencyList[vertex] = current->next;
            else
                prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

bool Graph::edgeExists(int vertex, int neighbor) const {
    if (vertex < 0 || vertex >= numVertices || neighbor < 0 || neighbor >= numVertices)
        throw std::out_of_range("edgeExists: vertex or neighbor out of bounds.");

    Neighbor* current = adjacencyList[vertex];
    while (current != nullptr) {
        if (current->id == neighbor)
            return true;
        current = current->next;
    }
    return false;
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
        Neighbor* current = adjacencyList[i];
        while (current != nullptr) {
            std::cout << "(" << current->id << ", w=" << current->weight << ") ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}

int Graph::getNumVertices() const {
    return numVertices;
}

Neighbor* Graph::getNeighbors(int vertex) const {
    if (vertex < 0 || vertex >= numVertices)
        throw std::out_of_range("getNeighbors: vertex out of bounds.");
    return adjacencyList[vertex];
}

int Graph::getNeighborCount(int vertex) const {
    if (vertex < 0 || vertex >= numVertices)
        throw std::out_of_range("getNeighborCount: vertex out of bounds.");

    int count = 0;
    Neighbor* current = adjacencyList[vertex];
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void Graph::addDirectedEdge(int src, int dst, int weight) {
    addToList(src, dst, weight);
}

} // namespace graph
