## 🧠 Problem
Given an integer array ```nums```, rotate the array to the right by `k` steps, where k is non-negative.

```
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
---------------------------------------------------

Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
```
---
## Constraints:
```
1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
```

---

## Approach

Key Observations:  
Rotating an array by k = n (where n is array length) results in the original array.
Therefore, we compute k = k % n to handle cases when k > n.
 
Steps:  
- Reverse the first part of the array (from index 0 to n - k - 1).
- Reverse the second part (from index n - k to n - 1).
- Reverse the entire array.  
These three reversals together achieve the desired rotation.

A helper function is used to reverse any portion of the array in-place using two pointers (st and end).

---
## Complexities
- Time: O(n) — Each element is reversed at most twice.
- Extra Space: O(1) — In-place algorithm.