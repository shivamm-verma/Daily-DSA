## 🧭 Unique Paths Problem — Approaches Explained

---

## 📘 Problem Statement

You are given an `m x n` grid. You can only move either **down** or **right** at any point in time.

Your task is to determine the **total number of unique paths** from the **top-left** corner to the **bottom-right** corner.

---

## 🧪 Example

**Input:**

m = 3, n = 7

**Output:**

Number of Unique Paths: 28

perl
Copy
Edit

**Explanation:**

You must move down `m - 1 = 2` times and right `n - 1 = 6` times in any order. The total number of such unique sequences is:
C(8, 2) = 28
---

## 1️⃣ Brute Force Recursive Approach (Without Memoization)

### 💡 Idea
- Recursively move either down or right.
- If you reach the destination, return 1.
- If you go out of bounds, return 0.
- Time complexity is exponential due to overlapping subproblems.

### ⚙️ Complexity
> **Time:** O(2^(m+n))  
> **Space:** O(m + n) (Recursion Stack)

---

## 2️⃣ Top-Down DP (Memoization)

### 💡 Idea
- Store results of subproblems in a memoization table `dp[i][j]`.
- If `dp[i][j]` is already calculated, use it.
- Eliminates redundant recursive calls.

### ⚙️ Complexity
> **Time:** O(m × n)  
> **Space:** O(m × n) (Memo Table) + O(m + n) (Stack Space)

---

## 3️⃣ Bottom-Up DP (Tabulation)

### 💡 Idea
- Use a 2D DP table where `dp[i][j]` stores number of unique paths to `(i, j)`.
- Base case: `dp[0][0] = 1`.
- At each cell, move either from the top or left:  
  `dp[i][j] = dp[i-1][j] + dp[i][j-1]`

### ⚙️ Complexity
> **Time:** O(m × n)  
> **Space:** O(m × n)

---

## 4️⃣ Space Optimized DP (1D Array)

### 💡 Idea
- Only store the current row (or column) because the result at any point only depends on the current and previous values.
- Use a 1D array `dp[j]` and update in-place.

### ⚙️ Complexity
> **Time:** O(m × n)  
> **Space:** O(n)

---

## 5️⃣ Combinatorics Approach (Optimal)

### 💡 Idea
- From `(0, 0)` to `(m - 1, n - 1)` we need to make `(m - 1)` down and `(n - 1)` right moves.
- Total moves = `(m + n - 2)`
- Choose any `(m - 1)` down moves out of these:
Result = C(m + n - 2, m - 1)
= (m + n - 2)! / ((m - 1)! * (n - 1)!)



### ⚙️ Complexity
> **Time:** O(min(m, n))  
> **Space:** O(1)

---

## 🧪 Test Cases

| m | n | Output |
|---|---|--------|
| 3 | 7 | 28     |
| 3 | 2 | 3      |
| 7 | 3 | 28     |
| 3 | 3 | 6      |

---

## 🔚 Conclusion

- Recursive → Simple but slow.
- Memoization → Top-down optimization.
- Tabulation → Bottom-up DP.
- Space Optimization → Efficient for large inputs.
- Combinatorics → Fastest and most optimal.