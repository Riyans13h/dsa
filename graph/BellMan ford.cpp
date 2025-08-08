
 // Question:
        // Given a weighted, directed graph with `V` vertices and a list of `E` edges.
        // Find the shortest distance from a given source vertex `src` to all other vertices.
        // If a negative weight cycle is reachable from the source, return a vector with `{-1}`.

        // Logic:
        // Bellman-Ford iteratively relaxes edges V-1 times to find shortest paths.
        // A final pass detects negative cycles by checking for further relaxation.

        // Use long long for distance to prevent potential integer overflow
        // with large negative path sums.

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        const long long INF = 1e18;
        vector<long long> distance(V, INF);
        distance[src] = 0;

        // Step 2: Relax all edges V-1 times.
        for (int i = 0; i < V - 1; i++) {
            for (auto it : edges) {
                int u = it[0];
                int v = it[1];
                int w = it[2];

                // Correct relaxation condition: check if source 'u' is reachable.
                if (distance[u] != INF && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                }
            }
        }

        // Step 3: Check for negative cycles in a final pass.
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            // If a distance can still be relaxed, a negative cycle exists.
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                return {-1};
            }
        }

        // Convert the long long distances back to int.
        vector<int> result(V);
        for (int i = 0; i < V; ++i) {
            if (distance[i] == INF) {
                result[i] = 1e9; // Represents infinity for the int type
            } else {
                result[i] = static_cast<int>(distance[i]);
            }
        }

        return result;
    }
};

/*
* Time Complexity (TC):
* O(V * E). The algorithm performs V-1 relaxation passes, and each pass
* iterates through all E edges. The final negative cycle check adds another O(E) pass.
*
* Space Complexity (SC):
* O(V). The space is dominated by the `distance` vector, which stores distances for V vertices.
*/