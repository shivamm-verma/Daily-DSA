# Problem Title: Word Search Puzzle

## Problem Statement
Given a 2D grid of letters and a target word, determine if the word exists in the grid.  
The word can be constructed from letters of sequentially adjacent cells (horizontally or vertically), and the same cell cannot be used more than once.

## Logic / Approach
1. Iterate through each cell as a potential starting point.  
2. Use DFS (Depth-First Search) to explore all 4 directions: up, down, left, and right.  
3. Mark visited cells temporarily to avoid revisiting them in the current path.  
4. Backtrack after exploring each path to restore the cell.  
5. Return `true` if any path forms the word, else return `false`.

## Time Complexity
O(M * N * 4^L)  
- M = number of rows in the grid  
- N = number of columns  
- L = length of the word  
Each cell can branch into 4 directions recursively.

## Space Complexity
O(L) recursion stack for DFS, where L is the length of the word.

## Test Cases

**Board:**
```
[['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']]
```
- Word: `"ABCCED"` → Output: `true`  
- Word: `"SEE"` → Output: `true`  
- Word: `"ABCB"` → Output: `false`  

## Conclusion
DFS + Backtracking systematically explores all paths starting from each cell.  
Temporary marking of visited cells prevents cycles, and backtracking restores the board.  
This guarantees that if the word exists in the grid, it will be found.
