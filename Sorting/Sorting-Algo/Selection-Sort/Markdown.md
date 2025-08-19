# Selection Sort

**Explanation:**
Selection Sort repeatedly selects the smallest element from the unsorted portion of the array and swaps it with the first unsorted element.

It is **generally unstable** (equal elements may change their relative order) and is an **in-place** algorithm, meaning it sorts the array directly without using extra memory.

**Algorithm Approach:**

1. Find the smallest element in the unsorted portion of the array.
2. Swap it with the first unsorted element.
3. Move the boundary of the sorted portion one element forward.
4. Repeat until the array is fully sorted.

**Pseudocode:**

```text
for i = 0 to n-1:
    min_idx = i
    for j = i+1 to n-1:
        if arr[j] < arr[min_idx]:
            min_idx = j
    swap(arr[i], arr[min_idx])
```

**Time Complexity:**

* Best case: O(n²)
* Average case: O(n²)
* Worst case: O(n²)

**Space Complexity:** O(1)

**Key Concepts:**

* **Unstable:** Relative order of equal elements may change.
* **In-place:** Sorting is done directly in the original array without significant extra memory.




