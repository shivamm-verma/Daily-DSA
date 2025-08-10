# Kadane's Algorithm — Maximum Subarray Sum

## 🧠 Problem Statement
Given an integer array `arr[]`, find the **subarray** (containing at least one element) which has the **maximum possible sum**, and return that sum.

> **Note:** A subarray is a continuous part of an array.

---

## 🧪 Example Input/Output

### Example 1:
**Input:**  
`arr[] = [2, 3, -8, 7, -1, 2, 3]`  
**Output:**  
`11`  
**Explanation:**  
Subarray `[7, -1, 2, 3]` gives the largest sum.

### Example 2:
**Input:**  
`arr[] = [-2, -4]`  
**Output:**  
`-2`  
**Explanation:**  
Subarray `[-2]` gives the largest sum.

### Example 3:
**Input:**  
`arr[] = [5, 4, 1, 7, 8]`  
**Output:**  
`25`  
**Explanation:**  
The entire array is the subarray with the maximum sum.

---

## 🔁 Generic Logic

### ✅ Naive Approach (Brute Force) — O(n²)
- Use two nested loops to iterate over **all possible subarrays**.
- For each subarray, calculate the sum and update the maximum sum encountered.
- This is inefficient for large arrays.

### ✅ Optimized Approach — **Kadane’s Algorithm** — O(n)
- Traverse the array from left to right.
- At each element, choose:
  - Either extend the current subarray sum if it’s beneficial.
  - Or start a new subarray from this element.
- Keep track of the global maximum during traversal.

---

## ⏱ Time and Space Complexity

| Approach            | Time Complexity | Space Complexity |
|---------------------|------------------|------------------|
| Brute Force         | O(n²)            | O(1)             |
| Kadane’s Algorithm  | O(n)             | O(1)             |

---

## 🧠 Intuition Behind Kadane's Algorithm

At every element in the array, we decide:
- Do we **extend the existing subarray** by adding the current element?
- Or is it better to **start a new subarray** from the current element?

This is done by comparing:
```cpp
maxEnding = max(arr[i], maxEnding + arr[i])
