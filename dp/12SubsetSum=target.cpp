
/*
🔷 Problem: Subset Sum Problem

Given an array `arr[]` of non-negative integers and an integer `sum`, 
check whether there exists a subset of the array whose sum is equal to `sum`.

📥 Input:
- arr: vector of integers
- sum: target value

📤 Output:
- Return true if there exists a subset with sum equal to the given `sum`, else return false.

🔍 Example:
Input: arr = [3, 34, 4, 12, 5, 2], sum = 9
Output: true
Explanation: 4 + 5 = 9 is a valid subset.

----------------------------------------------------
Approach 1: Memoization (Top-Down DP)
Approach 2: Tabulation (Bottom-Up DP)
----------------------------------------------------

🧠 Time Complexity:
- Memoization: O(N * sum)
- Tabulation:  O(N * sum)

🧠 Space Complexity:
- Memoization: O(N * sum) + Recursion Stack
- Tabulation:  O(N * sum)

*/

class Solution {
public:

    // 🔹 Memoization (Top-Down DP)
    bool check(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;                       // ✅ Base case: found subset
        if (index == 0) return arr[0] == target;            // ✅ Base case: check only one element

        if (dp[index][target] != -1) return dp[index][target];  // 🔁 Return memoized result

        bool notTake = check(index - 1, target, arr, dp);   // ❌ Not including current element
        bool take = false;
        if (arr[index] <= target) {
            take = check(index - 1, target - arr[index], arr, dp); // ✅ Include current if possible
        }

        dp[index][target] = take || notTake;                // 📝 Store and return result
        return dp[index][target];
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        // 🧠 Memoization table: dp[i][j] = true/false if sum 'j' is possible using first 'i' elements
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        // return check(n - 1, sum, arr, dp);  // 🔄 Uncomment to use Memoization

        // -----------------------------------------------------------------
        // 🧾 Tabulation (Bottom-Up DP) - based on memoization structure
        // -----------------------------------------------------------------
        vector<vector<bool>> tab(n, vector<bool>(sum + 1, false));

        // 🔸 Base Case Initialization:
        for (int i = 0; i < n; i++) tab[i][0] = true;           // sum = 0 is always possible
        if (arr[0] <= sum) tab[0][arr[0]] = true;               // Only the first element

        // 🔁 DP Table Filling
        for (int index = 1; index < n; index++) {
            for (int target = 1; target <= sum; target++) {
                bool notTake = tab[index - 1][target];          // Don't pick current
                bool take = false;
                if (arr[index] <= target) {
                    take = tab[index - 1][target - arr[index]]; // Pick current
                }
                tab[index][target] = take || notTake;           // Store result
            }
        }

        return tab[n - 1][sum]; // ✅ Final result
    }
};
