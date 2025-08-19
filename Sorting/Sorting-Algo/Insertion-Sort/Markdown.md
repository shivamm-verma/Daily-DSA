# Insertion Sort

**Explanation:**
Insertion Sort builds the sorted array one element at a time by placing each new element into its correct position.

It is a **stable** sorting algorithm, so elements with the same value maintain their relative order. 
 
Insertion Sort is an **in-place** algorithm as it rearranges elements directly without using extra memory.

**Algorithm Approach:**

1. Start from the second element (index 1) and compare it with the elements before it.
2. Shift all larger elements one position to the right to make space.
3. Insert the current element into its correct position.
4. Repeat for all elements until the array is sorted.

**Pseudocode:**

```text
for i = 1 to n-1:
    key = arr[i]
    j = i-1
    while j >= 0 and arr[j] > key:
        arr[j+1] = arr[j]
        j -= 1
    arr[j+1] = key
```

**Time Complexity:**

* Best case: O(n) (array already sorted)
* Average case: O(n²)
* Worst case: O(n²)

**Space Complexity:** O(1)

**Example:**

