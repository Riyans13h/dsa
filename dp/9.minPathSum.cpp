/*
    Problem: Minimum Path Sum (Leetcode 64)

    You're given a 2D grid of non-negative numbers. Start at the top-left corner 
    and move only right or down to reach the bottom-right. Find the path with the minimum sum.
*/



// ---------------------- Memoization ----------------------
// Top-down approach with recursion + memoization
class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        // If out of bounds, return large value
        if (i < 0 || j < 0) return 1e9;

        // If we're at the start, return the value at (0, 0)
        if (i == 0 && j == 0) return grid[0][0];

        // If already computed, use that
        if (dp[i][j] != -1) return dp[i][j];

        // Try going up and left, take the minimum
        int fromTop = helper(i - 1, j, grid, dp);
        int fromLeft = helper(i, j - 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(fromTop, fromLeft);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        return helper(rows - 1, cols - 1, grid, dp);
    }
};

// ---------------------- Tabulation ----------------------
// Bottom-up approach without recursion
class SolutionTabulation {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];  // starting point
                } else {
                    int fromTop = (i > 0) ? dp[i - 1][j] : 1e9;
                    int fromLeft = (j > 0) ? dp[i][j - 1] : 1e9;
                    dp[i][j] = grid[i][j] + min(fromTop, fromLeft);
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

// ------------------ Space Optimization ------------------
// Optimized version using only one row
class SolutionOptimized {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> prev(cols, 0);  // stores previous row

        for (int i = 0; i < rows; ++i) {
            vector<int> curr(cols, 0);
            for (int j = 0; j < cols; ++j) {
                if (i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                } else {
                    int fromTop = (i > 0) ? prev[j] : 1e9;
                    int fromLeft = (j > 0) ? curr[j - 1] : 1e9;
                    curr[j] = grid[i][j] + min(fromTop, fromLeft);
                }
            }
            prev = curr;
        }

        return prev[cols - 1];
    }
};

/*
    Time Complexity:
    - All approaches run in O(m * n), where m = number of rows, n = number of columns

    Space Complexity:
    - Memoization: O(m * n) for dp + recursion stack
    - Tabulation: O(m * n)
    - Space Optimized: O(n)
*/

