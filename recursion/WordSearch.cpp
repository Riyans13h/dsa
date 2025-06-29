/*
LeetCode Problem: 79. Word Search (Medium)
-------------------------------------------
Given an m x n grid of characters `board` and a string `word`, return true 
if `word` exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Examples:
---------
Input: board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]], 
       word = "SEE"
Output: true

Constraints:
------------
- 1 <= m, n <= 6
- 1 <= word.length <= 15
- m == board.length, n == board[i].length
*/

class Solution {
public:
    // Recursive helper function using DFS and backtracking
    bool solve(int index, int i, int j, int m, int n, vector<vector<char>>& board, string word) {
        // Base case: all characters matched
        if (index == word.size()) return true;

        // Boundary and character check
        if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == word[index]) {
            char temp = board[i][j];
            board[i][j] = '$';  // mark visited

            // Trace recursion path
            cout << "Matched '" << temp << "' at (" << i << "," << j << "), index: " << index << "\n";

            bool found = (
                solve(index + 1, i - 1, j, m, n, board, word) ||
                solve(index + 1, i + 1, j, m, n, board, word) ||
                solve(index + 1, i, j - 1, m, n, board, word) ||
                solve(index + 1, i, j + 1, m, n, board, word)
            );

            board[i][j] = temp;  // backtrack
            return found;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // Try each cell as starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (solve(0, i, j, m, n, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};
