
# Quick Sort

**Explanation:**
Quick Sort is a divide-and-conquer algorithm that selects a pivot, partitions the array into elements less than and greater than the pivot, and recursively sorts the partitions.

It is **not stable** (equal elements may change their relative order) and **in-place**, as it rearranges elements directly in the array.

**Algorithm Approach:**

1. Choose a pivot element (commonly the last element).
2. Partition the array into two parts: elements smaller than the pivot and elements greater than the pivot.
3. Recursively apply Quick Sort on both partitions with a **base condition**: if the start index is greater than or equal to the end index, return.
4. Repeat until the array is fully sorted.

**Pseudocode:**

```text
function quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)

function partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j = low to high-1:
        if arr[j] < pivot:
            i += 1
            swap(arr[i], arr[j])
    swap(arr[i+1], arr[high])
    return i+1
```

**Time Complexity:**

* Best/Average case: O(n log n)
* Worst case: O(n²)[occurs when the array is already sorted or reverse sorted and pivot choice is poor]


**Space Complexity:** O(log n) (recursion stack)

**Key Concepts:**

* **Not Stable:** Equal elements may change their relative order.
* **In-place:** Sorting is done directly in the original array without significant extra memory.



