## 🔢 Diagonal Sum Problem — Approach Explained

## 📘 Problem Statement
Given a square matrix of size n×n where it represent rows x columns, calculate the sum of elements on both the main diagonal and the anti-diagonal (secondary diagonal). The main diagonal runs from the top-left to the bottom-right, while the anti-diagonal runs from the top-right to the bottom-left.

**Note:** If the matrix has an odd size, the center element should only be counted once (it appears on both diagonals).

## 🧪 Example
Input:
    Matrix:  [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 9]]
    Size: 3×3

Output:
    Diagonal Sum: 25

## Explanation: 
    Main diagonal: 1 + 5 + 9 = 15
    Anti-diagonal: 3 + 5 + 7 = 15
    Total: 15 + 15 = 30
    But center element (5) is counted twice, so subtract it once: 30 - 5 = 25

## 1️⃣ Optimal Single-Pass Approach
## 💡 Idea
* Traverse the matrix only once using a single loop.

* For each row index i:
  - Add the main diagonal element: `matrix[i][i]`
  - Add the anti-diagonal element: `matrix[i][n-1-i]`
  - Use condition `i != n-1-i` to avoid double-counting the center element in odd-sized matrices.

* This approach is both time and space efficient.

## ⚙️ Complexity
 >Time: O(n) - Single pass through the matrix

 >Space: O(1) - Only using a single variable to store the sum

## 🔍 Key Insights
* **Main Diagonal:** Elements where row index equals column index (i == j)
* **Anti-Diagonal:** Elements where row index + column index equals n-1 (i + j == n-1)
* **Center Element:** In odd-sized matrices, the center element appears on both diagonals
* **Efficiency:** Single pass approach is optimal as we need to access each diagonal element exactly once

## 📝 Algorithm Steps
1. Initialize sum = 0
2. For i = 0 to n-1:
   - Add `matrix[i][i]` (main diagonal)
   - If `i != n-1-i`, add `matrix[i][n-1-i]` (anti-diagonal)
3. Return sum

## 🎯 Edge Cases Handled
* Empty matrix (n ≤ 0)
* Matrix of size 1×1
* Even-sized matrices (no center element)
* Odd-sized matrices (center element counted once)