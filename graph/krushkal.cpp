/*
Problem:
---------
We are given:
- V vertices (numbered 0 to V-1)
- A list of edges, where each edge has: {u, v, weight}

Task:
Find the weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.

Approach:
---------
1. Sort all edges in non-decreasing order of weight.
2. Use Disjoint Set Union (DSU) to check if two vertices belong to the same component.
3. If they belong to different components, include the edge in the MST and merge the components.
4. Stop when we have exactly V-1 edges in the MST.

We will use:
- DSU with path compression (for fast "find" operation).
- Union by size (to keep the trees shallow).
*/

class Solution {
  public:
    // Find function with path compression
    int find(int x, vector<int> &parent) {
        if (x == parent[x]) return x; // x is the leader of its set
        return parent[x] = find(parent[x], parent); // Path compression
    }

    // Merge two sets using union by size
    void merge(int u, int v, vector<int> &size, vector<int> &parent) {
        int pu = find(u, parent);
        int pv = find(v, parent);
        if (pu == pv) return; // Already in the same set

        // Attach smaller set under the larger set
        if (size[pv] >= size[pu]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    // Kruskal's algorithm to find MST weight
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<int> size(V, 1), parent(V);
        for (int i = 0; i < V; i++) {
            parent[i] = i; // Initially, each vertex is its own parent
        }

        // Store edges as {weight, {u, v}} for sorting
        vector<pair<int, pair<int, int>>> ed;
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            ed.push_back({w, {u, v}});
        }
        sort(ed.begin(), ed.end()); // Sort edges by weight

        int wt = 0; // MST total weight

        // Process edges in increasing order
        for (auto &it : ed) {
            int u = it.second.first;
            int v = it.second.second;
            int w = it.first;

            if (find(u, parent) != find(v, parent)) {
                merge(u, v, size, parent);
                wt += w;
            }
        }
        return wt;
    }
};

/*
Example Test Case:
------------------
V = 4
Edges:
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Sorted by weight:
(2,3,4), (0,3,5), (0,1,10), (0,2,6), (1,3,15)

MST picks:
- Edge (2,3) weight 4
- Edge (0,3) weight 5
- Edge (0,1) weight 10

Total MST weight = 4 + 5 + 10 = 19
*/
