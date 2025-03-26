#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

namespace graph {

    class PriorityQueue {
    private:
        int* elements;    // מערך של מזהי קודקודים
        int* priorities;  // מערך של ערכי עדיפות (מרחקים)
        int capacity;
        int size;

    public:
        PriorityQueue(int capacity);
        ~PriorityQueue();

        void insert(int element, int priority);
        int extractMin();
        void decreaseKey(int element, int newPriority);
        bool isEmpty() const;
        bool contains(int element) const;
    };

}

#endif // PRIORITY_QUEUE_H
