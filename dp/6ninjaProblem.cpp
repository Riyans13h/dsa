/*
👨‍🏫 Problem: Ninja Training (Dynamic Programming)

You are given a 2D vector `arr` of size n x 3, where `arr[i][j]` represents the merit points
Ninja gets on the i-th day for doing task j (0 ≤ j ≤ 2). He **cannot do the same task on two consecutive days**.

🔧 Task: Return the maximum merit points Ninja can earn in `n` days while following the rule.

Approach:
- Use recursion with memoization (top-down dynamic programming).
- Track the previous task to avoid repetition.
*/

class Solution {
public:
    // Recursive function with memoization
    int meritPoints(int ind, vector<vector<int>>& arr, int n, int last, vector<vector<int>>& dp) {
        // Base case: no more days left
        if (ind == n) return 0;

        // If already computed, return the stored result
        if (dp[ind][last] != -1) return dp[ind][last];

        int maxi = -1e9;

        // Try all tasks for the current day
        for (int i = 0; i < 3; i++) {
            if (i != last) {  // Ensure different task from the previous day
                int points = arr[ind][i] + meritPoints(ind + 1, arr, n, i, dp);
                maxi = max(maxi, points);
            }
        }

        

        return dp[ind][last] = maxi;
    }

    // Main function to start recursion with last task = 3 (meaning "no previous task")
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        // dp[day][lastTask] stores max points from day to end, given last task was 'lastTask'
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return meritPoints(0, arr, n, 3, dp);
    }
};
