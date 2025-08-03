/*
🔵 Problem: 931. Minimum Falling Path Sum
Link: https://leetcode.com/problems/minimum-falling-path-sum/

🧾 Description:
Given an n x n integer matrix, return the minimum sum of any falling path through `matrix`.
A falling path starts at any element in the first row and chooses one element from each row.
The next row's element must be in a column that is either the same, or one column to the left or right.

🔍 Example:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: 1 → 4 → 8 = 13
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🔁 Memoization Approach
    int minPath(int i, int j, int m, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if (j < 0 || j >= n) return 1e9;  // Out of bounds
        if (i == 0) return matrix[0][j];  // Top row base case

        if (dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + minPath(i - 1, j, m, n, matrix, dp);
        int ld = matrix[i][j] + minPath(i - 1, j - 1, m, n, matrix, dp);
        int rd = matrix[i][j] + minPath(i - 1, j + 1, m, n, matrix, dp);

        return dp[i][j] = min({up, ld, rd});
    }

    int minFallingPathSumMemo(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        int mini = INT_MAX;
        for (int j = 0; j < n; j++) {
            mini = min(mini, minPath(m - 1, j, m, n, matrix, dp));
        }
        return mini;
    }

    // 📦 Tabulation Approach
    int minFallingPathSumTab(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case: first row
        for (int j = 0; j < n; j++) dp[0][j] = matrix[0][j];

        // Bottom-up DP
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i - 1][j];
                int ld = (j - 1 >= 0) ? dp[i - 1][j - 1] : 1e9;
                int rd = (j + 1 < n) ? dp[i - 1][j + 1] : 1e9;

                dp[i][j] = matrix[i][j] + min({up, ld, rd});
            }
        }

        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

/*
 Time Complexity:
- Memoization: O(n^2) [Each state computed once]
- Tabulation: O(n^2)

 Space Complexity:
- Memoization: O(n^2) + recursion stack O(n)
- Tabulation: O(n^2)
*/
