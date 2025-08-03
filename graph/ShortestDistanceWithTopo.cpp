// Problem: Shortest Path in a Directed Acyclic Graph (DAG)
// Given a DAG with V vertices and E weighted edges,
// find the shortest distance from source node 0 to all other nodes.
// If a node is unreachable, mark its distance as -1.

// Time Complexity: O(V + E) — for topological sort and single pass edge relaxation
// Space Complexity: O(V + E) — for adjacency list and distance/visited arrays

class Solution {
  public:

    // DFS-based Topological Sort
    void topo(int node, vector<int> &visited, stack<int> &st,
              vector<vector<pair<int, int>>> &adj) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            int u = it.first;
            if (!visited[u]) {
                topo(u, visited, st, adj);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {
        // Adjacency list construction
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        int src = 0;
        vector<int> visited(V, 0);
        stack<int> st;

        // Step 1: Topological sort
        topo(src, visited, st, adj);

        // Step 2: Initialize distances
        vector<int> dis(V, 1e9);
        dis[src] = 0;

        // Step 3: Relax nodes in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dis[node] != 1e9) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dis[node] + wt < dis[v]) {
                        dis[v] = dis[node] + wt;
                    }
                }
            }
        }

        // Step 4: Mark unreachable nodes as -1
        for (int i = 0; i < V; i++) {
            if (dis[i] == 1e9) dis[i] = -1;
        }

        return dis;
    }
};
