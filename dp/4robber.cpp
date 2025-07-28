/*
🏠💰 Leetcode 198: House Robber

🧠 Problem Statement:
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, but adjacent houses have security systems connected.
If two adjacent houses are robbed on the same night, the police will be alerted.

🧾 Task:
Return the maximum amount of money you can rob tonight without alerting the police.

🔐 Constraints:
- You cannot rob two adjacent houses.
- You may rob from either end of the list.
- 1 <= nums.length <= 100
- 0 <= nums[i] <= 400

📥 Input: A vector of integers `nums` representing the amount of money at each house.
📤 Output: The maximum money that can be robbed without alerting the police.

🔁 Example:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 0 (2) + house 2 (9) + house 4 (1) = 12
*/

class Solution {
public:
    // Recursive function with memoization to solve subproblems
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        // Base case: only one house, rob it
        if (n == 0) return nums[0];

        // Base case: two houses, rob the one with more money
        if (n == 1) return max(nums[0], nums[1]);

        // If already computed, return the stored result
        if (dp[n] != -1) return dp[n];

        // Option 1: Do not rob current house, move to previous
        int notTake = solve(n - 1, nums, dp);

        // Option 2: Rob current house and skip previous one
        int take = nums[n] + solve(n - 2, nums, dp);

        // Store and return the maximum of the two options
        return dp[n] = max(take, notTake);
    }

    // Main function to be called
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge case: only one house available
        if (n == 1) return nums[0];

        // DP array to store results, initialized with -1
        vector<int> dp(n, -1);

        // Start from the last house (index n-1)
        return solve(n - 1, nums, dp);
    }
};
