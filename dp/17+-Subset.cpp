// Problem:
// Given an array of integers 'nums' and an integer 'target',
// assign '+' or '-' to each element such that the final expression equals 'target'.
// Return the number of different expressions that evaluate to 'target'.

// Insight:
// This problem reduces to finding the number of subsets whose sum is:
// (sum(nums) - target) / 2, provided the result is non-negative and even.

class Solution {
public:

    // Top-down recursive DP (Memoization)
    int ways(int ind, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (nums[0] == 0 && target == 0) return 2; // two ways: include or exclude zero
            if (nums[0] == target || target == 0) return 1;
            return 0;
        }

        if (dp[ind][target] != -1) return dp[ind][target];

        int notTake = ways(ind - 1, nums, target, dp);
        int take = 0;
        if (nums[ind] <= target)
            take = ways(ind - 1, nums, target - nums[ind], dp);

        return dp[ind][target] = take + notTake;
    }

    // Bottom-up DP (Tabulation)
    int tabulation(vector<int>& nums, int subsetTarget) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(subsetTarget + 1, 0));

        // Initialize base cases
        if (nums[0] == 0) {
            dp[0][0] = 2; // two ways: include or exclude zero
        } else {
            dp[0][0] = 1; // one way to make sum 0 by excluding nums[0]
            if (nums[0] <= subsetTarget)
                dp[0][nums[0]] = 1; // one way to form nums[0]
        }

        // Fill the dp table
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= subsetTarget; target++) {
                int notTake = dp[ind - 1][target];
                int take = 0;
                if (nums[ind] <= target)
                    take = dp[ind - 1][target - nums[ind]];
                dp[ind][target] = take + notTake;
            }
        }

        return dp[n - 1][subsetTarget];
    }

    // Main function
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        int val = sum - target;

        // If invalid target sum, return 0
        if (val < 0 || val % 2 != 0) return 0;

        int subsetTarget = val / 2;

        // Method 1: Memoization
        // vector<vector<int>> dp(n, vector<int>(subsetTarget + 1, -1));
        // return ways(n - 1, nums, subsetTarget, dp);

        // Method 2: Tabulation
        return tabulation(nums, subsetTarget);
    }
};

/*
Time and Space Complexity:

Memoization:
- Time: O(n * target)
- Space: O(n * target) + O(n) recursion stack

Tabulation:
- Time: O(n * target)
- Space: O(n * target)

