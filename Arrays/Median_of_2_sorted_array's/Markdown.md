## Problem Statement: Median of Two Sorted Arrays

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, find the **median** of the two sorted arrays.

The overall run time complexity should be **O(log (m+n))**.

---

## 🧪 Examples

### Example 1:

#### Input:
```plaintext
nums1 = [1, 3], nums2 = [2]
```

#### Output:
```plaintext
2.0
```

#### Explanation:
The combined sorted array is `[1, 2, 3]`. The median is `2`.

### Example 2:

#### Input:
```plaintext
nums1 = [1, 2], nums2 = [3, 4]
```

#### Output:
```plaintext
2.5
```

#### Explanation:
The combined sorted array is `[1, 2, 3, 4]`. The median is `(2 + 3) / 2 = 2.5`.

---

## Approach — Binary Search + Partitioning

## 💡 Key Idea

Instead of merging arrays (which takes O(m+n) time), we **binary search** to find the correct **partition point** that divides both arrays such that:

* Left partition has the same number of elements as right partition (or one more for odd total)
* All elements in left partition ≤ all elements in right partition

To achieve this:
* Perform binary search on the **smaller array** to find partition point
* Calculate corresponding partition point in the larger array
* Check if partition is valid using cross-comparison of boundary elements

---

## ✅ Partition Validation Logic

For a valid partition with boundaries `maxLeft1`, `minRight1`, `maxLeft2`, `minRight2`:

* **Cross-check condition**: `maxLeft1 ≤ minRight2` AND `maxLeft2 ≤ minRight1`
* If `maxLeft1 > minRight2` → partition too far right, move left
* If `maxLeft2 > minRight1` → partition too far left, move right

---

## ⚙️ Time & Space Complexity

> **Time**: O(log(min(m, n))) - Binary search on smaller array
> **Space**: O(1) - Only using boundary variables

---

## 📝 Algorithm Steps

1. **Ensure nums1 is smaller**: If `m > n`, swap arrays to optimize binary search
2. **Set binary search bounds**: `low = 0`, `high = m`
3. **While low ≤ high**:
   * Calculate `partitionX = (low + high) / 2`
   * Calculate `partitionY = (m + n + 1) / 2 - partitionX`
   * Find boundary elements around partitions
   * **Check partition validity**:
     * If valid → calculate and return median
     * If `maxLeftX > minRightY` → move left (`high = partitionX - 1`)
     * Else → move right (`low = partitionX + 1`)

---

## 💭 Key Insights

* **Binary Search on Partition**: We're searching for the optimal cut point, not array elements
* **Balanced Partitioning**: Left side always has `⌈(m+n)/2⌉` elements
* **Cross-Validation**: Boundary elements must satisfy the sorted property across arrays
* **Edge Handling**: Use `INT_MIN`/`INT_MAX` when partition touches array boundaries

---

## 🎯 Edge Cases

* **Empty array**: One array is empty → median comes from the non-empty array
* **Single element arrays**: `m = 1, n = 1` → median is average of both elements
* **Partition at boundaries**: Handle when `partitionX = 0` or `partitionX = m`
* **Odd vs Even total length**: Different median calculation logic

---

## 🧠 Why This Approach?

* **Naive merge**: O(m+n) time, O(m+n) space - violates time constraint
* **Binary search on values**: Complex due to duplicate handling
* **✅ Binary search on partition**: O(log(min(m,n))) time, O(1) space - optimal solution
