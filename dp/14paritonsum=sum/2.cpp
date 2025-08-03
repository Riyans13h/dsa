pariton=sum/2
// 🔒 Problem: Partition Equal Subset Sum (Leetcode 416)
// Given a non-empty array `nums` containing only positive integers,
// determine if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

// ✅ Example:
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11]

// ✅ Constraints:
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

class Solution {
public:

    // 🔁 Memoization-based helper function
    bool check(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base Case: If target becomes 0, subset found
        if (target == 0) return true;

        // Base Case: If only one element left
        if (index == 0) return arr[0] == target;

        // Return memoized result if already computed
        if (dp[index][target] != -1) return dp[index][target];

        // Option 1: Do not include the current element
        bool notTake = check(index - 1, target, arr, dp);

        // Option 2: Include current element (only if it's <= target)
        bool take = false;
        if (arr[index] <= target) {
            take = check(index - 1, target - arr[index], arr, dp);
        }

        // Save result in DP table
        dp[index][target] = take || notTake;
        return dp[index][target];
    }

    // ✅ Tabulation based on above memoization
    bool tabulation(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Initialization:
        for (int i = 0; i < n; i++) dp[i][0] = true; // sum == 0 possible with any prefix (by taking nothing)
        if (nums[0] <= target) dp[0][nums[0]] = true; // first element alone can form its own value

        for (int index = 1; index < n; index++) {
            for (int t = 1; t <= target; t++) {
                bool notTake = dp[index - 1][t];
                bool take = false;
                if (nums[index] <= t) {
                    take = dp[index - 1][t - nums[index]];
                }
                dp[index][t] = take || notTake;
            }
        }
        return dp[n - 1][target];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int val : nums) totalSum += val;

        // If sum is odd, can't split into two equal subsets
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        // ---------- MEMOIZATION ----------
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return check(n - 1, target, nums, dp);

        // ---------- TABULATION ----------
        return tabulation(nums, target);
    }
};

/*
🧠 Time Complexity:
    - Memoization: O(n * target)
    - Tabulation:  O(n * target)
    where n = nums.size(), target = totalSum / 2

📦 Space Complexity:
    - Memoization: O(n * target) + O(n) recursion stack
    - Tabulation:  O(n * target)
    - Optimized Space Tabulation: O(target) possible with 1D dp
*/
