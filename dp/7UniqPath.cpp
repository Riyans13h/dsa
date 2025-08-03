/*
Problem: Unique Paths (Leetcode #62)

You are in a `m x n` grid. Starting at top-left (0, 0), you can move either:
Right (i, j+1)  
⬇ Down (i+1, j)

Return the total number of unique paths to reach the bottom-right (m-1, n-1).

 Approach:
- Use recursion with memoization (Top-Down DP)
- Use tabulation (Bottom-Up DP) as an alternative

 Base Case:
- ways(0, 0) = 1 (only one path: stay there)
- If (i < 0 || j < 0): return 0

 Time Complexity:
- Memoization: O(m * n)
- Tabulation: O(m * n)

 Space Complexity:
- Memoization: O(m * n) for DP table + recursion stack
- Tabulation: O(m * n)
*/

class Solution {
public:
    // ---------------- Memoization (Top-Down) ----------------
    int ways(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) return 1;        // Reached start
        if (i < 0 || j < 0) return 0;          // Out of grid

        if (dp[i][j] != -1) return dp[i][j];   // Use cached value

        int left = ways(i, j - 1, dp);         // Move left
        int up = ways(i - 1, j, dp);           // Move up

        return dp[i][j] = left + up;           // Total paths to (i, j)
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return ways(m - 1, n - 1, dp);         // Start from (m-1, n-1)
    }

    // ---------------- Tabulation (Bottom-Up) ----------------
    int uniquePathsTabulation(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;  // Starting point
                } else {
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    dp[i][j] = left + up;
                }
            }
        }

        return dp[m - 1][n - 1];  // Bottom-right cell
    }
};
