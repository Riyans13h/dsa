/*
LeetCode Problem: 216. Combination Sum III (Medium)
-----------------------------------------------------
Find all valid combinations of k numbers that sum up to n such that:
  - Only numbers from 1 to 9 are used.
  - Each number is used at most once.
  - Each combination should be unique (no duplicates).
  - Return all valid combinations in any order.

Examples:
----------
Input: k = 3, n = 7
Output: [[1,2,4]]

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]

Input: k = 4, n = 1
Output: []

Approach:
----------
We use backtracking (recursive DFS):
- At each level, try picking numbers from 1 to 9.
- Only move forward to higher indexes to avoid duplicates.
- Track current sum and size of combination.
- Add the combination to result if size == k and sum == n.
*/

class Solution {
public:
    void solve(int index, int k, int target, vector<vector<int>>& ans, vector<int>& output, vector<int> nums) {
        if (output.size() == k) {
            if (target == 0) {
                ans.push_back(output); // Valid combination
                return;
            } else return; // Size is k but sum doesn't match
        }

        for (int i = index; i < nums.size(); i++) {
            if (target < nums[i]) break; // No need to explore further if current number exceeds target

            int value = nums[i];
            target -= value;
            output.push_back(value);
            solve(i + 1, k, target, ans, output, nums); // Move to next index to avoid reuse
            target += value; // Backtrack
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> output;
        vector<vector<int>> ans;
        solve(0, k, n, ans, output, nums);
        return ans;
    }
};
