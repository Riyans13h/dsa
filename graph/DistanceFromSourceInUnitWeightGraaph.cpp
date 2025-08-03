/*
Question:
Given an unweighted undirected graph, find the shortest distance (in terms of number of edges)
from a given source node to all other nodes using BFS.

Return a vector of distances from the source node.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/

class Solution {
public:

    void distance(int src, vector<vector<int>>& adj, vector<int>& dis) {
        int v = adj.size();
        vector<int> vis(v, 0);
        queue<pair<int, int>> q;

        vis[src] = 1;
        q.push({src, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int node = it.first;
            int d = it.second;

            dis[node] = d;

            for (auto nbr : adj[node]) {
                if (!vis[nbr]) {
                    vis[nbr] = 1;
                    q.push({nbr, d + 1});
                }
            }
        }
    }

    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int v = adj.size();
        vector<int> dis(v, 1e9); // INT_MAX or big value
        distance(src, adj, dis);
        return dis;
    }
};
