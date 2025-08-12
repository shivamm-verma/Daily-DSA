# 🧠 Three Sum Problem

## ✅ Problem Statement

Given an array `nums` of integers, return **all unique triplets** `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `j != k`, and `i != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution must not contain duplicate triplets.

---

## 📘 Example

**Input:**
nums = [-1, 0, 1, 2, -1, -4]

**Output:**
[[-1, -1, 2], [-1, 0, 1]]

**Explanation:**
- Triplet `[-1, 0, 1]` sums to 0.
- Triplet `[-1, -1, 2]` also sums to 0.
- Triplet `[-4, 2, 2]` is invalid because there's only one `2`.

---

## 🧩 Approach

1. **Sort the array** to simplify duplicate handling and use two-pointer technique.
2. **Iterate** through the array with index `i`:
   - Skip duplicates for `i`.
   - Use two pointers `j` and `k` to find pairs such that `nums[i] + nums[j] + nums[k] == 0`.
3. **Move pointers**:
   - If sum is less than 0 → move `j` forward.
   - If sum is greater than 0 → move `k` backward.
   - If sum is 0 → store triplet and skip duplicates for `j` and `k`.

---

## 🧠 Pseudocode (Python)

```python
def threeSum(nums):
    nums.sort()
    result = []

    for i in range(len(nums) - 2):
        if i > 0 and nums[i] == nums[i - 1]:
            continue

        j, k = i + 1, len(nums) - 1
        while j < k:
            total = nums[i] + nums[j] + nums[k]
            if total == 0:
                result.append([nums[i], nums[j], nums[k]])
                j += 1
                k -= 1
                while j < k and nums[j] == nums[j - 1]:
                    j += 1
                while j < k and nums[k] == nums[k + 1]:
                    k -= 1
            elif total < 0:
                j += 1
            else:
                k -= 1

    return result
```

---

## ⏱️ Time Complexity
Sorting: O(n log n)

Two-pointer traversal: O(n^2)

Total: O(n^2)

---

## 🧮 Space Complexity
O(1) extra space (excluding output list)

Output space depends on number of valid triplets.

---

## 📌 Notes
Sorting helps eliminate duplicates efficiently.

Two-pointer technique avoids nested loops and improves performance.

This problem is a classic example of using sorting + two pointers for optimization.

---