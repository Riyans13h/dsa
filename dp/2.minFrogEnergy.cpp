/*
🔷 Problem: Minimum Cost to Climb from 0 to N-1 (Frog Jump)

A frog is jumping on stairs. Each stair has a certain height given in `height[]`.
The frog is initially at index 0. It can jump either to index i+1 or i+2.
The cost of a jump is the absolute difference between the heights of the stairs.

Return the **minimum total cost** to reach the last stair (index n-1).

🔸 Example:
Input: height = [10, 30, 40, 20]
Output: 30

Explanation:
Jump from 0 → 1 (cost 20), then 1 → 3 (cost 10), total = 30.
*/

class Solution {
public:
    // Recursive function with memoization
    int jump(vector<int>& height, vector<int>& dp, int n) {
        if (n == 0) return 0;  // Base case: already at start
        if (dp[n] != -1) return dp[n];  // Return cached result

        // One step jump
        int left = abs(height[n] - height[n - 1]) + jump(height, dp, n - 1);

        // Two step jump, only if possible
        int right = INT_MAX;
        if (n - 2 >= 0)
            right = abs(height[n] - height[n - 2]) + jump(height, dp, n - 2);

        // Store and return the minimum cost
        return dp[n] = min(left, right);
    }

    // Main function
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);  // Initialize DP array
        return jump(height, dp, n - 1);  // Start from last step
    }
};
