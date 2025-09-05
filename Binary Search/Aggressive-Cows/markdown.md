# Aggressive Cows Problem

## Problem Statement
You are given an array of stall positions and an integer `k` representing the number of cows.  
The goal is to place the cows in the stalls such that the **minimum distance between any two cows** is maximized.

---

## Examples
**Input:**
stalls = [1, 2, 8, 4, 9]
cows = 3


**Output:**
3



**Explanation:**
- Place 1st cow at stall `1`
- Place 2nd cow at stall `4`
- Place 3rd cow at stall `8` or `9`  
The minimum distance between cows is **3**.

---

## Approaches

### 1. Brute Force
- Try all possible stall selections of size `k` and compute the minimum distance.
- Keep track of the maximum among them.

**Time Complexity:** `O(N^k)` (very high)  
**Space Complexity:** `O(1)`

---

### 2. Better Approach (Greedy + Linear Search)
- Sort the stalls.
- Use greedy placement of cows.
- Instead of binary searching the distance, linearly test each distance.

**Time Complexity:** `O(N^2)`  
**Space Complexity:** `O(1)`

---

### 3. Optimal Approach (Binary Search on Answer)
- Sort the stalls.
- Use **binary search** on the answer (distance).
- For each candidate distance `d`, check if we can place all cows with at least `d` spacing using a greedy placement function.
- Return the largest feasible distance.

**Time Complexity:**  
- Sorting: `O(N log N)`  
- Binary Search iterations: `O(log(maxDistance))`  
- Feasibility check: `O(N)`  
Overall → **`O(N log N + N log(maxDistance))`**

**Space Complexity:** `O(1)`

---

## Files in This Folder
- `brute_force.cpp / brute_force.java / brute_force.py`
- `better.cpp / better.java / better.py`
- `optimal.cpp / optimal.java / optimal.py`
- `markdown.md`

Each file demonstrates one approach to solve the problem.

---
