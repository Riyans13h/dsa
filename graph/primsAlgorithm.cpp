
/*
📝 Question:
You are given a connected, undirected, and weighted graph with V vertices and E edges.
Your task is to find the weight of the Minimum Spanning Tree (MST) using Prim's Algorithm.

The graph is represented by an edge list `edges` where:
- edges[i] = {u, v, wt} means there is an undirected edge between u and v with weight wt.

Return:
- The sum of weights of the edges in the MST.

Example:
Input:
V = 3
E = 3
edges = {{0, 1, 5}, {1, 2, 3}, {0, 2, 1}}

Output:
4
Explanation:
The MST will take edges {0,2} (1) and {1,2} (3) → total weight = 4
*/

/*
📌 Logic of Prim's Algorithm:
1. Build an adjacency list from the given edge list (undirected graph).
2. Start from any node (we choose node 0 here).
3. Use a min-heap (priority queue) to always pick the smallest edge leading to an unvisited node.
4. Mark the chosen node as visited, and add its edge weight to MST sum.
5. Push all its adjacent edges into the priority queue.
6. Repeat until all vertices are visited.
7. The accumulated sum will be the MST weight.
*/

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // because the graph is undirected
        }

        // Step 2: Initialize MST weight and visited array
        int mstWeight = 0;
        vector<int> visited(V, 0);

        // Step 3: Min-heap {edge weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Step 4: Start with node 0 and weight 0
        pq.push({0, 0});

        // Step 5: Main loop of Prim's algorithm
        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();

            // Skip if already visited
            if (visited[u]) continue;

            // Include this edge in MST
            mstWeight += wt;
            visited[u] = 1;

            // Add all adjacent edges to PQ
            for (auto &[v, edw] : adj[u]) {
                if (!visited[v]) {
                    pq.push({edw, v});
                }
            }
        }

        return mstWeight;
    }
};

/*
⏳ Time Complexity:
- Building adjacency list: O(E)
- Prim's algorithm: O((V + E) log V) due to priority queue operations
Overall: O((V + E) log V)

💾 Space Complexity:
- Adjacency list: O(V + E)
- Visited array: O(V)
- Priority queue: O(V)
Overall: O(V + E)
*/
