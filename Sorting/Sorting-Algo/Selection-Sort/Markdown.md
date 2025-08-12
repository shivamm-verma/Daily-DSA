
    ===================== Selection Sort =====================

    What is Selection Sort?
    ------------------------
    Selection Sort is a simple comparison-based sorting algorithm.
    It divides the array into two parts: the sorted part and the unsorted part.

    How it Works:
    --------------
    - Start from the first element of the array.
    - Find the smallest element in the unsorted part of the array.
    - Swap it with the element at the beginning of the unsorted part.
    - Move the boundary of the sorted part one step to the right.
    - Repeat until the entire array is sorted.

    Time Complexity:
    ----------------
    - Best Case:    O(n²)
    - Average Case: O(n²)
    - Worst Case:   O(n²)

    Space Complexity:
    -----------------
    - O(1) — In-place sorting, requires no extra space.

    Notes:
    ------
    - It is not a stable sort.
    - It is an in-place sorting algorithm.
    - Useful for small datasets or when memory write is more costly than read.

