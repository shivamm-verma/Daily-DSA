
# Merge Sort

**Explanation:**
Merge Sort is a divide-and-conquer algorithm that splits the array into halves, recursively sorts them, and then merges the sorted halves. It is a **stable** sorting algorithm but **not in-place** because it requires extra memory for merging.

**Algorithm Approach:**

1. Divide the array into two halves.
2. Recursively apply Merge Sort on both halves until each subarray has one element.
3. Merge the two sorted halves into a single sorted array.
4. Repeat until the entire array is sorted.

**Pseudocode:**

```text
function mergeSort(arr):
    if length(arr) <= 1:
        return arr
    mid = length(arr) / 2
    left = mergeSort(arr[0:mid])
    right = mergeSort(arr[mid:])
    return merge(left, right)

function merge(left, right):
    result = []
    while left and right:
        if left[0] <= right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))
    return result + left + right
```

**Time Complexity:**

* Best case: O(n log n)
* Average case: O(n log n)
* Worst case: O(n log n)

**Space Complexity:** O(n) (extra memory for merging)

**Key Concepts:**

* **Stable:** Equal elements retain their relative order.
* **Not In-place:** Requires additional memory for merging.

**Example:**


