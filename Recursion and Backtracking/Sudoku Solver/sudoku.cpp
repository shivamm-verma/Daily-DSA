#include <bits/stdc++.h>
using namespace std;

bool is_safe(vector<vector<char>>& board, int row, int col, int val)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[i][col] == val) return false;
    }
    for(int j = 0; j < 9; j++)
    {
        if(board[row][j] == val) return false;
    }

    int starting_row = (row/3) * 3;
    int starting_col = (col/3) * 3;
    for(int i = starting_row; i <= starting_row+2; i++)
    {
        for(int j = starting_col; j <= starting_col+2; j++)
        {
            if(board[i][j] == val) return false;
        }
    }

    return true;
}

bool solve_sudoku(vector<vector<char>>& board, int row, int col)
{
    if(row == 9) return true;
    int next_row = row;
    int next_col = col + 1;
    if(next_col == 9)
    {
        next_row = row + 1;
        next_col = 0;
    } 

    if(board[row][col] != '.')
    {
        return solve_sudoku(board, next_row, next_col);
    }

    else
    {
        for(char val = '1'; val <= '9'; val++)
        {
            if(is_safe(board, row, col, val))
            {
                board[row][col] = val;
                if(solve_sudoku(board, next_row, next_col)) return true;
                board[row][col] = '.';
            }

        }
    }
        return false;
}

void solveSudoku(vector<vector<char>>& board) 
{
    solve_sudoku(board, 0, 0);
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    cout << "Initial Sudoku:\n";
    for (auto &row : board) {
        for (auto &cell : row) cout << cell << " ";
        cout << "\n";
    }

    if (solve_sudoku(board, 0, 0)) {
        cout << "\nSolved Sudoku:\n";
        for (auto &row : board) {
            for (auto &cell : row) cout << cell << " ";
            cout << "\n";
        }
    } else {
        cout << "No solution exists.\n";
    }
    return 0;
}


