
# 🎒 0/1 Knapsack Problem — Tabulation, Memoization & Brute Force

## 📘 Problem Statement
Given weights and values of `n` items, and a knapsack of capacity `W`, find the maximum value that can be put in the knapsack without exceeding the capacity. Each item can be picked **at most once**.

---

## 💡 Core Idea
At every item, you have 2 choices:
1. **Include it** if its weight is ≤ remaining capacity.
2. **Exclude it**.

You choose the option that gives you the maximum value.

---

## 🧪 Example
**Input:** `weights = [1, 3, 4, 5]`, `values = [10, 40, 50, 70]`, `W = 8`  
**Output:** `110` (Pick item-1 and item-3)

---

## 🔁 1. Brute Force Approach (Recursive)

### 💡 Idea
- Try **every possible combination** of including or excluding each item.
- At each item, you have **two choices**:
  1. **Include** the item (if it fits in the remaining capacity).
  2. **Exclude** the item.
- The goal is to **explore all combinations** and return the one with the **maximum total value** without exceeding the capacity.


### ▶️ Pseudocode
```
function knapsack(index, capacity):
    if index == 0:
        if weights[0] <= capacity:
            return values[0]
        return 0

    exclude = knapsack(index - 1, capacity)
    include = 0
    if weights[index] <= capacity:
        include = values[index] + knapsack(index - 1, capacity - weights[index])

    return max(include, exclude)
```

### ⏱ Time Complexity: `O(2^n)`  
### 🧠 Space Complexity: `O(n)` (recursive stack)

### ⚠️ Why It's Inefficient
- The same subproblems are recalculated multiple times.
- **Exponential number of calls** due to the binary decision tree (include/exclude) for each item.



---

## 🧠 2. Memoization Approach (Top-down DP)

### 💡 Idea
- This is an optimization over brute force.
- Use a **2D array dp[index][capacity]** to **cache results** of subproblems.
- If we’ve already computed the solution for a given index and capacity, we just **return it** instead of recalculating.


### ▶️ Pseudocode
```
function knapsack(index, capacity, dp):
    if index == 0:
        if weights[0] <= capacity:
            return values[0]
        return 0

    if dp[index][capacity] != -1:
        return dp[index][capacity]

    exclude = knapsack(index - 1, capacity, dp)
    include = 0
    if weights[index] <= capacity:
        include = values[index] + knapsack(index - 1, capacity - weights[index], dp)

    dp[index][capacity] = max(include, exclude)
    return dp[index][capacity]
```

### ⏱ Time Complexity: `O(n * W)`  
### 🧠 Space Complexity: `O(n * W)` + recursion stack

### ✅ Why It’s Better
- **Avoids recomputation** of overlapping subproblems.
- Reduces time complexity from `O(2^n)` to `O(n * W)`.
- Still uses recursion but adds **memoization** to store previously solved cases.


---

## 📊 3. Tabulation Approach (Bottom-up DP)

### 💡 Idea
- This is an **iterative version** of memoization.
- We create a 2D `dp` table where:
  - `dp[i][w]` represents the **maximum value** that can be obtained using the first `i` items and capacity `w`.
- We build the table **from smaller subproblems to larger ones**.


### ▶️ Pseudocode
```
function knapsack(n, capacity):
    dp = array of size (n+1) x (capacity+1) filled with 0

    for i in range(1 to n):
        for w in range(0 to capacity):
            exclude = dp[i-1][w]
            include = 0
            if weights[i-1] <= w:
                include = values[i-1] + dp[i-1][w - weights[i-1]]
            dp[i][w] = max(include, exclude)

    return dp[n][capacity]
```

### ⏱ Time Complexity: `O(n * W)`  
### 🧠 Space Complexity: `O(n * W)`

### ✅ Advantages
- No recursion stack → **more memory-efficient** for large input sizes.
- Efficient and scalable.


---

## 🚀 4. Space-Optimized DP

### 💡 Idea
- This is an **optimized version of Tabulation**.
- Instead of maintaining a `2D dp[n+1][capacity+1]` table, we use a **1D array `dp[capacity+1]`**.
- We update `dp[w]` from **right to left** to ensure correctness without overwriting values needed for the current iteration.

### ▶️ Pseudocode (Space-Optimized 0/1 Knapsack)

```
function knapsack(n, capacity):
    dp = array of size (capacity + 1) filled with 0

    for i from 0 to n - 1:
        for w from capacity down to weights[i]:
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]])

    return dp[capacity]
```


### ⏱ Time Complexity: `O(n * W)`  
### 🧠 Space Complexity: `O(W)`

### ✅ Advantages
- Uses **less memory** than both memoization and tabulation.
- Very efficient for large input constraints when only the final result is needed.

---

## ✅ Summary

| Approach         | Time Complexity | Space Complexity | Notes                                |
|------------------|------------------|------------------|---------------------------------------|
| Brute Force      | O(2^n)           | O(n)             | Exponential time                      |
| Memoization      | O(n * W)         | O(n * W)         | Top-down + cache                      |
| Tabulation       | O(n * W)         | O(n * W)         | Bottom-up, avoids recursion           |
| Space-Optimized  | O(n * W)         | O(W)             | Best memory efficiency, bottom-up     |

---

## 🏁 Conclusion

The 0/1 Knapsack problem is a classic example to understand and apply dynamic programming techniques. Throughout this guide, we explored four major approaches:

1. **Brute Force** – Simple but inefficient, with exponential time complexity.
2. **Memoization (Top-Down DP)** – Optimizes recursion with caching; reduces redundant calculations.
3. **Tabulation (Bottom-Up DP)** – Iteratively builds up the solution; avoids recursion stack.
4. **Space-Optimized DP** – Reduces space from `O(n * W)` to `O(W)` by using a 1D array.

By understanding the transition from brute force to optimized approaches, you can efficiently solve many real-world problems that involve **decision making under constraints**.

> 🚀 **Always analyze problem constraints before choosing the approach**:
> - Use **memoization** for easier transition from recursion.
> - Use **tabulation or space optimization** when input sizes are large and performance matters.

---

