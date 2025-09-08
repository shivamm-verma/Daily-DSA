# 📘 Problem: Sort a Linked List

## 📖 Problem Statement
Given a linked list, sort its nodes in ascending order based on their data values.  
Return the head of the sorted linked list.

---

## 📝 Examples

### Example 1:
**Input:**  
`4 -> 2 -> 1 -> 3`  

**Output:**  
`1 -> 2 -> 3 -> 4`

---

### Example 2:
**Input:**  
`-1 -> 5 -> 3 -> 4 -> 0`  

**Output:**  
`-1 -> 0 -> 3 -> 4 -> 5`

---

## ✅ Brute Force Approach
### Idea:
- Traverse the linked list and store the elements in an array.
- Sort the array.
- Recreate the linked list from the sorted values.

### Complexity:
- **Time Complexity:** `O(n log n)` (sorting dominates)  
- **Space Complexity:** `O(n)` (extra array storage)

📂 Files:  
- `BruteForce.cpp`  
- `BruteForce.java`  
- `BruteForce.py`  

---

## 🚀 Optimal Approach
### Idea:
- Use **Merge Sort** on the linked list.
- Recursively split the list into halves, sort each half, then merge them.

### Complexity:
- **Time Complexity:** `O(n log n)` (merge sort)  
- **Space Complexity:** `O(log n)` (recursion stack)  

📂 Files:  
- `Optimal.cpp`  
- `Optimal.java`  
- `Optimal.py`  

---

## 📂 Topics Covered
- Linked List  
- Sorting  
- Merge Sort  

---
