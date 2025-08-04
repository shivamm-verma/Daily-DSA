# ✅ Longest Consecutive Sequence in an Array – Explained
=========================================================

Given an array `nums` of `n` integers, return the length of the longest sequence of consecutive integers. The integers can appear in **any order**.

---

## 🧪 Examples

- Input: `nums = [100, 4, 200, 1, 3, 2]`  
  Output: `4`  
  Explanation: The longest sequence is `[1, 2, 3, 4]`

- Input: `nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]`  
  Output: `9`  
  Explanation: The sequence is `[0, 1, 2, 3, 4, 5, 6, 7, 8]`

- Input: `nums = [1, 9, 3, 10, 4, 20, 2]`  
  Output: `4`  
  Explanation: Sequence is `[1, 2, 3, 4]`

---

## 🚀 Problem Statement

You are given an unsorted array of integers.  
Your task is to return the length of the **longest sequence** of consecutive elements.

---

## 🔍 BRUTE FORCE APPROACH

### 🧠 Intuition

For each number `x` in the array, we check if the next numbers `x+1`, `x+2`, ... exist in the array.  
We do this for **every** element in the array and track the length of the longest chain found.

### 🛠️ Approach

1. Iterate through each element `x` in `nums`
2. For every `x`, search for `x+1`, `x+2`, etc., using linear search
3. Count the chain length until the next number is not found
4. Track the **maximum** length encountered

### ⏱️ Complexity

- Time: **O(N³)**  
  For each element, we may scan the array linearly multiple times

- Space: **O(1)**  
  No extra data structures used

---

## ⚡ OPTIMAL APPROACH (Using Set)

### 🧠 Intuition

Instead of blindly checking for sequences from all numbers,  
we start only from elements that **do not** have a previous consecutive (`x - 1`) — these are potential starting points.

Using a `Set` helps with constant time lookup.

### 🛠️ Approach

1. Insert all elements into a set
2. For each number `x` in the set:
   - If `x - 1` does not exist in the set, it's the **start** of a sequence
   - Count how many numbers `x+1`, `x+2`, ... exist
3. Track the **maximum** count

### ⏱️ Complexity

- Time: **O(N)** on average  
  Insertions + at most 2xN lookups (each number is checked once)
  
- Space: **O(N)**  
  Due to the set used for quick lookups

> 🔎 Note: If using a `set` with `O(logN)` operations (e.g., in C++), time becomes `O(NlogN)`

---

## ✅ Pseudocode

function longestConsecutive(nums):
put all nums into a set
maxLength = 0
for each num in set:
    if num - 1 not in set:
        length = 1
        while num + length in set:
            length += 1
        maxLength = max(maxLength, length)

return maxLength


---

## 🔁 Summary

| Approach          | Time Complexity | Space Complexity | Notes                                |
|------------------|------------------|------------------|--------------------------------------|
| Brute Force       | O(N³)            | O(1)             | Inefficient, avoids extra space      |
| Optimal (Set) ✅  | O(N) avg         | O(N)             | Efficient using hashing and skipping |

---

## 📌 Extra Test Cases

- Input: `[]` → Output: `0`  
- Input: `[1, 2, 0, 1]` → Output: `3`  
- Input: `[9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6]` → Output: `7`  
  Explanation: The sequence is `[-1, 0, 1, 3, 4, 5, 6]` (after filtering duplicates)

---
