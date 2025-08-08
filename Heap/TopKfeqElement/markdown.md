# Top K Frequent Elements

## Problem
Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.  
You may return the answer in **any order**.

---

## **1. Brute Force**
**Idea:**  
- Store all unique elements.  
- Count frequency for each by scanning the array.  
- Sort by frequency and take the top `k`.

**Time Complexity:** O(n² log n) (counting each frequency costs O(n), sorting costs O(u log u))  
**Space Complexity:** O(u) where `u` is number of unique elements.

---

## **2. Better Approach (Hash Map + Sorting)**
**Idea:**  
- Use a hash map to count frequencies in O(n).  
- Convert map to vector and sort by frequency.  
- Pick top `k`.

**Time Complexity:** O(n log u)  
**Space Complexity:** O(u)

---

## **3. Optimal Approach (Hash Map + Min Heap)**
**Idea:**  
- Count frequencies with a hash map.  
- Use a min heap of size `k` to store the top frequent elements.  
- Pop from heap if size exceeds `k`.

**Time Complexity:** O(n log k)  
**Space Complexity:** O(u + k)

---

**Where to use which?**  
- Brute force → only for small constraints.  
- Better → works fine for moderate constraints.  
- Optimal → best for large `n` and small `k`.
