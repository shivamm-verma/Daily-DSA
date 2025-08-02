# 🧗‍♂️ Problem: Climbing Stairs

Given `n` steps, you can climb either `1` or `2` steps at a time. Your task is to find how many distinct ways you can climb to the top.

---

### 📌 Example

**Input:** `n = 5`  
**Output:** `8`  
**Explanation:** There are 8 ways to climb 5 steps are:
- 1+1+1+1+1
- 1+1+1+2
- 1+1+2+1
- 1+2+1+1
- 2+1+1+1
- 2+2+1
- 2+1+2
- 1+2+2


**Input:** `n = 2`
**Output:** `2`
**Explanation:** There are 2 ways to climb 2 steps are:
- 1+1
- 2 

---

## ✅ Brute Force (Recursive)

### 🔍 Intuition
Try all combinations of taking 1 or 2 steps recursively.

### ⏱ Time Complexity:
`O(2^n)` — exponential due to overlapping subproblems.

### 📦 Space Complexity:
`O(n)` — recursion stack.


---

## ✅ Better Approach (Top-Down with Memoization)

### 🔍 Intuition
Use a DP array to store intermediate results (memoization).Instead of calling multiple same sub problems store the results and use them.

### ⏱ Time Complexity:
`O(n)`

### 📦 Space Complexity:
`O(n)`

---


## ✅ Most Optimal (Space-Optimized)

### 🔍 Intuition
Just track the last two results instead of the full DP array.

### ⏱ Time Complexity:
`O(n)`

### 📦 Space Complexity:
`O(1)`


---

## 📌 Summary
```text
+------------------+------------------+------------------+
| Approach         | Time Complexity  | Space Complexity |
+------------------+------------------+------------------+
| Brute Force      | O(2^n)           | O(n)             |
| Memoization      | O(n)             | O(n)             |
| Space-Optimized  | O(n)             | O(1)             |
+------------------+------------------+------------------+