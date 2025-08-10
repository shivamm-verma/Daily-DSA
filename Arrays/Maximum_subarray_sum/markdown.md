## 🧠 Problem
Given an integer array `nums`, find the subarray with the largest sum, and return its sum.
```
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
-------------------------------------------------------------------

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
-------------------------------------------------------------------

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```
---
## Constraints:
```
1 <= nums.length <= 105
-104 <= nums[i] <= 104
```

---

## Approach
We keep a running sum (currSum) of the current subarray.

If currSum becomes negative, we know it cannot contribute to a future maximum subarray sum (because adding a negative sum will make things worse), so we reset it to 0.

At each step, we track the highest sum seen so far using maxSum.

---
## Complexities
- Time: O(n) — one pass through the array.
- Extra Space: O(1) — only a few variables are used.