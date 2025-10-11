# Find the Middle Index in Array (LeetCode 1991)

## Description
Given an integer array `nums`, return the **leftmost** middle index.  
The middle index is an index where the sum of the numbers to the left is equal to the sum of the numbers to the right.  
If no such index exists, return `-1`.

---

## Constraints
- `1 <= nums.length <= 100`
- `-1000 <= nums[i] <= 1000`

---

## Test Cases
```text
Input: nums = [2,3,-1,8,4]
Output: 3

Input: nums = [1,-1,4]
Output: 2

Input: nums = [2,5]
Output: -1

## Tips to Identify Pattern

“Left sum = Right sum” → Prefix sums.

Compute total sum, then track left sum as you iterate.

Check: leftSum == totalSum - leftSum - nums[i].