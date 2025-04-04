/*
Mail - ariel.yaacobi@msmail.ariel.ac.il
*/
#include "EdgePriorityQueue.h"
#include <stdexcept>

namespace graph {

    EdgePriorityQueue::EdgePriorityQueue(int capacity)
        : capacity(capacity), size(0) {
        if (capacity <= 0)
            throw std::invalid_argument("EdgePriorityQueue capacity must be positive.");
        data = new EdgeElement[capacity];
    }

    EdgePriorityQueue::~EdgePriorityQueue() {
        delete[] data;
    }

    void EdgePriorityQueue::insert(Edge e) {
        if (size == capacity)
            throw std::runtime_error("EdgePriorityQueue overflow");

        data[size].edge = e;
        data[size].priority = e.weight;
        size++;
    }

    Edge EdgePriorityQueue::extractMin() {
        if (isEmpty())
            throw std::runtime_error("EdgePriorityQueue underflow");

        int minIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (data[i].priority < data[minIndex].priority) {
                minIndex = i;
            }
        }

        Edge minEdge = data[minIndex].edge;
        data[minIndex] = data[size - 1]; // Swap with last
        size--;
        return minEdge;
    }

    bool EdgePriorityQueue::isEmpty() const {
        return size == 0;
    }

} // namespace graph
