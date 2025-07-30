# Set Matrix Zeroes — Approaches and Analysis

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

## 🧠 Brute Force Approach

### 🔍 Intuition:
- Loop through each cell of the matrix.
- When a cell contains `0`, mark its entire row and column for updating.
- To avoid accidentally marking other cells too early, we use a marker value (like `-1` or a custom flag) instead of directly setting them to `0`.

### 📖 Explanation:
1. Traverse the matrix.
2. When you find a `0`, mark all elements in its row and column with a special flag (e.g., `-1`).
3. After the traversal, go through the matrix again and convert all marked (`-1`) values to `0`.

⚠️ This approach is not safe if the matrix contains the marker value naturally.

### ⏱ Time Complexity:
- **O(N × M × (N + M))** — For each `0`, potentially marking an entire row and column.

### 📦 Space Complexity:
- **O(1)** — No extra space except constants.
  *(But potentially risky due to in-place flagging.)*

---

## 🚀 Better Approach

### 🔍 Intuition:
- Instead of changing the matrix immediately, keep track of the rows and columns that should be zeroed using extra arrays.

### 📖 Explanation:
1. Create two arrays:
   - `row[n]`: to mark rows that need to be zeroed.
   - `col[m]`: to mark columns that need to be zeroed.
2. Traverse the matrix:
   - If `matrix[i][j] == 0`, mark `row[i] = 1` and `col[j] = 1`.
3. Traverse the matrix again:
   - If either `row[i] == 1` or `col[j] == 1`, set `matrix[i][j] = 0`.

### ⏱ Time Complexity:
- **O(N × M)** — Two full traversals.

### 📦 Space Complexity:
- **O(N + M)** — Extra space for `row` and `col` arrays.

---

## 💎 Optimal Approach

### 🔍 Intuition:
- Use the matrix itself as the marker storage.
- Specifically, use the **first row** and **first column** to store information about rows and columns to be zeroed.
- Handle the first row and column carefully since they're used both as data and markers.

### 📖 Explanation:
1. Use `matrix[0][j]` and `matrix[i][0]` as markers for zeroing the `j`th column and `i`th row.
2. Use a flag `isFirstColZero` to track if the **first column** initially had any zeroes (since its data gets overwritten).
3. First pass:
   - Mark rows and columns that need to be zeroed using the first row and column.
4. Second pass:
   - Traverse the matrix from **bottom-right to top-left** to avoid using overwritten markers.
   - Use the marker values to set cells to `0`.
5. Finally:
   - Zero out the first row and/or first column if needed, based on flags.

### ⏱ Time Complexity:
- **O(N × M)** — Two passes through the matrix.

### 📦 Space Complexity:
- **O(1)** — No additional space; in-place modifications only.
