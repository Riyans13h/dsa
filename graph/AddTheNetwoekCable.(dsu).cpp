// Q. Count the number of Strongly Connected Components (SCCs) in a directed graph using Kosaraju's algorithm.
//
// A directed graph is strongly connected if there is a path between any two vertices. 
// Kosaraju's algorithm finds all strongly connected components in a graph using 3 main steps:
// 1. Do a DFS and store the nodes in a stack according to their finishing time.
// 2. Transpose the graph (reverse the direction of every edge).
// 3. Do DFS on the transposed graph using the order in the stack to identify SCCs.
//
// Input: A directed graph represented as an adjacency list.
// Output: The number of strongly connected components in the graph.

class Solution {
public:
    // Step 1 DFS: Standard DFS, but push nodes to stack after all descendants are visited
    void dfs1(int node, stack<int> &st, vector<vector<int>> &adj, vector<int> &visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs1(it, st, adj, visited);
            }
        }
        st.push(node); // Finished exploring all neighbors
    }

    // Step 3 DFS: DFS on transposed graph to identify SCC
    void dfs2(int node, stack<int> &st, vector<vector<int>> &adjt, vector<int> &visited) {
        visited[node] = 1;
        for (auto it : adjt[node]) {
            if (!visited[it]) {
                dfs2(it, st, adjt, visited);
            }
        }
    }

    int kosaraju(vector<vector<int>> &adj) {
        int n = adj.size();                 // Number of vertices
        vector<int> visited(n, 0);          // Visited array
        stack<int> st;                      // Stack for finish times

        // Step 1: Topological Sort using DFS
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i, st, adj, visited);
            }
        }

        // Step 2: Transpose the graph
        vector<vector<int>> adjt(n);        // Transposed graph
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                adjt[it].push_back(i);
            }
        }

        // Step 3: DFS on Transposed Graph using stack order
        visited = vector<int>(n, 0);        // Reset visited
        int count = 0;                      // Count of strongly connected components

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                count++;
                dfs2(node, st, adjt, visited);
            }
        }

        return count;
    }
};

/*
🧠 Logic Recap:
1. First DFS (dfs1) captures the "finish time" ordering of nodes (postorder).
2. Transpose the graph by reversing all edges.
3. Second DFS (dfs2) on the transposed graph using the stack order ensures we explore full SCCs.

✅ Time Complexity: 
O(V + E), where V = number of vertices, E = number of edges.
- Each node and edge is visited at most twice (once in dfs1, once in dfs2).

✅ Space Complexity:
O(V + E)
- Adjacency list for graph and transpose: O(V + E)
- Visited array: O(V)
- Stack: O(V)
*/
