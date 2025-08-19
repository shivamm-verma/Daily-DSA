
# Heap Sort

**Explanation:**
Heap Sort is a comparison-based sorting algorithm that uses a **binary heap** data structure — typically a **Max Heap** for ascending order sorting. 

It is **not stable** (equal elements may change order) and **in-place**, as it sorts the array without extra memory apart from recursion stack if using a recursive heapify.

**Algorithm Approach:**

1. Build a Max Heap from the input array.
2. Swap the root (maximum element) with the last element.
3. Reduce the heap size by one and call `heapify()` on the root.
4. Repeat steps 2–3 until the heap size is 1.

**Pseudocode:**

```text
function heapSort(arr):
    buildMaxHeap(arr)
    for i = n-1 downto 1:
        swap(arr[0], arr[i])
        heapify(arr, 0, i)

function heapify(arr, i, n):
    largest = i
    left = 2*i + 1
    right = 2*i + 2
    if left < n and arr[left] > arr[largest]:
        largest = left
    if right < n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        swap(arr[i], arr[largest])
        heapify(arr, largest, n)
```

**Time Complexity:**

* Best case: O(n log n)
* Average case: O(n log n)
* Worst case: O(n log n)
  Building the heap takes O(n), and each `heapify()` call is O(log n).

**Space Complexity:** O(1) (in-place sorting, no extra arrays except recursion stack if recursive)

**Key Concepts:**

* **Not Stable:** Equal elements may change their relative order.
* **In-place:** Sorting is done directly in the original array.





