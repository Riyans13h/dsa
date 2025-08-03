// Problem:
// Given two strings `text1` and `text2`, return the length of their Longest Common Subsequence (LCS).
// A subsequence is a sequence that appears in the same relative order but not necessarily contiguous.
// Example:
// Input: text1 = "abcde", text2 = "ace"
// Output: 3 (The LCS is "ace")

class Solution {
public:

    // ---------------- Memoization Approach (Top-down) ----------------
    // Helper function for computing LCS recursively with memoization
    int lcsMemo(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        // Base case: if any index goes negative, no subsequence
        if (i < 0 || j < 0) return 0;

        // If already computed, return from dp table
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, move diagonally
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + lcsMemo(i - 1, j - 1, s1, s2, dp);
        } 
        // Else, check by skipping one character from either string
        else {
            return dp[i][j] = max(
                lcsMemo(i - 1, j, s1, s2, dp),
                lcsMemo(i, j - 1, s1, s2, dp)
            );
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        // ---------------- Memoization DP table ----------------
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        int memoAnswer = lcsMemo(n1 - 1, n2 - 1, text1, text2, dp);  // Not returned, but computed

        // ---------------- Tabulation Approach (Bottom-up) ----------------
        vector<vector<int>> tab(n1 + 1, vector<int>(n2 + 1, 0));

        // Base case already handled (0th row and column are initialized to 0)
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    tab[i][j] = 1 + tab[i - 1][j - 1];
                } else {
                    tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
                }
            }
        }

        // Return the final result from the bottom-right of the table
        return tab[n1][n2];
    }
};

/*
Time Complexity:
- Memoization: O(n1 * n2)
- Tabulation: O(n1 * n2)

Space Complexity:
- Memoization: O(n1 * n2) for dp + O(n1 + n2) recursion stack
- Tabulation: O(n1 * n2)

Further Optimization:
- You can reduce space to O(n2) using two 1D arrays since we only need the previous row.

This approach ensures both memoization and tabulation are demonstrated clearly.
*/
