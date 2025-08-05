

# QUICK SORT ALGORITHM
    
- Quick Sort is a **divide and conquer** algorithm.

    Working:
    - Pick an element as a "pivot" (in this implementation, we use the first element).
    - Partition the array so that:
        * Elements less than or equal to the pivot come before it.
        * Elements greater than the pivot come after it.
    - Recursively apply the same logic to the left and right subarrays.

    Time Complexity:
    - Best Case: O(n log n)
    - Average Case: O(n log n)
    - Worst Case: O(n^2) [occurs when the array is already sorted or reverse sorted and pivot choice is poor]

    Space Complexity: O(log n) due to recursion stack
