# Median of Two Sorted Arrays

## Problem Statement

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

## Example

### Input

```
nums1 = [1, 3]
nums2 = [2]
```

### Output

```
Median = 2.0
```

### Explanation

The combined sorted array is `[1, 2, 3]`. The median is `2`.

---

### Input

```
nums1 = [1, 2]
nums2 = [3, 4]
```

### Output

```
Median = 2.5
```

### Explanation

The combined sorted array is `[1, 2, 3, 4]`. The median is `(2 + 3) / 2 = 2.5`.

## Approach

- Use binary search to partition the arrays such that the left half contains the same number of elements as the right half.
- Compare elements around the partition to find the correct median.

## Complexity Analysis

- **Time Complexity:** O(log(min(m, n))), where `m` and `n` are the lengths of the two arrays. Binary search is performed on the smaller array.
- **Space Complexity:** O(1), as only a constant amount of extra space is used.

## Constraints

- `nums1` and `nums2` are both sorted in non-decreasing order.
- `0 <= m, n <= 1000`
- `1 <= m + n <= 2000`
- `-10^6 <= nums1[i], nums2[i] <= 10^6`


