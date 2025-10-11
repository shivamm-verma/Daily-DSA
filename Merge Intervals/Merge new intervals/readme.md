
---

# 📂 File 2: `insert_interval.md`

```markdown
# Insert Interval (LeetCode 57)

## Description
You are given an array of non-overlapping intervals sorted by start times, and a new interval.  
Insert the new interval into the intervals (merge if necessary).

---

## Constraints
- `0 <= intervals.length <= 10^4`
- `intervals[i].length == 2`
- `0 <= start_i <= end_i <= 10^5`

---

## Test Cases
```text
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]

## Tips to Identify Pattern

Similar to merge intervals, but with one extra insertion.

Add all before newInterval, merge overlaps, add rest.