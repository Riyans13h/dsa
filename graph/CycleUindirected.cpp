/*
Problem:
Given an undirected graph with V vertices and a list of edges,
determine if the graph contains a cycle using DFS.

Approach:
- Convert the edge list into an adjacency list.
- Use DFS to explore nodes. If we visit an already visited node
  that is not the parent of the current node, a cycle is found.

Time Complexity: O(V + E)
- V: number of vertices
- E: number of edges (we visit each node and edge once)

Space Complexity: O(V + E)
- For adjacency list (O(V + E))
- For visited array (O(V))
*/

class Solution {
public:
    // DFS function to detect cycle in an undirected graph
    bool dfs(int node, int parent, vector<int> adj[], int visited[]) {
        visited[node] = 1;

        for (auto neighbor : adj[node]) {
            // If the neighbor hasn't been visited, recursively DFS on it
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, adj, visited)) {
                    return true; // cycle found
                }
            }
            // If visited and not parent → cycle
            else if (neighbor != parent) {
                return true;
            }
        }

        return false; // no cycle from this node
    }

    // Main function to check for cycle in the graph
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];           // adjacency list
        int visited[V] = {0};         // visited array

        // Step 1: Convert edge list to adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u); // since undirected graph
        }

        // Step 2: Check for cycle in each component
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) {
                    return true;
                }
            }
        }

        return false; // no cycle found
    }
};
