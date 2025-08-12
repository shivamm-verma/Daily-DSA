
# Count Number of Nice Subarrays

## Problem Statement

Given an array of integers `nums` and an integer `k`, a continuous subarray is called **nice** if there are exactly `k` odd numbers in it.

Return the number of **nice** subarrays.

---

## Example

### Input:
```
nums = [1,1,2,1,1], k = 3
```

### Output:
```
2
```

### Explanation:
The nice subarrays are:
- [1,1,2,1]
- [1,2,1,1]

---

## Brute-Force Approach

### Idea:
Check every possible subarray, and count the number of odd numbers in it. If the count is exactly `k`, increment the result.

### Pseudocode:
```
count = 0
for i in range(0 to n-1):
    oddCount = 0
    for j in range(i to n-1):
        if nums[j] is odd:
            oddCount += 1
        if oddCount == k:
            count += 1
        if oddCount > k:
            break
return count
```

### Time Complexity:
- O(n²), where n is the length of the array

### Why Brute-Force Fails:
- Inefficient for large arrays (`n` up to 10⁵), will exceed time limits

---

## Optimal Approach (Sliding Window - Two Pointers)

### Key Insight:
Instead of directly counting subarrays with **exactly** `k` odd numbers, we use:
```
countNiceSubarrays(k) = countAtMostK(k) - countAtMostK(k - 1)
```
This is a common technique where we subtract:
- Subarrays with **at most k** odd numbers
- Subarrays with **at most k - 1** odd numbers

The result is subarrays with **exactly k** odd numbers.

### Pseudocode:
```
function countAtMostK(nums, k):
    left = 0
    count = 0
    odd = 0

    for right in 0 to len(nums) - 1:
        if nums[right] % 2 == 1:
            odd += 1
        while odd > k:
            if nums[left] % 2 == 1:
                odd -= 1
            left += 1
        count += right - left + 1
    return count

function numberOfSubarrays(nums, k):
    return countAtMostK(nums, k) - countAtMostK(nums, k - 1)
```

### Time Complexity:
- O(n), where n is the length of the array

### Why This Optimal Approach is Better:
- Uses a **two-pointer sliding window** strategy
- Avoids nested loops
- Efficient for large arrays

---

## Time Complexities Summary

| Approach                | Time Complexity |
|-------------------------|-----------------|
| Brute-Force             | O(n²)           |
| Optimal (Sliding Window)| O(n)            |
