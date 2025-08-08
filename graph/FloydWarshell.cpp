/**
 * Question:
 * Given a square matrix `dist` of size `n x n` representing the adjacency matrix of a graph.
 * `dist[i][j]` contains the weight of the edge from vertex `i` to vertex `j`.
 * If there is no edge, the value is a very large number (e.g., 1e8).
 * The task is to find the shortest distance between all pairs of vertices in the graph
 * and update the given `dist` matrix with these shortest path distances.
 */


class Solution {
public:
    /**
     * Logic of the Floyd-Warshall Algorithm:
     * This is a dynamic programming algorithm for finding all-pairs shortest paths.
     * The core idea is to iteratively consider all vertices as intermediate points
     * on the path between any two other vertices.
     *
     * 1. The algorithm uses three nested loops:
     * - The outermost loop `k` iterates through all possible intermediate vertices (from 0 to n-1).
     * - The middle loop `i` iterates through all possible source vertices.
     * - The innermost loop `j` iterates through all possible destination vertices.
     *
     * 2. The central update step is `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`.
     * This checks if the path from `i` to `j` is shorter by going through `k`.
     * - `dist[i][j]` is the shortest path from `i` to `j` found so far.
     * - `dist[i][k] + dist[k][j]` represents the path from `i` to `j` via the intermediate vertex `k`.
     *
     * 3. The check `if(dist[i][k] != 1e8 && dist[k][j]!= 1e8)` is crucial
     * to avoid integer overflow when adding two "infinite" distances.
     *
     * After the three loops complete, the `dist` matrix will contain the shortest
     * distances between all pairs of vertices.
     */
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        // int m = dist[0].size();
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != 1e8 && dist[k][j] != 1e8)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        return;
    }
};

/*
* Time Complexity (TC):
* The algorithm uses three nested loops, each iterating 'n' times.
* This results in a time complexity of O(n^3).
*
* Space Complexity (SC):
* The algorithm modifies the input matrix in place and does not use any
* additional data structures that scale with the input size.
* Therefore, the auxiliary space complexity is O(1).
*/