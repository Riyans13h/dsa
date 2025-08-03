// DFS Traversal of Graph - Starting from Node 0

/*
Problem:
Given an undirected connected graph represented as an adjacency list `adj`,
return the Depth-First Search (DFS) traversal starting from node 0.

Input:
- adj: a vector of vectors where adj[i] contains all nodes connected to node i.
- The graph is connected and has no self-loops.

Output:
- A vector containing the DFS traversal order starting from node 0.

Time Complexity: O(V + E)
    - V = number of vertices, E = number of edges
    - Each vertex and edge is visited once.

Space Complexity: O(V)
    - Visited array + recursion stack
*/

class Solution {
  public:
    // Helper recursive DFS function
    void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
        visited[node] = 1;            // Mark the node visited
        result.push_back(node);       // Add node to DFS traversal list

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
    }

    // Main DFS function
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();            // Total nodes
        vector<int> visited(n, 0);     // Visited array
        vector<int> result;            // Result DFS traversal

        dfsHelper(0, adj, visited, result); // Start DFS from node 0
        return result;
    }
};
