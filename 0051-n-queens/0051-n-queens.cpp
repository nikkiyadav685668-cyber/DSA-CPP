class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col, int n) {

        // Check row
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        // Check column
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void nQueens(vector<string> &board, int row, int n,
                 vector<vector<string>> &ans) {

        // Base case
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try placing queen in every column
        for (int j = 0; j < n; j++) {

            if (isSafe(board, row, j, n)) {

                // Place queen
                board[row][j] = 'Q';

                // Move to next row
                nQueens(board, row + 1, n, ans);

                // Backtrack
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        nQueens(board, 0, n, ans);

        return ans;
    }
};