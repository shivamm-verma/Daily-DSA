# 69. Triplet Sum in Array


## 📝 Problem Statement

Given an array `arr[]` and an integer `target`, determine whether there exists a triplet in the array whose sum is equal to the target.

### Examples:

Input: arr[] = [1, 4, 45, 6, 10, 8], target = 13
Output: true
Explanation: Triplet [1, 4, 8] adds up to 13

Input: arr[] = [1, 2, 4, 3, 6, 7], target = 10
Output: true
Explanation: Triplet [1, 3, 6] adds up to 10

Input: arr[] = [40, 20, 10, 3, 6, 7], target = 24
Output: false
Explanation: No such triplet exists



---

## 🔍 Approaches

### 1. Naive Approach – Brute Force (O(n³) Time, O(1) Space)

- Loop through all possible triplets using three nested loops.
- Check if the sum of any triplet equals the target.
- Return `true` if a valid triplet is found, else `false`.

---

### 2. Better Approach – Hashing (O(n²) Time, O(n) Space)

- Fix the first element.
- Use a hash set to find a pair in the remaining array that adds up to `target - arr[i]`.
- If such a pair exists, return `true`.
- This reduces one loop and optimizes the solution using extra space.

---

### 3. Optimized Approach – Sorting + Two Pointer (O(n²) Time, O(1) Space)

- First, sort the array.
- Loop through the array fixing the first element.
- Use the two-pointer technique on the subarray to find two elements whose sum is `target - arr[i]`.
- This is the most efficient solution with constant space usage.

---

## 📚 Topics Covered

- Arrays  
- Hashing  
- Two Pointer Technique  
- Sorting

---

## ✅ Status

- [x] Naive (Brute-force) logic added  
- [x] Hashing-based logic added  
- [x] Two-pointer optimized logic added

---

## 🗂️ Note for Contributors

You can implement the above logic in **any programming language** such as:
- C++
- Python
- Java
- Go
- JavaScript

Make sure to include only relevant logic, input/output, and proper formatting as per your language's standards.
