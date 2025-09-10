# 4Sum Problem

## Problem Statement
Given an array `nums` of *n* integers and an integer `target`, find all unique quadruplets `[nums[a], nums[b], nums[c], nums[d]]` such that:
- `0 <= a, b, c, d < n`
- All indices are distinct
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

The quadruplets should be unique—no duplicates allowed—and can be returned in any order. Internally, each quadruplet should be in non-decreasing order. :contentReference[oaicite:0]{index=0}

---

## Input
- An integer `n` representing the number of elements in the array.
- An array `nums` of `n` integers.
- An integer `target` representing the sum value.

---

## Output
- A list of all unique quadruplets from `nums` whose sum equals `target`.
- Each quadruplet must be sorted internally (non-decreasing order).
- The result list can be in any order. :contentReference[oaicite:1]{index=1}

---

## Steps (Approach)
1. **Sort** the `nums` array.
2. For `i` from `0` to `n - 4`:
   - Skip duplicates (`if i > 0 and nums[i] == nums[i - 1]`).
3. For `j` from `i + 1` to `n - 3`:
   - Skip duplicates (`if j > i + 1 and nums[j] == nums[j - 1]`).
4. Use two pointers: `l = j + 1` and `r = n - 1`:
   - Compute `total = nums[i] + nums[j] + nums[l] + nums[r]`.
   - If `total == target`:
     - Append quadruplet and move both pointers (`l++, r--`), skipping duplicates.
   - Else if `total < target`: `l++`
   - Else: `r--`
5. Continue until all unique quadruplets are collected. :contentReference[oaicite:2]{index=2}

---

## Example
**Input:**
nums = [1, 0, -1, 0, -2, 2]
target = 0

**After sorting:** 
`[-2, -1, 0, 0, 1, 2]`

**Output:**

[
[-2, -1, 1, 2],
[-2, 0, 0, 2],
[-1, 0, 0, 1]
]

---

## Pseudocode (in Python)

```python
def fourSum(nums, target):
    nums.sort()
    n = len(nums)
    res = []

    for i in range(n - 3):
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        for j in range(i + 1, n - 2):
            if j > i + 1 and nums[j] == nums[j - 1]:
                continue
            l, r = j + 1, n - 1
            while l < r:
                total = nums[i] + nums[j] + nums[l] + nums[r]
                if total == target:
                    res.append([nums[i], nums[j], nums[l], nums[r]])
                    l += 1
                    r -= 1
                    while l < r and nums[l] == nums[l - 1]:
                        l += 1
                    while l < r and nums[r] == nums[r + 1]:
                        r -= 1
                elif total < target:
                    l += 1
                else:
                    r -= 1
    return res
```
---

## Time Complexity

- The algorithm runs in 𝑂(𝑛^3) because sorting takes 𝑂(𝑛log⁡𝑛)and then you have two nested loops plus a two-pointer scan which, in the worst case, iterates in 𝑂(𝑛)inside the innermost loop.

---

## Space Complexity:
- Apart from the space used by sorting (assuming in-place or 𝑂(log⁡𝑛) recursion stack) and the output list, the algorithm uses constant auxiliary space, i.e., 𝑂(1), excluding the result storage.
