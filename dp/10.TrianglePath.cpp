// ✅ PROBLEM:
// Given a triangle array, return the minimum path sum from top to bottom.
// At each step, you may move to adjacent numbers on the row below.

// -------------------- MEMOIZATION --------------------
class Solution {
public:
    int minPath(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle) {
        // Base case: reached the bottom row
        if (i == triangle.size() - 1)
            return triangle[i][j];

        // If already calculated, return stored value
        if (dp[i][j] != -1)
            return dp[i][j];

        // Move to the cell directly below
        int down = triangle[i][j] + minPath(i + 1, j, dp, triangle);
        // Move to the cell diagonally right below
        int diagonal = triangle[i][j] + minPath(i + 1, j + 1, dp, triangle);

        // Store and return the minimum of both paths
        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();
        // Initialize memoization table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minPath(0, 0, dp, triangle);
    }
};

// ✅ Time Complexity (Memoization): O(N^2)
// Space Complexity: O(N^2) + O(N) recursion stack
// where N is the number of rows in the triangle

// -------------------- TABULATION --------------------
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // Initialize dp with triangle's last row
        vector<vector<int>> dp = triangle;

        // Build from bottom up
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // Choose min path: down or diagonal
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0]; // Top cell contains final answer
    }
};

//Time Complexity (Tabulation): O(N^2)
//Space Complexity: O(N^2)
