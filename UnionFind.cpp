// UnionFind.cpp
#include "UnionFind.h"
#include <stdexcept>

namespace graph {

    UnionFind::UnionFind(int n) : size(n) {
        if (n <= 0)
            throw std::invalid_argument("UnionFind size must be positive.");

        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; ++i) {
            create(i);
        }
    }

    UnionFind::~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    void UnionFind::create(int x) {
        if (x < 0 || x >= size)
            throw std::out_of_range("UnionFind::create - index out of range.");
        parent[x] = x;
        rank[x] = 0;
    }

    int UnionFind::find(int x) {
        if (x < 0 || x >= size)
            throw std::out_of_range("UnionFind::find - index out of range.");
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void UnionFind::unionSets(int x, int y) {
        if (x < 0 || x >= size || y < 0 || y >= size)
            throw std::out_of_range("UnionFind::unionSets - index out of range.");

        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot) return;

        // Union by rank
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

} // namespace graph
