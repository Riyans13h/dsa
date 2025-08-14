// Problem:
// You are given an undirected connected graph with V vertices and a list of edges.
// Your task is to find all Articulation Points in the graph.
// An articulation point (or cut vertex) is a vertex that, if removed along with its edges, makes the graph disconnected.

// Example:
// Input:
// V = 5
// edges = {{0, 1}, {1, 2}, {1, 3}, {3, 4}}
// Output:
// [1, 3]
// Explanation: Removing node 1 or 3 disconnects the graph, so they are articulation points.

class Solution {
public:

    // Depth-First Search (DFS) helper to find articulation points
    void dfs(int node, int parent, int &timer,
             vector<int> &visited, vector<int> &low, vector<int> &disc,
             vector<vector<int>> &adj, vector<int> &ans) {

        visited[node] = 1;
        low[node] = disc[node] = timer++;

        for (auto nbr : adj[node]) {
            if (nbr == parent) continue; // Ignore the parent edge

            if (!visited[nbr]) {
                // Recurse on the unvisited neighbor
                dfs(nbr, node, timer, visited, low, disc, adj, ans);

                // After DFS, update low time of current node
                low[node] = min(low[node], low[nbr]);

                // Check articulation point condition (non-root)
                if (low[nbr] >= disc[node] && parent != -1) {
                    ans[node] = 1;
                }
            } else {
                // Back edge case
                low[node] = min(low[node], disc[nbr]);
            }
        }

        // Special check for root node
        if (parent == -1 && adj[node].size() > 1) {
            ans[node] = 1;
        }
    }

    // Main function to find all articulation points
    vector<int> articulationPoints(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V); // Adjacency list

        // Build the undirected graph
        for (auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);
        vector<int> low(V, 0);
        vector<int> disc(V, 0);
        vector<int> ans(V, 0); // Stores 1 if node is articulation point
        vector<int> result;    // Final list of articulation points

        int timer = 0;

        // Run DFS for each component
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, timer, visited, low, disc, adj, ans);
            }
        }

        // Collect articulation points
        for (int i = 0; i < V; i++) {
            if (ans[i] == 1) {
                result.push_back(i);
            }
        }

        return result;
    }
};

/*
Time Complexity:  O(V + E)
- Each node and edge is visited once using DFS.

Space Complexity: O(V + E)
- Adjacency list takes O(E) space.
- Arrays: visited, low, disc, ans take O(V) space each.
*/
