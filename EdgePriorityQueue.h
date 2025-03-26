#ifndef EDGE_PRIORITY_QUEUE_H
#define EDGE_PRIORITY_QUEUE_H

namespace graph {

    struct Edge {
        int u, v;
        int weight;
    };

    struct EdgeElement {
        Edge edge;
        int priority; // שווה למשקל הקשת
    };

    class EdgePriorityQueue {
    private:
        EdgeElement* data;
        int capacity;
        int size;

    public:
        EdgePriorityQueue(int capacity);
        ~EdgePriorityQueue();

        void insert(Edge e);
        Edge extractMin();
        bool isEmpty() const;
    };

}

#endif // EDGE_PRIORITY_QUEUE_H
