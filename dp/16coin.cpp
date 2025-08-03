// Leetcode 518: Coin Change II
/*
Problem:
You are given an integer amount and an array of coins. 
Return the number of combinations that make up that amount. 
You may use an infinite number of each coin.

Example:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four combinations that make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
*/

class Solution {
public:
    // --------------------- MEMOIZATION ---------------------
    int minCoin(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: if only using the first coin type
        if (ind == 0) {
            if (amount % coins[0] == 0) return 1;
            else return 0;
        }

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = minCoin(ind - 1, amount, coins, dp);
        int take = 0;
        if (coins[ind] <= amount) {
            take = minCoin(ind, amount - coins[ind], coins, dp);
        }

        return dp[ind][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // ---------- MEMOIZATION ----------
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int memoAns = minCoin(n - 1, amount, coins, dp);

        // ---------- TABULATION ----------
        vector<vector<int>> tab(n, vector<int>(amount + 1, 0));

        // Base case: fill first row
        for (int amt = 0; amt <= amount; amt++) {
            if (amt % coins[0] == 0)
                tab[0][amt] = 1;
            else
                tab[0][amt] = 0;
        }

        // Build the table
        for (int ind = 1; ind < n; ind++) {
            for (int amt = 0; amt <= amount; amt++) {
                int notTake = tab[ind - 1][amt];
                int take = 0;
                if (coins[ind] <= amt)
                    take = tab[ind][amt - coins[ind]];
                tab[ind][amt] = take + notTake;
            }
        }

        // You can return either result
        return tab[n - 1][amount]; // or return memoAns;
    }
};
