/*
🔷 Problem: Climbing Stairs (Leetcode Easy)

You are climbing a staircase. It takes `n` steps to reach the top.
Each time you can either climb 1 or 2 steps.
In how many distinct ways can you climb to the top?

🔸 Example:
Input: n = 3
Output: 3

Explanation: There are 3 ways to climb to the top:
→ 1 step + 1 step + 1 step  
→ 1 step + 2 steps  
→ 2 steps + 1 step  
*/

class Solution {
public:
    // Recursive function with memoization to find number of ways to climb stairs
    int stair(int n, vector<int> &dp) {
        // Base case: 1 way to stay at step 0 (do nothing)
        if (n == 0) return 1;

        // Base case: Only 1 way to reach step 1 (1 step)
        if (n == 1) return 1;

        // Return memoized result if already calculated
        if (dp[n] != -1) return dp[n];

        // Recurrence: sum of ways from (n-1) and (n-2) steps
        int oneStep = stair(n - 1, dp);  // taking 1 step
        int twoStep = stair(n - 2, dp);  // taking 2 steps

        // Store the result and return
        return dp[n] = oneStep + twoStep;
    }

    // Main function to be called
    int climbStairs(int n) {
        // dp[i] will store number of ways to reach step i
        vector<int> dp(n + 1, -1);  // Initialize all with -1 for memoization
        return stair(n, dp);
    }
};
