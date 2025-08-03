/*
LeetCode 785 - Is Graph Bipartite?

You're given an undirected graph (adjacency list form).
Check if it can be divided into 2 sets (A and B) such that:
every edge connects one node from A and one from B.

Idea: Use DFS to try coloring the graph using 2 colors.
If any neighbor ends up with the same color = Not bipartite.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/

class Solution {
public:

    // DFS check: try to color with 'col'
    bool dfs(int node, vector<vector<int>>& adj, int col, 
             vector<int>& color, vector<int>& vis) {
        
        vis[node] = 1;
        color[node] = col;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                // try alternate color for neighbor
                if (!dfs(it, adj, 1 - col, color, vis)) return false;
            }
            else if (color[it] == color[node]) {
                // same color conflict => not bipartite
                return false;
            }
        }
        return true;
    }

    // main function
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V = graph.size();              // number of nodes
        vector<int> color(V, -1);          // -1 = uncolored
        vector<int> vis(V, 0);             // visited array

        for (int i = 0; i < V; i++) {
            if (!vis[i] && color[i] == -1) {
                // start dfs with color 0
                if (!dfs(i, graph, 0, color, vis)) return false;
            }
        }

        return true;
    }
};
