# Transpose of a Matrix

## 📝 Problem Statement:
Given a 2D matrix `mat[][]`, compute its transpose.

> The **transpose** of a matrix is formed by converting all rows into columns and columns into rows.

---

## 🔍 Example 1:
**Input:**
mat = [
[1, 1, 1, 1],
[2, 2, 2, 2],
[3, 3, 3, 3],
[4, 4, 4, 4]
]

**Output:**
[
[1, 2, 3, 4],
[1, 2, 3, 4],
[1, 2, 3, 4],
[1, 2, 3, 4]
]


---

## 🧠 Approaches

### ✅ Brute Force — O(n × m) Time | O(n × m) Space
- Create a **new matrix** of dimensions `[cols][rows]`.
- For each element `mat[i][j]`, assign it to `transposed[j][i]`.
- Works for both **square and rectangular** matrices.

### ✅ Optimized (In-place for Square Matrices) — O(n²) Time | O(1) Space
- Only for **square matrices**.
- Swap `mat[i][j]` with `mat[j][i]` for all `i < j`.
- This reflects elements across the diagonal **without using extra space**.

---

## ⏱️ Time & Space Complexity

| Approach    | Time Complexity | Space Complexity | Notes                     |
|-------------|------------------|------------------|----------------------------|
| Brute Force | O(n × m)         | O(n × m)         | Works for all matrices     |
| Optimized   | O(n²)            | O(1)             | Only for square matrices   |

---

## 📚 Topics Covered:
- 2D Arrays
- Matrix Operations
- In-place Algorithms
