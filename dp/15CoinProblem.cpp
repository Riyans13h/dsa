/*
🧩  Problem: Coin Change

You are given an integer array `coins` representing coins of different denominations 
and an integer `amount` representing a total amount of money. 
Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

🔍 Example:
Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

------------------------------------------------
🔧 Memoization + Tabulation
*/

class Solution {
public:

    // 🔁 MEMOIZATION FUNCTION: Top-Down DP
    int minCoin(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: only one type of coin
        if (ind == 0) {
            if (amount % coins[0] == 0) 
                return amount / coins[0];
            else 
                return 1e9;  // Large number to represent infinity
        }

        // Return if already computed
        if (dp[ind][amount] != -1) return dp[ind][amount];

        // Not take current coin
        int notTake = 0 + minCoin(ind - 1, amount, coins, dp);

        // Take current coin (if possible)
        int take = 1e9;
        if (coins[ind] <= amount) {
            take = 1 + minCoin(ind, amount - coins[ind], coins, dp);
        }

        return dp[ind][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // 💾 STEP 1: Memoization
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = minCoin(n - 1, amount, coins, dp);
        if (ans != 1e9) return ans;

        // 📦 STEP 2: Tabulation (Bottom-Up DP)
        vector<vector<int>> tab(n, vector<int>(amount + 1, 1e9));

        // Base Case: fill the first row (only coins[0])
        for (int t = 0; t <= amount; ++t) {
            if (t % coins[0] == 0) tab[0][t] = t / coins[0];
        }

        // Fill rest of the table
        for (int ind = 1; ind < n; ++ind) {
            for (int t = 0; t <= amount; ++t) {
                int notTake = tab[ind - 1][t];
                int take = 1e9;
                if (coins[ind] <= t) {
                    take = 1 + tab[ind][t - coins[ind]];
                }
                tab[ind][t] = min(take, notTake);
            }
        }

        int result = tab[n - 1][amount];
        return result == 1e9 ? -1 : result;
    }
};

/*
🕒 Time Complexity (TC): O(n * amount)
     - where `n` is number of coin types and `amount` is the target amount

📦 Space Complexity (SC): O(n * amount)
     - for both memoization and tabulation arrays
     - can be optimized to O(amount) with space optimization
*/
