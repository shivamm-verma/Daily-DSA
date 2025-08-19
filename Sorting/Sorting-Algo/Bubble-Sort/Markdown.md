
# Bubble Sort

**Explanation:**
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping adjacent elements, pushing the largest elements toward the end in each pass.

It is a **stable** sorting algorithm, meaning that elements with the same value maintain their relative order. 

Bubble Sort is an **in-place** algorithm as it swaps elements directly without using any major data structure. 

**Algorithm Approach:**

- Compare each pair of adjacent elements.
- Swap them if they’re in the wrong order (larger before smaller).
- After each pass, the largest unsorted element is moved to its correct position.
- Repeat this for all elements (n-1 passes). 


**Pseudocode:**

```text
for i = 0 to n-1:
    for j = 0 to n-i-2:
        if arr[j] > arr[j+1]:
            swap(arr[j], arr[j+1])
```

**Time Complexity:**

* Best case: O(n) (array already sorted)
* Average case: O(n²)
* Worst case: O(n²)

**Space Complexity:** O(1)




