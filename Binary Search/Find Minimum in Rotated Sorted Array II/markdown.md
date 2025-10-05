# 🌀 Find Minimum in Rotated Sorted Array

## 📌 Problem Statement
You are given a rotated sorted array `nums` of length `n`.  
A rotated array means an originally sorted array has been shifted some number of positions.  
For example, the sorted array `[0, 1, 2, 4, 5, 6, 7]` might become `[4, 5, 6, 7, 0, 1, 2]`.  

Your task is to **find the minimum element** in this rotated sorted array.  
The array **may contain duplicates**.

---

## ✅ Example

### Input
```
Enter number of elements: 5
Enter array elements: 4 5 6 7 0
```

### Output
```
Minimum element in rotated array: 0
```

---

## 🔎 Steps to Solve
1. Use **binary search** to minimize comparisons.
2. Initialize two pointers:
   - `lo = 0` (start of array)  
   - `hi = n-1` (end of array)
3. Check if the array is already sorted (`nums[lo] < nums[hi]`).  
   - If true, the first element is the minimum.
4. Otherwise, perform binary search:
   - Find `mid = (lo + hi) / 2`.
   - If `nums[mid] > nums[hi]`, the minimum is in the **right half** → `lo = mid + 1`.
   - Else if `nums[mid] > nums[lo]`, the minimum is in the **left half** → `hi = mid`.
   - Else, reduce search space by moving `hi--` (handles duplicates).
5. Continue until `lo == hi`.  
6. Return `nums[lo]` as the minimum.

---

## ⏱️ Time Complexity
- **O(log n)** in the average case (binary search).  
- **O(n)** in the worst case when many duplicates exist (e.g., `[2,2,2,0,1]`). 

---

## 💾 Space Complexity
- **O(1)** → only a few extra variables (`lo`, `hi`, `mid`).  
