// Problem: Knapsack with Duplicate Items (Unbounded Knapsack)
// Given `val[]` and `wt[]` arrays representing the value and weight of each item,
// and a knapsack with capacity `W`,
// return the maximum profit you can make by picking items any number of times.

// Example 1:
// Input: val = [1, 1], wt = [2, 1], capacity = 3
// Output: 3
// Explanation: Pick the second item (wt = 1, val = 1) three times.

// Example 2:
// Input: val = [6, 1, 7, 7], wt = [1, 3, 4, 5], capacity = 8
// Output: 48
// Explanation: Pick the first item (wt = 1, val = 6) eight times.

class Solution {
public:

    // Memoization-based recursive function
    int profit(int ind, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {

        // Base case: for first item, we can pick it as many times as it fits
        if (ind == 0) {
            if (wt[0] <= capacity) 
                return (capacity / wt[0]) * val[0];
            else 
                return 0;
        }

        // Return memoized result if available
        if (dp[ind][capacity] != -1) 
            return dp[ind][capacity];

        // Not taking the current item
        int notTake = profit(ind - 1, capacity, val, wt, dp);

        // Taking the current item (can stay at same index since it's unbounded)
        int take = -1e9;
        if (wt[ind] <= capacity) {
            take = val[ind] + profit(ind, capacity - wt[ind], val, wt, dp);
        }

        // Memoize and return max profit
        return dp[ind][capacity] = max(take, notTake);
    }

    // Function that starts the recursion
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {

        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1)); // dp[i][w] = max profit using items[0..i] and capacity w

        return profit(n - 1, capacity, val, wt, dp);
    }

    // Tabulation (Bottom-up DP) version
    int knapSackTab(vector<int>& val, vector<int>& wt, int capacity) {

        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0)); // initialize all with 0

        // Base case for first item
        for (int w = 0; w <= capacity; ++w) {
            if (wt[0] <= w)
                dp[0][w] = (w / wt[0]) * val[0];
        }

        // Build the table iteratively
        for (int i = 1; i < n; ++i) {
            for (int w = 0; w <= capacity; ++w) {
                int notTake = dp[i - 1][w];
                int take = -1e9;
                if (wt[i] <= w)
                    take = val[i] + dp[i][w - wt[i]]; // i (not i-1) because items can repeat

                dp[i][w] = max(take, notTake);
            }
        }

        return dp[n - 1][capacity];
    }
};

/*
Time Complexity (Memoization): O(n * capacity)
  - Each state (i, capacity) is computed once and stored in dp

Time Complexity (Tabulation): O(n * capacity)
  - Filling the dp table of size n x capacity

Space Complexity:
  - Memoization: O(n * capacity) for dp table + O(n) recursion stack
  - Tabulation: O(n * capacity)

To optimize space, a 1D dp of size capacity+1 can be used in tabulation.
*/