# Heap Sort

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure — typically a **Max Heap** for ascending order sorting.

---

##  How Heap Sort Works

1. **Build a Max Heap** from the input data.
2. **Swap the root (maximum element)** with the last element.
3. **Reduce the heap size** and call `heapify()` on the root.
4. **Repeat** step 2–3 until the heap is reduced to size 1.

---

##  Example

Given:  
`arr = [4, 10, 3, 5, 1]`

### Step-by-Step:
- Build Max Heap → `[10, 5, 3, 4, 1]`
- Swap 10 and 1 → `[1, 5, 3, 4, 10]`  
  → Heapify → `[5, 4, 3, 1, 10]`
- Swap 5 and 1 → `[1, 4, 3, 5, 10]`  
  → Heapify → `[4, 1, 3, 5, 10]`
- Continue until sorted → `[1, 3, 4, 5, 10]`

---

## ⏱️ Time Complexity

| Case       | Time     |
|------------|----------|
| Best       | O(n log n) |
| Average    | O(n log n) |
| Worst      | O(n log n) |

- Each call to `heapify()` takes `O(log n)`.
- Building the heap takes `O(n)`, and we perform `O(n)` heapify calls during sort.

---

##  Space Complexity

- **O(1)** (in-place sorting, no extra arrays except for recursion stack if not iterative).

---

##  Is Heap Sort Stable?

>  **No**, Heap Sort is **not stable**.

- Stability means **equal elements retain their relative order**.
- Heap sort does not guarantee this, due to how elements are swapped during heap construction and sorting.

---



