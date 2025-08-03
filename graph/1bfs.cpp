// BFS Traversal of Graph - Starting from Node 0

/*
Problem:
Given an undirected connected graph represented as an adjacency list `adj`,
return the Breadth-First Search (BFS) traversal starting from node 0.

Input:
- adj: a vector of vectors where adj[i] contains all nodes connected to node i.
- The graph is connected and has no self-loops.

Output:
- A vector containing the BFS traversal order starting from node 0.

Time Complexity: O(V + E)
    - V = number of vertices, E = number of edges
    - Each vertex and edge is visited exactly once in BFS

Space Complexity: O(V)
    - Visited array + queue to store nodes

*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();            // Number of vertices
        vector<int> vis(n, 0);         // Visited array to mark visited nodes
        vector<int> result;            // Stores the final BFS traversal
        queue<int> q;                  // Queue for BFS

        q.push(0);                     // Start BFS from node 0
        vis[0] = 1;                    // Mark node 0 as visited

        while (!q.empty()) {
            int node = q.front();      // Get the front node
            q.pop();
            result.push_back(node);    // Add it to BFS result

            // Visit all unvisited neighbors of the current node
            for (auto neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1; // Mark neighbor as visited
                    q.push(neighbor); // Push neighbor to queue
                }
            }
        }

        return result;
    }
};
