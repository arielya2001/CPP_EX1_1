#ifndef UNION_FIND_H
#define UNION_FIND_H

namespace graph {

    class UnionFind {
    private:
        int* parent;
        int* rank;
        int size;

    public:
        UnionFind(int n);
        ~UnionFind();

        void create(int x);
        int find(int x);
        void unionSets(int x, int y);
    };

}

#endif // UNION_FIND_H
