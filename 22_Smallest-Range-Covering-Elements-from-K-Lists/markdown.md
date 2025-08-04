# 🔍 Smallest Range Covering Elements from K Lists

## Problem Statement

Given `k` sorted lists of integers, find the smallest range `[start, end]` that includes at least one number from each of the `k` lists. A range `[a, b]` is smaller than a range `[c, d]` if `b - a < d - c` or if `b - a == d - c` and `a < c`.

---

## Algorithm: Using a Min-Heap

The optimal approach uses a **min-heap** to maintain a window of `k` elements—one from each list. The window is defined by the minimum element in the heap and the maximum element seen so far. We "slide" this window by removing the overall minimum and adding the next element from that same list.

1.  **Initialization**: Create a min-heap and a variable `max_val` to track the maximum number in the window. Push the first element from each of the `k` lists into the heap and update `max_val`.
2.  **Initial Range**: The first candidate range is `[heap.peek(), max_val]`. Store this as the best range found so far.
3.  **Sliding Window**:
    * In a loop, pop the minimum element from the heap.
    * If the list that element came from is now exhausted, stop the process.
    * Otherwise, add the *next* element from that list to the heap.
    * Update `max_val` if this new element is larger than the current `max_val`.
    * The new candidate range is `[heap.peek(), max_val]`. If this range is smaller than the best range found so far, update it.
4.  **Termination**: The loop ends when one list runs out of elements. The stored best range is the answer.

---

## Pseudocode

```python
function smallestRange(lists):
  min_heap = new PriorityQueue() // Stores (value, list_idx, elem_idx)
  current_max = -infinity

  // Initialize heap
  for i from 0 to k-1:
    value = lists[i][0]
    min_heap.push((value, i, 0))
    current_max = max(current_max, value)

  range_start = -1
  min_range_size = infinity

  while true:
    (min_val, list_idx, elem_idx) = min_heap.pop()

    if (current_max - min_val < min_range_size):
      min_range_size = current_max - min_val
      range_start = min_val

    if (elem_idx + 1 >= lists[list_idx].length):
      break // A list is exhausted

    next_val = lists[list_idx][elem_idx + 1]
    min_heap.push((next_val, list_idx, elem_idx + 1))
    current_max = max(current_max, next_val)

  return [range_start, range_start + min_range_size]
```