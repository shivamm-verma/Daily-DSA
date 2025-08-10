# 🧩 Three Sum Problem

## 📘 Problem Statement

Given an array `nums` of integers, return all **unique triplets** `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `j != k`, and `i != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution must not contain duplicate triplets.

---

## 🧠 Approach

1. **Sort the array** to simplify duplicate handling and enable two-pointer traversal.
2. **Iterate** through the array with index `i`:
   - Skip duplicates for `i` to avoid repeated triplets.
3. For each `i`, use **two pointers**:
   - `j = i + 1` (start of subarray)
   - `k = nums.length - 1` (end of subarray)
4. Calculate the sum: `nums[i] + nums[j] + nums[k]`
   - If sum is `0`: store the triplet and move both pointers inward, skipping duplicates.
   - If sum is `< 0`: move `j` forward to increase the sum.
   - If sum is `> 0`: move `k` backward to decrease the sum.

This ensures all unique triplets are found efficiently.

---

## 📊 Example

**Input:**
nums = [-1, 0, 1, 2, -1, -4]

**Output:**
[[-1, -1, 2], [-1, 0, 1]]

**Explanation:**
- Triplets that sum to zero are:
  - `-1 + -1 + 2 = 0`
  - `-1 + 0 + 1 = 0`
- Duplicates are skipped to ensure uniqueness.

---

## ⏱️ Time Complexity

- **Sorting:** \( O(n \log n) \)
- **Two-pointer traversal:** \( O(n^2) \)
- **Overall:** \( O(n^2) \)

---

## 🧮 Space Complexity

- **Auxiliary space:** \( O(1) \) (excluding output list)
- **Output space:** Depends on number of valid triplets

---

## 📚 Topics Covered

- Sorting
- Two-pointer technique
- Array traversal
- Duplicate handling
- Brute-force optimization

---



