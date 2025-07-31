# ❓ Problem: Set Matrix Zeroes

Given an `m x n` integer matrix, if an element is `0`, set its **entire row and column** to `0` in-place.

---

### 📌 Example

**Input:**
matrix = [
[1, 2, 3],
[4, 0, 6],
[7, 8, 9]
]
**Output:**
[
[1, 0, 3],
[0, 0, 0],
[7, 0, 9]
]

---

## ✅ Brute Force Approach

### 🔍 Intuition
We traverse the matrix and **mark cells that need to be set to zero** using a placeholder value like `-1` (assuming `-1` doesn't already exist in the matrix). After marking, we go for a second pass to update all `-1` cells to `0`.

### 🧠 Explanation
1. Traverse the matrix.
2. If `matrix[i][j] == 0`, mark all `matrix[i][k]` and `matrix[k][j]` as `-1` (except if it's already `0`).
3. Do a second traversal to convert all `-1` to `0`.

### ⏱ Time Complexity:
O(m × n × (m + n)) — worst case for each zero, marking the row and column.

### 📦 Space Complexity:
O(1) — only using in-place marking.

---

## ✅ Better Approach

### 🔍 Intuition
Instead of marking in-place, maintain two arrays to **record which rows and columns** should be made zero.

### 🧠 Explanation
1. Create two arrays: `row[m]` and `col[n]` to track the zeros.
2. In the first pass, if `matrix[i][j] == 0`, mark `row[i] = 1` and `col[j] = 1`.
3. In the second pass, if `row[i] == 1` or `col[j] == 1`, set `matrix[i][j] = 0`.

### ⏱ Time Complexity:
O(m × n)

### 📦 Space Complexity:
O(m + n)

---

## ✅ Optimal Approach

### 🔍 Intuition
Use the **first row and column of the matrix itself as the markers** to avoid extra space.

### 🧠 Explanation
1. Use `matrix[0][j]` to mark columns, and `matrix[i][0]` to mark rows.
2. Use a **separate flag for the first column** (since `matrix[0][0]` overlaps).
3. First pass: mark the rows/columns.
4. Second pass (reverse direction): update elements based on markers.

### ⏱ Time Complexity:
O(m × n)

### 📦 Space Complexity:
O(1) — done in-place with no extra space.