/*
🐭 Rat in a Maze Problem:

Given an n x n matrix 'maze' where:
- 0 represents a blocked cell.
- 1 represents a free cell.

The rat starts at (0, 0) and must reach (n-1, n-1).
It can move in 4 directions: 'U' (up), 'D' (down), 'L' (left), 'R' (right).
You must return all unique paths in **lexicographically sorted order**.

Constraints:
- 1 ≤ n ≤ 10
- No cell may be visited more than once in a path.
*/

class Solution {
public:
    // Check if cell (i, j) is within bounds, not visited, and not blocked
    bool isSafe(int i, int j, vector<vector<int>>& maze, vector<vector<int>>& visited) {
        int n = maze.size();
        return (i >= 0 && i < n && j >= 0 && j < n &&
                visited[i][j] == 0 && maze[i][j] == 1);
    }

    // Recursive function to explore all valid paths
    void solve(int i, int j, vector<vector<int>>& maze, vector<string>& ans,
               string output, vector<vector<int>>& visited) {
        int n = maze.size();

        // Base case: destination reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(output);
            return;
        }

        // Mark current cell as visited
        visited[i][j] = 1;

        // Move Down
        if (isSafe(i + 1, j, maze, visited)) {
            solve(i + 1, j, maze, ans, output + 'D', visited);
        }

        // Move Left
        if (isSafe(i, j - 1, maze, visited)) {
            solve(i, j - 1, maze, ans, output + 'L', visited);
        }

        // Move Right
        if (isSafe(i, j + 1, maze, visited)) {
            solve(i, j + 1, maze, ans, output + 'R', visited);
        }

        // Move Up
        if (isSafe(i - 1, j, maze, visited)) {
            solve(i - 1, j, maze, ans, output + 'U', visited);
        }

        // Backtrack: unmark current cell
        visited[i][j] = 0;
    }

    // Entry point
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;

        // If start or end cell is blocked, return empty
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        // Initialize visited matrix with 0s
        vector<vector<int>> visited(n, vector<int>(n, 0));

        string output = "";
        solve(0, 0, maze, ans, output, visited);

        // Sort results lexicographically
        sort(ans.begin(), ans.end());
        return ans;
    }
};
