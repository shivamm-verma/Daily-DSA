## ✂️ Rod Cutting Problem — Approaches Explained

---

## 📘 Problem Statement

You are given a rod of length `n` and an array `price[]` of size `n` where `price[i]` denotes the price of a rod of length `i+1`.

Your task is to determine the **maximum total price obtainable** by cutting the rod and selling the pieces in such a way that the total length of the pieces is `n`.

**Note:** You can cut the rod into as many pieces as you want, and you can use the same piece length multiple times.

---

## 🧪 Example

### Input:
Price: [1, 5, 8, 9, 10, 17, 17, 20]        Maximum Obtainable Price: 22


### Explanation:
- Cut the rod into lengths 2 and 6.  
- Price = 5 (for length 2) + 17 (for length 6) = **22**

---

## 🧠 Relation to Unbounded Knapsack

- Each rod length is like an item.
- We can choose an item (length) multiple times → **unbounded**.
- `wt[i] = i+1`, `val[i] = price[i]`

---

## 1️⃣ Brute Force Recursive Approach (Without Memoization)

### 💡 Idea
- At every index:
  - **Take** the piece (stay at same index since unlimited cuts allowed).
  - **Not take** the piece (move to previous index).
- Base case: only one piece length left → take as many as possible if it fits.

### ⚙️ Complexity
> 🕒 Time: O(2^n)  
> 🧠 Space: O(n) (recursion stack)

---

## 2️⃣ Top-Down DP (Memoization)

### 💡 Idea
- Store solutions to subproblems in a 2D `dp[ind][len]` table.
- Prevents recomputation of overlapping subproblems.

### ⚙️ Complexity
> 🕒 Time: O(n × n)  
> 🧠 Space: O(n × n) (DP + stack space)

---

## 3️⃣ Bottom-Up DP (Tabulation)

### 💡 Idea
- Use a 2D table `dp[i][length]` where each cell stores the maximum price.
- Build from base case (only using first rod length).

### ⚙️ Complexity
> 🕒 Time: O(n × n)  
> 🧠 Space: O(n × n)

---

## 4️⃣ Space Optimized DP (1D Array)

### 💡 Idea
- Instead of 2D table, use a 1D `dp[length]`.
- Update current state using previous results (same row update allowed in unbounded case).

### ⚙️ Complexity
> 🕒 Time: O(n × n)  
> 🧠 Space: O(n)

