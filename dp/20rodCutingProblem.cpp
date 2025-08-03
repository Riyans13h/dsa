// User function Template for C++

/*
Problem: Rod Cutting Problem

Given a rod of length `n` and an array `price[]` of size `n` where price[i] represents 
the price of a rod of length `i+1`, your task is to determine the maximum total value 
that can be obtained by cutting the rod into pieces.

Example:
Input: price = {2, 5, 7, 8}, n = 4
Output: 10
Explanation: Cut the rod into lengths 2 and 2 -> 5 + 5 = 10

--------------------------------------------------
Approach 1: Memoization (Top-Down DP)
--------------------------------------------------

Time Complexity:  O(n^2)
Space Complexity: O(n^2) for dp + O(n) recursion stack
*/

class Solution {
  public:
  
  // Recursive helper function with memoization
  int maxPrice(int ind, int n, vector<int>& price, vector<vector<int>>& dp) {
      if (ind == 1) return n * price[0]; // base case: use only piece of size 1
      if (dp[ind][n] != -1) return dp[ind][n];

      int notTake = maxPrice(ind - 1, n, price, dp); // skip current length
      int take = INT_MIN;
      if (ind <= n) {
          take = price[ind - 1] + maxPrice(ind, n - ind, price, dp); // take current length
      }

      return dp[ind][n] = max(take, notTake);
  }

  /*
  --------------------------------------------------
  Approach 2: Tabulation (Bottom-Up DP)
  --------------------------------------------------

  Time Complexity:  O(n^2)
  Space Complexity: O(n^2)
  */

  int cutRod(vector<int> &price) {
      int n = price.size();

      // ---------- Memoization Version ----------
      // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
      // return maxPrice(n, n, price, dp);

      // ---------- Tabulation Version ----------
      vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

      // Base case: only using piece of size 1
      for (int rodLen = 0; rodLen <= n; rodLen++) {
          dp[1][rodLen] = rodLen * price[0];
      }

      // Fill the DP table
      for (int ind = 2; ind <= n; ind++) {
          for (int rodLen = 0; rodLen <= n; rodLen++) {
              int notTake = dp[ind - 1][rodLen];
              int take = INT_MIN;
              if (ind <= rodLen) {
                  take = price[ind - 1] + dp[ind][rodLen - ind];
              }
              dp[ind][rodLen] = max(take, notTake);
          }
      }

      return dp[n][n]; // maximum price for full rod using all sizes
  }
};
