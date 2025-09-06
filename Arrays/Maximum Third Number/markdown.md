# Problem: Third Maximum Number

## Problem Statement
Given an integer array `nums`, return the **third distinct maximum number** in the array.  
If the third maximum does not exist, return the maximum number.

---

## Example

**Input**
```
Enter integers separated by space: 3 2 1
```

**Output**
```
Third maximum (or max if not enough distinct values): 1
```

---

## Approach

1. Initialize three variables: `max1`, `max2`, `max3` as negative infinity.
2. Traverse through the array:
   - If the number is already one of `max1`, `max2`, or `max3`, skip it (to ensure distinct values).
   - Update `max1`, `max2`, and `max3` accordingly:
     - If `num > max1`: shift values down (`max3 = max2`, `max2 = max1`, `max1 = num`).
     - Else if `num > max2`: shift (`max3 = max2`, `max2 = num`).
     - Else if `num > max3`: update `max3 = num`.
3. At the end:
   - If `max3` is still negative infinity, return `max1` (meaning fewer than 3 distinct numbers exist).
   - Otherwise, return `max3`.

---

## Time Complexity
- **O(n)**, where `n` is the length of the array.  
Each element is processed once.

## Space Complexity
- **O(1)**, since only three variables are used regardless of input size.

---
