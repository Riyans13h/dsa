/*
N-Queens Problem:
-----------------
Place 'n' queens on an n x n chessboard such that no two queens threaten each other.

Return all distinct solutions, where:
- 'Q' represents a queen
- '.' represents an empty cell

Constraints:
1 <= n <= 9

Examples:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."], ["..Q.","Q...","...Q",".Q.."]]

Input: n = 1
Output: [["Q"]]
*/

class Solution {
public:
    // Function to check if it's safe to place a queen at (row, col)
    bool isSafe(int row, int col, vector<vector<char>> &board, int n) {
        int x = row;
        int y = col;

        // Check the left side of the current row
        while (y >= 0) {
            if (board[x][y] == 'Q') return false;
            y--;
        }

        // Check the upper-left diagonal
        x = row;
        y = col;
        while (x >= 0 && y >= 0) {
            if (board[x][y] == 'Q') return false;
            x--;
            y--;
        }

        // Check the lower-left diagonal
        x = row;
        y = col;
        while (x < n && y >= 0) {
            if (board[x][y] == 'Q') return false;
            x++;
            y--;
        }

        // All checks passed — it's safe to place a queen
        return true;
    }

    // Converts the board of characters to a board of strings and stores it in the answer
    void addSolution(vector<vector<char>> &board, vector<vector<string>> &ans, int n) {
        vector<string> configuration;
        for (int i = 0; i < n; ++i) {
            string row = "";
            for (int j = 0; j < n; ++j) {
                row += board[i][j];  // Build string row
            }
            configuration.push_back(row);
        }
        ans.push_back(configuration);  // Store valid board configuration
    }

    // Recursive backtracking function to place queens column by column
    void solve(int col, vector<vector<char>> &board, vector<vector<string>> &ans, int n) {
        // Base case: all queens are placed successfully
        if (col == n) {
            addSolution(board, ans, n);
            return;
        }

        // Try placing a queen in each row of the current column
        for (int row = 0; row < n; ++row) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';               // Place queen
                solve(col + 1, board, ans, n);       // Recur for next column
                board[row][col] = '.';               // Backtrack: remove queen
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        // Initialize an n x n board with '.'
        vector<vector<char>> board(n, vector<char>(n, '.'));

        // Vector to store all valid configurations
        vector<vector<string>> ans;

        // Start solving from the first column
        solve(0, board, ans, n);

        return ans;
    }
};
