# ✍️ Word Wrap Problem — Brute Force, Memoization & DP

## 📘 Problem Statement
Given an array `arr[]` of size `n` representing the lengths of words and a line width `k`, arrange the words in such a way that the total cost is minimized.  
The cost of putting words from index `i` to `j` on one line is: cost = (k - total_length)^2
(where `total_length` includes spaces between words, except the last line which has cost = 0).

---

## 💡 Core Idea
At every word, you have **two choices**:
1. **Wrap here** → Move to the next line and pay the cost for unused spaces.
2. **Continue** → Keep adding words until line length exceeds `k`.

The goal is to **minimize the sum of costs** across all lines.

---

## 🧪 Example
**Input:** `arr = [3, 2, 2, 5]`, `k = 6`  
**Output:** `10`  

**Explanation:**  
- Line 1 → words (3, 2) → length = 3+1+2 = 6 → cost = (6-6)^2 = 0  
- Line 2 → words (2) → length = 2 → cost = (6-2)^2 = 16  
- Line 3 → words (5) → last line → cost = 0  
→ Total = 16 → **Optimal rearrangement reduces cost to 10**.

---

## 🔁 1. Brute Force Approach (Recursive)

### 💡 Idea
- Try **all possible places** to insert line breaks.
- At each word, either:
  1. Start a new line.
  2. Continue on the same line (if it fits).
- Take the **minimum total cost**.

### ▶️ Pseudocode
function solve(i, arr, k):
if i == n:
return 0
min_cost = ∞
line_length = -1

for j in range(i, n):
    line_length += arr[j] + 1
    if line_length > k: break

    if j == n-1:
        cost = 0
    else:
        cost = (k - line_length)^2 + solve(j+1, arr, k)

    min_cost = min(min_cost, cost)

return min_cost


### ⏱ Time Complexity: `O(2^n)`  
### 🧠 Space Complexity: `O(n)` (recursion stack)

---

## 🧠 2. Memoization Approach (Top-down DP)

### 💡 Idea
- Store results of subproblems in a DP array `dp[i]` = min cost from word `i` to `n-1`.
- Avoids recalculating the same range multiple times.

### ▶️ Pseudocode
function solve(i, arr, k, dp):
if i == n: return 0
if dp[i] != -1: return dp[i]
min_cost = ∞
line_length = -1

for j in range(i, n):
    line_length += arr[j] + 1
    if line_length > k: break

    if j == n-1:
        cost = 0
    else:
        cost = (k - line_length)^2 + solve(j+1, arr, k, dp)

    min_cost = min(min_cost, cost)

dp[i] = min_cost
return dp[i]


### ⏱ Time Complexity: `O(n^2)`  
### 🧠 Space Complexity: `O(n)` + recursion stack

---

## 📊 3. Tabulation Approach (Bottom-up DP)

### 💡 Idea
- Build DP iteratively.
- `dp[i]` = minimum cost to arrange words from `i` to `n-1`.
- Compute from the **end to the beginning**.

### ▶️ Pseudocode
function wordWrap(arr, n, k):
dp = array of size n+1 filled with ∞
dp[n] = 0
for i from n-1 down to 0:
    line_length = -1
    for j from i to n-1:
        line_length += arr[j] + 1
        if line_length > k: break

        if j == n-1:
            cost = 0
        else:
            cost = (k - line_length)^2 + dp[j+1]

        dp[i] = min(dp[i], cost)

return dp[0]

### ⏱ Time Complexity: `O(n^2)`  
### 🧠 Space Complexity: `O(n)`

---

## ✅ Summary

| Approach         | Time Complexity | Space Complexity | Notes                                 |
|------------------|-----------------|------------------|----------------------------------------|
| Brute Force      | O(2^n)          | O(n)             | Explores all breaks, very slow         |
| Memoization      | O(n^2)          | O(n) + recursion | Optimizes by caching results           |
| Tabulation       | O(n^2)          | O(n)             | Iterative, efficient, no recursion     |

---

## 🏁 Conclusion

The **Word Wrap Problem** demonstrates how **Dynamic Programming** can optimize exponential recursive solutions.  
- **Brute Force** → Impractical for large input.  
- **Memoization** → Reduces time to quadratic by avoiding recomputation.  
- **Tabulation** → Most efficient and avoids recursion.  

> 🚀 Always prefer **Tabulation DP** for real-world implementations since it’s iterative, clean, and avoids stack overflows.

---
