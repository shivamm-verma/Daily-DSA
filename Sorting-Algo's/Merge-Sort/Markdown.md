
 Merge Sort - Explanation
===============================================================================

Merge Sort is a **Divide and Conquer** sorting algorithm.

 How it Works:
------------------
1. **Divide**:
   - Recursively split the array into two halves until each subarray has one element.

2. **Conquer**:
   - Merge the sorted subarrays back together in a sorted manner.

 Example:
-----------
Given: [4, 2, 5, 1, 3]

Step 1: Split until single elements:
   [4, 2, 5] and [1, 3]
   → [4, 2], [5], [1], [3]
   → [4], [2], [5], [1], [3]

Step 2: Merge sorted subarrays:
   → [2, 4], [5], [1, 3]
   → [2, 4, 5] and [1, 3]
   → Final sorted: [1, 2, 3, 4, 5]

⏱ Time Complexity:
--------------------
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

 Space Complexity:
---------------------
- O(n): Due to use of temporary array during merge step

 Merge Sort is a **stable sort**: It preserves the order of equal elements.

