/*
Problem: Unique Paths II (Leetcode 63)

You are given an m x n grid. Some cells contain obstacles (value 1), and the rest are empty (value 0).
You can only move either down or right at any point in time.

Determine the number of unique paths from the top-left corner to the bottom-right corner
such that you avoid all obstacles.

Approach:
- Implemented three dynamic programming strategies:
    1. Memoization (Top-down with recursion)
    2. Tabulation (Bottom-up DP)
    3. Space Optimized DP (using 1D vector)
*/

class Solution {
public:
    // Memoization helper: calculates number of unique paths to cell (i, j)
    int ways(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        // If out of bounds
        if (i < 0 || j < 0)
            return 0;

        // If current cell has an obstacle, no path is possible
        if (obstacleGrid[i][j] == 1)
            return 0;

        // If we've reached the starting point
        if (i == 0 && j == 0)
            return 1;

        // Return memoized result
        if (dp[i][j] != -1)
            return dp[i][j];

        // Paths from above and left
        int up = ways(i - 1, j, obstacleGrid, dp);
        int left = ways(i, j - 1, obstacleGrid, dp);

        return dp[i][j] = up + left;
    }

    // Method 1: Memoization (Top-down)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If start or end cell is blocked, no path exists
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return ways(m - 1, n - 1, obstacleGrid, dp);
    }

    // Method 2: Tabulation (Bottom-up)
    int uniquePathsTabulation(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If cell is blocked, skip it
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                // Starting cell
                else if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    // Method 3: Space Optimized DP using 1D vector
    int uniquePathsSpaceOptimized(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n, 0);

        for (int i = 0; i < m; ++i) {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    curr[j] = 0;
                } else if (i == 0 && j == 0) {
                    curr[j] = 1;
                } else {
                    int up = (i > 0) ? prev[j] : 0;
                    int left = (j > 0) ? curr[j - 1] : 0;
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};
| Method          | Time Complexity | Space Complexity           |
| --------------- | --------------- | -------------------------- |
| Memoization     | O(m × n)        | O(m × n) + recursion stack |
| Tabulation      | O(m × n)        | O(m × n)                   |
| Space Optimized | O(m × n)        | O(n)                       |
