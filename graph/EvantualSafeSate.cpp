/*
Leetcode 210: Course Schedule II

Problem:
You are given `numCourses` courses labeled from 0 to numCourses - 1,
and a list of prerequisite pairs, where each pair [a, b] means:
To take course `a`, you must first complete course `b`.

Goal:
Return any valid ordering of courses you can take to finish all.
If it's not possible (due to a cycle), return an empty array.

Approach:
Use Depth-First Search (DFS) with topological sort.
We detect cycles using a recursion path array.
If a cycle is found, return {}.
Otherwise, return the reverse post-order traversal of the DAG.
*/

class Solution {
public:
    // DFS helper to detect cycle and build topological order
    bool dfs(int course, vector<vector<int>>& graph, vector<int>& visited, vector<int>& path, vector<int>& order) {
        visited[course] = 1;     // mark as visited
        path[course] = 1;        // mark as part of current DFS path

        for (int neighbor : graph[course]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, graph, visited, path, order))
                    return true;  // cycle found
            }
            else if (path[neighbor]) {
                return true;      // back edge → cycle
            }
        }

        path[course] = 0;           // remove from current DFS path
        order.push_back(course);    // post-order for topological sort
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]); // build directed graph
        }

        vector<int> visited(numCourses, 0);  // marks visited nodes
        vector<int> path(numCourses, 0);     // tracks current path
        vector<int> order;                   // stores result

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, graph, visited, path, order))
                    return {};  // cycle detected
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};

/*
Test Case:
Input: numCourses = 2, prerequisites = [[0,1]]
Explanation: You must take course 1 before course 0.
Valid output: [1, 0]

Time Complexity: O(V + E)
- V is the number of courses
- E is the number of prerequisite pairs

Space Complexity: O(V + E)
- Adjacency list + recursion stack + visited arrays
*/
