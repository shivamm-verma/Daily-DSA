## ✅ DSA Question: Heap Sort

---

### 🧠 Problem  

Heap Sort is a comparison-based sorting algorithm that sorts a given array of numbers in ascending order using a **binary heap** data structure — typically a **Max Heap**. It repeatedly extracts the maximum element from the heap and places it at the end of the array.

---

## 🧭 Approach

1. Build a Max Heap from the input array.  
2. Swap the root (maximum element) with the last element in the heap.  
3. Reduce the heap size by one and call `heapify()` on the root to maintain the heap property.  
4. Repeat steps 2–3 until the heap size becomes 1.  

**Properties:**  
- Not stable: equal elements may change their relative order.  
- In-place: sorts the array directly without extra space (except recursion stack if recursive).  

---

## 🔁 Generic Logic (Pseudocode)
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

## ⏱️ Complexities
 > Time Complexity
* Best case: **O(n log n)**
* Average case: **O(n log n)**
* Worst case: **O(n log n)**
  Building the heap takes O(n), and each `heapify()` call is O(log n).


> Space Complexity
* **O(1)** —  in-place sorting, no extra arrays except recursion stack if recursive
