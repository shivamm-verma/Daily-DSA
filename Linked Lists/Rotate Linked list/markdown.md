# Rotate List

## Problem Statement
Given the head of a linked list, rotate the list to the right by **k** places.

**Example 1:**
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]


**Example 2:**
Input: head = [0,1,2], k = 4
Output: [2,0,1]


---



## 🔹 Approach 1: Brute Force
- Rotate the list **one step at a time** for `k` times.  
- Each rotation:
  1. Traverse to the last node.  
  2. Move it to the front.  
- Repeat `k` times.

### Complexity
- **Time:** O(N × K)  
- **Space:** O(1)  

📂 Implementations:  
- [BruteForce.cpp](./BruteForce.cpp)  
- [BruteForce.java](./BruteForce.java)  
- [BruteForce.py](./BruteForce.py)  

---

## 🔹 Approach 2: Better Approach
- Count the **length (N)** of the list.  
- Connect the tail to the head → forms a **circular list**.  
- The new head will be at position `(N - (k % N))` from the start.  
- Break the circle to form the rotated list.

### Complexity
- **Time:** O(N)  
- **Space:** O(1)  

📂 Implementations:  
- [Better.cpp](./Better.cpp)  
- [Better.java](./Better.java)  
- [Better.py](./Better.py)  

---

## 🔹 Approach 3: Optimal Approach
- The **Better Approach is already Optimal**.  
- Time complexity is **O(N)** and space complexity is **O(1)**.  
- Thus, Optimal = Better in this problem.

📂 Implementations:  
- [Optimal.cpp](./Better.cpp)  
- [Optimal.java](./Better.java)  
- [Optimal.py](./Better.py)  

---

## ✅ Summary

| Approach       | Time Complexity | Space Complexity |
|----------------|-----------------|------------------|
| Brute Force    | O(N × K)        | O(1)             |
| Better/Optimal | O(N)            | O(1)             |

---

## ✨ Contribution Checklist
- [x] Added Brute Force solutions (`.cpp`, `.java`, `.py`)  
- [x] Added Better solutions (`.cpp`, `.java`, `.py`)  
- [x] Added Optimal solutions (linked to Better, since same)  
- [x] Added `Markdown.md` with explanation, complexities, and references  
