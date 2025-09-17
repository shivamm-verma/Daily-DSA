## Problem: Sudoku Solver  

Write a program to solve a Sudoku puzzle by filling the empty cells.  

A Sudoku solution must satisfy the following rules:  
1. Each digit `1–9` must appear exactly once in each row.  
2. Each digit `1–9` must appear exactly once in each column.  
3. Each digit `1–9` must appear exactly once in each of the 9 sub-boxes of the grid.  

The empty cells are denoted by `'.'`.  

## 🧪 Example
Input(9X9 Board):
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]

Output:
[
  ["5","3","4","6","7","8","9","1","2"],
  ["6","7","2","1","9","5","3","4","8"],
  ["1","9","8","3","4","2","5","6","7"],
  ["8","5","9","7","6","1","4","2","3"],
  ["4","2","6","8","5","3","7","9","1"],
  ["7","1","3","9","2","4","8","5","6"],
  ["9","6","1","5","3","7","2","8","4"],
  ["2","8","7","4","1","9","6","3","5"],
  ["3","4","5","2","8","6","1","7","9"]
]


## Backtracking-Based Approach
## 💡 Idea
Backtracking tries to fill empty cells one by one with a candidate digit 1–9. For each empty cell:
1. Try a candidate digit that doesn't violate row, column, and 3×3-box constraints.
2. Place it and recursively attempt to fill the next empty cell.
3. If at any point no candidate leads to a solution, undo (backtrack) the last assignment and try the next candidate.
4. Continue until the board is filled or all possibilities are exhausted.
5. This approach is straightforward, easy to implement, and effective for standard 9×9 Sudoku because the constraint checks prune the search heavily.

## Generic Code
#include <vector>
using namespace std;

class SudokuSolver {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char val) {
        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == val) return false;
        }
        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == val) return false;
        }
        // Check 3x3 subgrid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val) return false;
            }
        }
        return true;
    }

    bool backtrack(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (isSafe(board, row, col, val)) {
                            board[row][col] = val;
                            if (backtrack(board)) return true;
                            board[row][col] = '.'; // undo
                        }
                    }
                    return false; // no valid number found
                }
            }
        }
        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};

## ⚙️ Complexity
 >Time complexity (worst-case): Exponential. Backtracking explores a search tree; a loose upper bound is O(9^(N)) where N is number of empty cells. In practice, constraints prune the search drastically for typical Sudoku puzzles.

 >Space complexity: O(N) for recursion and tracking empties, plus O(1) extra for the fixed-size row/col/box sets (constant 9×9). If bitmask optimizations used, memory remains O(1) additional.

## 🔍 Key Insights
1. Constraints prune heavily: Row/column/box checks eliminate many candidates early, so backtracking is practical for 9×9 Sudoku.

2. Order matters: Choosing the empty cell with the fewest legal candidates (minimum remaining value heuristic) reduces branching and speeds up solving.

3. Fast checks: Maintaining occupancy structures (sets or bitmasks) for rows, columns, and boxes makes validity checks O(1).

4. Deterministic filling: If any cell has only one possible digit, fill it immediately — this can be integrated into preprocessing or within recursion to reduce search.

5. Bitmasks help: Representing possible digits as bits (9-bit integers) makes intersection and candidate enumeration faster and memory friendly.

## 📝 Algorithm Steps
1. Parse input board. Build:
rows[9], cols[9], boxes[9] sets containing digits already present.
A list empties of coordinates for cells with '.'.

2. Backtracking recursion:
2.1 If no empties remain, success.
2.2 Choose next empty cell. (Prefer cell with fewest candidates.)
2.3 For each candidate digit:
2.3.1 Place digit, update rows, cols, boxes.
2.3.2 Recurse to solve remaining empties.
2.3.3 If recursion returns success, propagate True.
2.3.4 Otherwise undo placement (backtrack) and try next candidate.

Return solved board when recursion completes successfully; otherwise, the puzzle is unsolvable.



