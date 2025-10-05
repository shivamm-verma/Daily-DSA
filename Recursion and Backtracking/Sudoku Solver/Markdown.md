## ✅ DSA Question: Solve the Sudoku game by filling emmpty cells

### 🧠 Problem  
Write a program to solve a Sudoku puzzle by filling the empty cells.  

A Sudoku solution must satisfy the following rules:  
1. Each digit `1–9` must appear exactly once in each row.  
2. Each digit `1–9` must appear exactly once in each column.  
3. Each digit `1–9` must appear exactly once in each of the 9 sub-boxes of the grid.  

The empty cells are denoted by `'.'`.  
**Examples:**  
- Input:
  ```
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
  ```
- Output:
  ```
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
  ```

---

## 🧭 Approach

1.  Parse input board:  
   - Build `rows[9]`, `cols[9]`, `boxes[9]` sets containing digits already present.  
   - A list empties of coordinates for cells with `.`.

2. Backtracking recursion:  
   - If no empties remain, success.
   - Choose next empty cell. (Prefer cell with fewest candidates.)
   - For each candidate digit:
      - Place digit, update rows, cols, boxes.
      - Recurse to solve remaining empties.
      - If recursion returns success, propagate True.
      - Otherwise undo placement (backtrack) and try next candidate.
        
3. Return solved board when recursion completes successfully; otherwise, the puzzle is unsolvable.
---

## 🔁 Generic Logic (Pseudocode)
```plaintext
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
```

## ⏱️ Complexities
 > Time Complexity
**O(9^(N))** — where N is number of empty cells

> Space Complexity
**O(1)** — constant space; no extra space used except pointers.


