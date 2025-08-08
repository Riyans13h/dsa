
/*
 Question:
You are given a **connected undirected graph** with `n` nodes and a list of `connections` (edges).  
You need to find all **critical connections (bridges)** in the graph.  
An edge is called a *critical connection* if removing it makes the graph disconnected.

Example:
Input:
n = 5  
connections = {{0,1},{1,2},{2,0},{1,3},{3,4}}

Output:
[[4,3],[3,1]]

Explanation:
- Removing (3-1) or (4-3) disconnects part of the graph, so they are **critical connections**.

💡 Core Logic:
This problem is solved using **Tarjan's Algorithm** to find bridges in a graph:
- A **bridge** is an edge (u, v) such that `low[v] > disc[u]`, meaning no back edge from subtree of v to u or its ancestors.
- We use DFS and track:
  - `disc[i]`: discovery time of node i
  - `low[i]`: lowest discovery time reachable from node i

🧠 Conceptual Question:
What will happen if we move `time++` **after** the recursive DFS call instead of **before**?  
➡️ Answer: All nodes will get the same `disc` and `low` values, breaking the bridge detection logic.

⏱ Time Complexity: O(V + E)  
🧠 Space Complexity: O(V + E)
*/

class Solution {
public:

    // DFS function to explore the graph and find bridges
    void dfs(int node, int time, int parent, vector<int>& visited,
             vector<int>& low, vector<int>& disc,
             vector<vector<int>>& adj, vector<vector<int>>& result) {
        
        visited[node] = 1;

        // Set discovery and low time
        low[node] = disc[node] = time++;

        // Explore all neighbors
        for (auto it : adj[node]) {

            if (it == parent) continue;  // Skip the edge leading back to parent

            if (!visited[it]) {
                // Recurse for unvisited neighbor
                dfs(it, time, node, visited, low, disc, adj, result);

                // Update the low-link value
                low[node] = min(low[node], low[it]);

                // Check for bridge condition
                if (low[it] > disc[node]) {
                    result.push_back({it, node});  // Found a bridge
                }

            } else {
                // Update low if it's a back edge
                low[node] = min(low[node], disc[it]);
            }
        }
    }

    // Main function to find all critical connections
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);     // Adjacency list
        vector<vector<int>> result;     // Store bridges

        // Build graph
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Discovery and low-link arrays
        vector<int> low(n, 0), disc(n, 0), visited(n, 0);

        // DFS for all unvisited nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, 0, -1, visited, low, disc, adj, result);
            }
        }

        return result;  // Return list of critical connections (bridges)
    }
};

