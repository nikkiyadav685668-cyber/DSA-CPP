class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == dig) {
                return false;
            }
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) {
                return false;
            }
        }

        // Check 3 x 3 box
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        for (int i = srow; i <= srow + 2; i++) {
            for (int j = scol; j <= scol + 2; j++) {
                if (board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {

        // Base case
        if (row == 9) {
            return true;
        }

        // Calculate next cell
        int nextRow = row;
        int nextCol = col + 1;

        if (nextCol == 9) {
            nextRow = row + 1;
            nextCol = 0;
        }

        // If cell is already filled
        if (board[row][col] != '.') {
            return helper(board, nextRow, nextCol);
        }

        // Try digits 1 to 9
        for (char dig = '1'; dig <= '9'; dig++) {

            if (isSafe(board, row, col, dig)) {

                // Place digit
                board[row][col] = dig;

                // Recursion
                if (helper(board, nextRow, nextCol)) {
                    return true;
                }

                // Backtrack
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};