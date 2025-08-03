/*
Question: Dijkstra's Algorithm (Single Source Shortest Path)
Given a graph with V vertices and E weighted edges, and a source vertex src, return the shortest distance from the source to all other vertices.

Input:
- V: Number of vertices (0 to V-1)
- edges: List of edges. Each edge is a triplet {u, v, wt}
- src: Source vertex

Output:
- A vector<int> where ans[i] is the shortest distance from src to i

Constraints:
- 1 <= V <= 1e4
- 1 <= E <= 1e5
- Edge weights are non-negative

Time Complexity: O((V + E) * log V) using set
Space Complexity: O(V + E)
*/

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Build adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
            // If graph is undirected, also add: adj[v].push_back({u, wt});
        }

        vector<int> dis(V, 1e9);
        dis[src] = 0;

        set<pair<int, int>> s;
        s.insert({0, src});

        while (!s.empty()) {
            auto it = *(s.begin());
            int u = it.second;
            s.erase(it);

            for (auto edge : adj[u]) {
                int v = edge.first;
                int wt = edge.second;

                if (dis[u] + wt < dis[v]) {
                    if (dis[v] != 1e9) {
                        s.erase({dis[v], v});
                    }
                    dis[v] = dis[u] + wt;
                    s.insert({dis[v], v});
                }
            }
        }

        return dis;
    }
};
