# Merge Intervals

### Description
You are given a collection of intervals, where each interval is represented as a pair of integers `[start, end]`.  
Merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

**Example:**  
Input: `[[1,4],[0,2],[3,5]]`  
Output: `[[0,5]]`

Input : `[[1,3],[2,6],[8,10],[15,18]]`
Output: `[[1,6],[8,10],[15,18]]`

Input: `[[1,4],[4,5]]`
Output: `[[1,5]]`

---

## Approach 1: Sorting and Merging (Optimal)

**Concept:**

- Sort the intervals by their starting time.  
- Initialize `start` and `end` with the first interval.  
- Traverse each interval and:
  - If the current interval overlaps (`interval[0] <= end`), update `end` as `max(end, interval[1])`.  
  - If it doesn't overlap, push `[start, end]` into result and update `start` and `end` to the current interval.  
- Push the last interval at the end.

**Complexity:**

- Time: `O(N log N)` — sorting takes `O(N log N)` and traversal takes `O(N)`.  
- Space: `O(N)` — for storing the merged intervals.

---