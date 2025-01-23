#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
    // vector<int> size;
    int components;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
            // size[i] = 1;
        }
    }

    /**
     * Find the root of the set in which element x belongs.
     * @param x The element to find.
     * @return The root of the set in which element x belongs.
     */
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    /**
     * Merge the sets in which elements x and y belong.
     * @param x The first element.
     * @param y The second element.
     * @return True if the sets were merged, false otherwise.
     */
    bool merge(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
                // size[rootX] += size[rootY];
            }
            else if (rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
                // size[rootY] += size[rootX];
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
                // size[rootX] += size[rootY];
            }
        }
        return false;
    }

    /**
     * Check if elements x and y are connected.
     * @param x The first element.
     * @param y The second element.
     * @return True if elements x and y are connected, false otherwise.
     */
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    /**
     *  Get the size of the set in which element x belongs.
     * @param x The element to find.
     * @return The size of the set in which element x belongs.
     */
    // int getSize(int x) {
    //     return size[find(x)];
    // }

    /**
     * Get the number of connected components.
     * @return The number of connected components.
     */
    int getComponents() {
        return components;
    }
};