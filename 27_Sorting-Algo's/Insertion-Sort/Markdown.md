
# Insertion Sort Algorithm

## Definition:
Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

## How it works:
1. Assume that the first element is already sorted.
2. Take the next element and compare it with the elements in the sorted portion.
3. Shift all larger elements one position to the right.
4. Insert the current element into its correct position.
5. Repeat until the array is fully sorted.

## Time Complexity:
- Best Case (Already Sorted): O(n)
- Average Case: O(n^2)
- Worst Case (Reversely Sorted): O(n^2)
- Space Complexity: O(1) – In-place sort
- Stable: Yes


