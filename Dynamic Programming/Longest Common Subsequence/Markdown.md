## 🔗 Longest Common Subsequence (LCS) — Approaches Explained

---

## 📘 Problem Statement

Given two strings `text1` and `text2`, return the length of their **Longest Common Subsequence**.

A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.  
For example, `"ace"` is a subsequence of `"abcde"`, but `"aec"` is not.

---

## 🧪 Example

### Input:
text1 = "abcde"  
text2 = "ace"

### Output:
**3**

### Explanation:
The LCS is `"ace"` which has length **3**.

---

## 🔍 Key Observations

- This is a **2D Dynamic Programming** problem.
- At every step, we compare characters and decide:
  - If they match → include + move both indices.
  - If not → explore both skip options and take the max.

---

## 1️⃣ Brute Force Recursive Approach (Without Memoization)

### 💡 Idea
- Start from the end of both strings.
- If characters match: `1 + LCS(i-1, j-1)`
- Else: `max(LCS(i-1, j), LCS(i, j-1))`
- Base case: if either index is out of bounds, return 0.

### ⚙️ Complexity
> 🕒 Time: O(2^n)  
> 🧠 Space: O(n) (Recursion stack)

---

## 2️⃣ Top-Down DP (Memoization)

### 💡 Idea
- Use a 2D DP table `dp[i][j]` to store solutions to subproblems.
- Avoid redundant recursive calls.


### ⚙️ Complexity
> 🕒 Time: O(n × m)  
> 🧠 Space: O(n × m) (DP + recursion stack)

---

## 3️⃣ Bottom-Up DP (Tabulation)

### 💡 Idea
- Build a 2D table `dp[i][j]` iteratively.
- Start from base case (0s for empty strings).
- Fill the table using the recurrence relation.

### ⚙️ Complexity
> 🕒 Time: O(n × m)  
> 🧠 Space: O(n × m)

---

## 4️⃣ Space Optimized DP (1D Array)

### 💡 Idea
- Only the previous row is needed to compute the current row.
- Use two 1D arrays: `prev[]` and `curr[]`.

### ⚙️ Complexity
> 🕒 Time: O(n × m)  
> 🧠 Space: O(m)



