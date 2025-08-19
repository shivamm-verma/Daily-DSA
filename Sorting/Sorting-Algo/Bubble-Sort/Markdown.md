
# <span style="color: #1E90FF;">Bubble Sort</span>

**<span style="color: #228B22;">Explanation:</span>**
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping adjacent elements, pushing the largest elements toward the end in each pass.

It is a **stable** sorting algorithm, meaning that elements with the same value maintain their relative order. 

Bubble Sort is an **in-place** algorithm as it swaps elements directly without using any major data structure. 

**<span style="color: #FF8C00;">Algorithm Approach:</span>**

- Compare each pair of adjacent elements.
- Swap them if they’re in the wrong order (larger before smaller).
- After each pass, the largest unsorted element is moved to its correct position.
- Repeat this for all elements (n-1 passes). 


**<span style="color: #FF8C00;">Pseudocode:</span>**

```text
for i = 0 to n-1:
    for j = 0 to n-i-2:
        if arr[j] > arr[j+1]:
            swap(arr[j], arr[j+1])
```

**<span style="color: #8B0000;">Time Complexity:</span>**

* <span style="color: #32CD32;">Best case:</span> O(n) (array already sorted)
* <span style="color: #FFD700;">Average case:</span> O(n²)
* <span style="color: #FF4500;">Worst case:</span> O(n²)

**<span style="color: #8A2BE2;">Space Complexity:</span>** O(1)




