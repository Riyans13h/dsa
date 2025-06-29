/*
LeetCode Problem: 17. Letter Combinations of a Phone Number (Medium)
----------------------------------------------------------------------
Given a string containing digits from 2–9 inclusive, return all possible 
letter combinations that the number could represent. Return the answer 
in any order.

A mapping of digits to letters (like on the telephone buttons) is given below.
Note: 1 does not map to any letters.

Examples:
---------
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Input: digits = ""
Output: []

Input: digits = "2"
Output: ["a","b","c"]

Constraints:
------------
- 0 <= digits.length <= 4
- digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public: 
    // Mapping digits to corresponding letters like on a phone keypad
    vector<string> map = {
        "",     // 0 (no letters)
        "",     // 1 (no letters)
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    // Recursive function to generate combinations
    void solve(int index, string digits, string output, vector<string>& ans) {
        // Base case: when the current index reaches the end of the digits string
        if (index >= digits.size()) {
            ans.push_back(output); // Add the formed combination to the result
            return;
        }

        // Get the digit at the current index and convert it to int
        int digi = digits[index] - '0';
        // Fetch corresponding characters from the map
        string s = map[digi];

        // Iterate through all characters mapped to the current digit
        for (int i = 0; i < s.size(); i++) {
            output.push_back(s[i]);                    // Choose a character
            solve(index + 1, digits, output, ans);     // Recurse for the next digit
            output.pop_back();                         // Backtrack to explore next option
        }
    }

    // Main function that sets up and starts the recursion
    vector<string> letterCombinations(string digits) {
        string output;          // To build each combination
        vector<string> ans;     // To store all combinations

        if (digits.size() == 0) return ans; // Edge case: empty input

        solve(0, digits, output, ans);      // Start recursion
        return ans;
    }
};
