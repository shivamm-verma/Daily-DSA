#🧮 Three Sum Closest

---

##📘 Problem Statement
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

---

##🧠 Pseudo Code
```python
function threeSumClosest(nums, target):
    sort nums
    initialize res as infinity

    for i from 0 to length(nums) - 2:
        j = i + 1
        k = length(nums) - 1

        while j < k:
            total = nums[i] + nums[j] + nums[k]

            if abs(total - target) < abs(res - target):
                res = total

            if total > target:
                k -= 1
            else if total < target:
                j += 1
            else:
                return res

    return res
```
---

##📊 Example
Input:

Code
nums = [-1, 2, 1, -4]
target = 1
Output:

Code
2
Explanation:

The possible triplets are:

(-1, 2, 1) → sum = 2

(-1, 2, -4) → sum = -3

(-1, 1, -4) → sum = -4

(2, 1, -4) → sum = -1

The closest sum to target 1 is 2.

---

##🧩 Explanation
First, sort the array to enable two-pointer traversal.

Fix one element and use two pointers (j and k) to find the best pair that, along with the fixed element, gives the closest sum.

Update the result whenever a closer sum is found.

If the exact target is found, return immediately.

---

##⏱️ Time Complexity
Sorting: 
𝑂
(
𝑛
log
⁡
𝑛
)

Two-pointer traversal: 
𝑂
(
𝑛
2
)

Overall: 
𝑂
(
𝑛
2
)

---

###🧠 Space Complexity
Auxiliary space: 
𝑂
(
1
)

Sorting is done in-place and no extra space is used beyond variables.

---