// PriorityQueue.cpp
#include "PriorityQueue.h"
#include <stdexcept>

namespace graph {

    PriorityQueue::PriorityQueue(int capacity)
        : capacity(capacity), size(0) {
        elements = new int[capacity];
        priorities = new int[capacity];
    }

    PriorityQueue::~PriorityQueue() {
        delete[] elements;
        delete[] priorities;
    }

    void PriorityQueue::insert(int element, int priority) {
        if (size == capacity)
            throw std::runtime_error("PriorityQueue overflow");

        elements[size] = element;
        priorities[size] = priority;
        size++;
    }

    int PriorityQueue::extractMin() {
        if (isEmpty())
            throw std::runtime_error("PriorityQueue underflow");

        int minIndex = 0;
        for (int i = 1; i < size; ++i) {
            if (priorities[i] < priorities[minIndex]) {
                minIndex = i;
            }
        }

        int minElement = elements[minIndex];

        // הזזת האלמנט האחרון למקום שהתפנה
        elements[minIndex] = elements[size - 1];
        priorities[minIndex] = priorities[size - 1];
        size--;

        return minElement;
    }

    void PriorityQueue::decreaseKey(int element, int newPriority) {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == element && priorities[i] > newPriority) {
                priorities[i] = newPriority;
                return;
            }
        }
    }

    bool PriorityQueue::isEmpty() const {
        return size == 0;
    }

    bool PriorityQueue::contains(int element) const {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == element)
                return true;
        }
        return false;
    }

} // namespace graph
