# N-Queens Problem: Three Approaches
This document explains three different approaches to solving the classic N-Queens problem, ranging from a naive brute-force method to a highly optimized backtracking solution.

### Problem Statement
The N-Queens puzzle is the problem of placing N chess queens on an N×N chessboard so that no two queens threaten each other. This means no two queens can share the same row, column, or diagonal.

## Approach 1: Brute-Force
This is the most naive approach. It generates every possible configuration of N queens on the board and then checks if the configuration is valid.

Concept: Place N queens on the board in all possible ways, then check each configuration to see if it's a valid solution.

Time Complexity: Exponential. Far too slow for anything but the smallest values of N.

Space Complexity: $$O(N^2)$$ for storing the board.

## Approach 2: Better (Standard Backtracking)
This is a much smarter approach. We use the insight that each row can only contain one queen. We place queens row by row, and "backtrack" as soon as we find that a path won't lead to a solution.

- Concept: Place one queen in each row. Before placing a queen, check if the spot is attacked by any previously placed queens. If it is, skip it. If not, place the queen and recurse to the next row.

- Time Complexity: $$O(N*N)$$. We explore roughly N valid placements, and for each placement, the `isSafe()` check takes $$O(N)$$ time.

Space Complexity: $$O(N^2)$$ for the board and recursion stack.

## Approach 3: Most Optimal (Backtracking with Hashing)
This approach optimizes the standard backtracking solution. The bottleneck is the isSafe() check. We can reduce its time from O(N) to O(1) by using extra arrays (or hash maps) to track which columns and diagonals are currently under attack.

- Concept: Use boolean arrays to keep track of attacked columns and diagonals. This makes checking for a safe spot an O(1) lookup operation.

- Time Complexity: $$O(N)$$. This is the most efficient time complexity for this type of solution.

- Space Complexity: $$O(N^2)$$ for the board, plus $$O(N)$$ for the hashing arrays.