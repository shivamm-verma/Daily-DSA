# 140. 132 Pattern Detection

##  Problem Statement

Given an integer array `nums`, determine whether there exists a **132 pattern**.

A **132 pattern** is a subsequence of three integers `nums[i]`, `nums[j]`, `nums[k]` such that:
- i < j < k
- nums[i] < nums[k] < nums[j]

Return `true` if there is such a triplet, otherwise return `false`.

---

###  Examples:

**Input:** nums = [1, 2, 3, 4]  
**Output:** false  
**Explanation:** There is no such triplet that satisfies the pattern.

**Input:** nums = [3, 1, 4, 2]  
**Output:** true  
**Explanation:** The pattern 1 < 2 < 4 exists at indices (1, 3, 2).

**Input:** nums = [-1, 3, 2, 0]  
**Output:** true  
**Explanation:** The pattern -1 < 0 < 3 exists at indices (0, 3, 1).

---

##  Approaches

### 1. Naive Approach – Brute Force (O(n³) Time, O(1) Space)

- Use three nested loops to check every possible triplet (i, j, k).
- For each triplet, verify if `nums[i] < nums[k] < nums[j]` and `i < j < k`.
- Return `true` if any such pattern is found.

---

### 2. Better Approach – Keeping Track of Prefix Min (O(n²) Time, O(1) Space)

- For each `j`, track the smallest value to the left (`i`).
- For each `k > j`, check if a valid `i` exists with `nums[i] < nums[k] < nums[j]`.

---

### 3. Optimized Approach – Stack & Monotonic Traversal (O(n) Time, O(n) Space)

- Traverse the array from right to left.
- Use a stack to keep track of possible `nums[k]` values.
- Track the max `nums[k]` (called `third`) which could form the 132 pattern.
- If at any point, a number less than `third` is found, return `true`.

---

##  Topics Covered

- Greedy  
- Stack  
- Monotonic Stack  
- Sliding Window  
- Arrays

---

##  Status

- [x] Naive (Brute-force) logic added  
- [x] Prefix minimum logic added  
- [x] Stack-based optimized logic added

---