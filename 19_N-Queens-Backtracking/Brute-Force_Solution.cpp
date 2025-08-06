class Solution {
private:
    bool validate(vector<string>& board, int n) {
        int queens = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'Q') {
                    queens++;

                    for(int k = 0; k < n; k++) {
                        if(k != j && board[i][k] == 'Q') return false; // row
                        if(k != i && board[k][j] == 'Q') return false; // col
                    }
                    for(int r=i+1, c=j+1; r<n && c<n; r++, c++) if(board[r][c] == 'Q') return false;
                    for(int r=i+1, c=j-1; r<n && c>=0; r++, c--) if(board[r][c] == 'Q') return false;
                }
            }
        }
        return queens == n;
    }

    void solve(int k, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (k == 0) {
            if (validate(board, n)) {
                ans.push_back(board);
            }
            return;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    board[i][j] = 'Q';
                    solve(k - 1, board, ans, n);
                    board[i][j] = '.'; // backtrack
                }
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(n, board, ans, n);
        return ans;
    }
};
// Time Complexity: O(n!) (TLE-worst Time complexity)