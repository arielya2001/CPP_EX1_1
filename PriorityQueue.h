/*
Mail - ariel.yaacobi@msmail.ariel.ac.il
*/
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

namespace graph {

    struct Element {
        int vertex;
        int priority;
    };

    class PriorityQueue {
    private:
        Element* data;
        int capacity;
        int size;

    public:
        PriorityQueue(int capacity);
        ~PriorityQueue();

        void insert(int vertex, int priority);
        int extractMin();
        void decreaseKey(int vertex, int newPriority);
        bool isEmpty() const;
        bool contains(int vertex) const;
    };

}

#endif // PRIORITY_QUEUE_H
