class Solution {
private:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // left row
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') return false;
        }
        
        // upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
             if (board[i][j] == 'Q') return false;
        }
        
        // vertical
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        return true;
    }

    void solve(int row, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(row + 1, board, ans, n);
                
                // backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, board, ans, n);
        return ans;
    }
};