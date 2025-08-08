class Solution {
private:
    void solve(int row, vector<string>& board, vector<vector<string>>& ans, int n, 
               vector<bool>& leftRow, vector<bool>& upperDiagonal, vector<bool>& lowerDiagonal) {
        
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            bool isLeftRowSafe = !leftRow[col];
            bool isUpperDiagonalSafe = !upperDiagonal[n - 1 + col - row];
            bool isLowerDiagonalSafe = !lowerDiagonal[col + row];

            if (isLeftRowSafe && isUpperDiagonalSafe && isLowerDiagonalSafe) {
                board[row][col] = 'Q';
                leftRow[col] = true;
                upperDiagonal[n - 1 + col - row] = true;
                lowerDiagonal[col + row] = true;

                // for the next row
                solve(row + 1, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);

                // backtrack
                board[row][col] = '.';
                leftRow[col] = false;
                upperDiagonal[n - 1 + col - row] = false;
                lowerDiagonal[col + row] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        vector<bool> leftRow(n, false);
        vector<bool> upperDiagonal(2 * n - 1, false);
        vector<bool> lowerDiagonal(2 * n - 1, false);

        solve(0, board, ans, n, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};