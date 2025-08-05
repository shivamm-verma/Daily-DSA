
📌 Bubble Sort Overview

Bubble Sort is a simple sorting algorithm that works by repeatedly
swapping adjacent elements if they are in the wrong order.
It "bubbles up" the largest unsorted element to the end of the array
in each pass, just like a bubble rising to the surface.

 How It Works:
- Compare each pair of adjacent elements.
- Swap them if they’re in the wrong order (larger before smaller).
- After each pass, the largest unsorted element is moved to its correct position.
- Repeat this for all elements (n-1 passes). 

⏱ Time Complexity:
- Best Case:    O(n)       → when the array is already sorted (with optimization)
- Average Case: O(n^2)
- Worst Case:   O(n^2)     → when the array is reverse sorted
- Space:        O(1)       → in-place sorting

 Stable Sort: Yes
=======================================