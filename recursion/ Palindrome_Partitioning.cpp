/*
LeetCode Problem 131: Palindrome Partitioning (Medium)
-------------------------------------------------------
Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitionings of s.

Examples:
---------
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Input: s = "a"
Output: [["a"]]

Constraints:
------------
- 1 <= s.length <= 16
- s contains only lowercase English letters.
*/

class Solution {
public:
    // Helper function to check if substring s[index...i] is a palindrome
    bool isPalindrome(string s, int index, int i) {
        while (index <= i) {
            if (s[index] != s[i]) return false;  // Characters mismatch
            index++;
            i--;
        }
        return true;  // It's a palindrome
    }

    // Recursive backtracking function to generate all valid partitions
    void solvePalindrome(int index, vector<string>& output, vector<vector<string>>& ans, string s) {
        // If we have reached the end of the string, current partition is complete
        if (index == s.size()) {
            ans.push_back(output);  // Store the current valid partition
            return;
        }

        // Try all possible substrings starting from 'index'
        for (int i = index; i < s.size(); i++) {
            // If s[index...i] is a palindrome, we can include it in the partition
            if (isPalindrome(s, index, i)) {
                // Add the valid substring to current output
                output.push_back(s.substr(index, i - index + 1));

                // Recur for the remaining substring
                solvePalindrome(i + 1, output, ans, s);

                // Backtrack: remove the last added substring
                output.pop_back();
            }
        }
    }
    int main(){
    // Main function to return all palindrome partitions of string s
    vector<vector<string>> partition(string s) {
        vector<string> output;             // Stores current partition being built
        vector<vector<string>> ans;        // Final result containing all partitions
        solvePalindrome(0, output, ans, s); // Start the recursive backtracking
        return ans;
    }
}
};
