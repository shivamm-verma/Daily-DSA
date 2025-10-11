
---

# 📂 File 2: `product_of_array_except_self.md`

```markdown
# Product of Array Except Self (LeetCode 238)

## Description
Given an integer array `nums`, return an array `answer` such that `answer[i]` equals the product of all elements of `nums` except `nums[i]`.  

You must solve it **without division** and in `O(n)`.

---

## Constraints
- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- Product fits in 32-bit integer.

---

## Test Cases
```text
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

## Tips to Identify Pattern

Prefix product and suffix product arrays.

answer[i] = prefix[i] * suffix[i].

Space optimized: compute prefix in first pass, multiply by suffix in second pass.