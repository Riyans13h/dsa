/*
Topological Sort Using DFS

Problem:
Given a Directed Acyclic Graph (DAG) with V vertices and E edges,
return any topological ordering of the graph.

A topological sort of a DAG is a linear ordering of its vertices
such that for every directed edge u → v, vertex u comes before v
in the ordering.

Input:
- V: number of vertices (0 to V-1)
- edges: list of directed edges, where each edge is [u, v] meaning u → v

Output:
- A vector representing a valid topological order

Time Complexity: O(V + E)
- Each node and each edge is visited once in DFS

Space Complexity: O(V + E)
- For adjacency list + visited array + recursion stack
*/

class Solution {
public:

    // DFS utility to visit nodes and store the order in a stack
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj, stack<int>& st) {
        visited[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, adj, st);
            }
        }

        st.push(node); // node processed after all neighbors
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Step 1: Convert edge list to adjacency list
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        // Step 2: Run DFS on unvisited nodes
        vector<int> visited(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }

        // Step 3: Extract ordering from the stack
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
