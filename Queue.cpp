/*
ID - 318727187
*/
#include "Queue.h"
#include <stdexcept>

namespace graph {

    Queue::Queue(int capacity)
        : capacity(capacity), front(0), rear(0), size(0) {
        data = new int[capacity];
    }

    Queue::~Queue() {
        delete[] data;
    }

    void Queue::enqueue(int value) {
        if (size == capacity)
            throw std::runtime_error("Queue overflow");

        data[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    int Queue::dequeue() {
        if (isEmpty())
            throw std::runtime_error("Queue underflow");

        int value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    bool Queue::isEmpty() const {
        return size == 0;
    }

}
