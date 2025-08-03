partionDifferenceMin.cpp


/*
💡  Partition a Set Into Two Subsets With Minimum Absolute Sum Difference

🧠 Problem Statement:
You are given an array `nums` consisting of `n` integers. 
Partition the array into two subsets such that the **absolute difference** 
between the sums of the subsets is **minimized**.

Return the **minimum possible absolute difference** between the subset sums.

🔢 Example:
Input: nums = [1, 6, 11, 5]
Output: 1
Explanation: Subset1 = [1, 5, 6] = 12, Subset2 = [11] = 11, |12 - 11| = 1

🎯 Goal:
Minimize |sum(S1) - sum(S2)| where S1 and S2 are the two subsets.

👨‍💻 Approach: Subset Sum DP + Partition Logic (Tabulation)
*/

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        // Calculate the total sum of the array
        for (int num : nums) totalSum += num;

        // Tabulation DP for subset sum: dp[i][j] = true if sum j is possible using first i elements
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

        // Base Case: sum = 0 is always possible
        for (int i = 0; i < n; i++) dp[i][0] = true;

        // Base Case: first element alone can make sum = nums[0]
        if (nums[0] <= totalSum) dp[0][nums[0]] = true;

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            for (int sum = 1; sum <= totalSum; sum++) {
                bool notTake = dp[i - 1][sum];
                bool take = false;
                if (nums[i] <= sum) {
                    take = dp[i - 1][sum - nums[i]];
                }
                dp[i][sum] = take || notTake;
            }
        }

        // Check all sums up to totalSum/2 to find the best partition
        int minDiff = INT_MAX;
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            if (dp[n - 1][s1]) {
                int s2 = totalSum - s1;
                minDiff = min(minDiff, abs(s1 - s2));
            }
        }

        return minDiff;
    }
};

/*
🧠 Time Complexity:
- O(n * totalSum), where `n` is the number of elements and `totalSum` is the sum of all elements.

🧠 Space Complexity:
- O(n * totalSum) for the 2D DP table.
- Can be optimized to O(totalSum) using a 1D DP array.
*/
   