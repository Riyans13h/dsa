/*
Problem: House Robber II
Link: https://leetcode.com/problems/house-robber-ii/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    // Helper function to solve the linear House Robber problem using top-down DP
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        if (n == 0) return nums[0];
        if (n == 1) return max(nums[0], nums[1]);
        if (dp[n] != -1) return dp[n];

        int notTake = solve(n - 1, nums, dp);      // Skip current house
        int take = nums[n] + solve(n - 2, nums, dp); // Rob current house

        return dp[n] = max(take, notTake); // Store and return the result
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // Only one house, return its amount

        vector<int> num1, num2;

        // Create two separate arrays:
        // num1 excludes the last house
        // num2 excludes the first house
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                num1.push_back(nums[i]);
                continue;
            }
            if (i == n - 1) {
                num2.push_back(nums[i]);
                continue;
            }
            num1.push_back(nums[i]);
            num2.push_back(nums[i]);
        }

        // Solve both scenarios and take the max
        int j = num1.size();
        int k = num2.size();

        vector<int> dp1(j, -1); // DP for num1
        int one = solve(j - 1, num1, dp1);

        vector<int> dp2(k, -1); // DP for num2
        int second = solve(k - 1, num2, dp2);

        return max(one, second); // Return the max of the two scenarios
    }
};
