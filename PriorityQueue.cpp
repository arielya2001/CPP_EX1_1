/*
Mail - ariel.yaacobi@msmail.ariel.ac.il
*/
#include "PriorityQueue.h"
#include <stdexcept>

namespace graph {

    PriorityQueue::PriorityQueue(int capacity)
        : capacity(capacity), size(0) {
        if (capacity <= 0)
            throw std::invalid_argument("PriorityQueue capacity must be positive.");
        data = new Element[capacity];
    }

    PriorityQueue::~PriorityQueue() {
        delete[] data;
    }

    void PriorityQueue::insert(int vertex, int priority) {
        if (size == capacity)
            throw std::runtime_error("PriorityQueue overflow");

        if (contains(vertex))
            throw std::invalid_argument("Vertex already exists in PriorityQueue.");

        data[size].vertex = vertex;
        data[size].priority = priority;
        size++;
    }

    int PriorityQueue::extractMin() {
        if (isEmpty())
            throw std::runtime_error("PriorityQueue underflow");

        int minIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (data[i].priority < data[minIndex].priority) {
                minIndex = i;
            }
        }

        int minVertex = data[minIndex].vertex;
        data[minIndex] = data[size - 1];
        size--;
        return minVertex;
    }

    void PriorityQueue::decreaseKey(int vertex, int newPriority) {
        for (int i = 0; i < size; ++i) {
            if (data[i].vertex == vertex) {
                if (newPriority >= data[i].priority)
                    throw std::invalid_argument("New priority is not smaller than current priority.");
                data[i].priority = newPriority;
                return;
            }
        }
        throw std::runtime_error("Vertex not found in PriorityQueue.");
    }

    bool PriorityQueue::isEmpty() const {
        return size == 0;
    }

    bool PriorityQueue::contains(int vertex) const {
        for (int i = 0; i < size; ++i) {
            if (data[i].vertex == vertex)
                return true;
        }
        return false;
    }

} // namespace graph
