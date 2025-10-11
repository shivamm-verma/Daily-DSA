
---

# 📂 File 4: `non_overlapping_intervals.md`

```markdown
# Non-overlapping Intervals (LeetCode 435)

## Description
Given a collection of intervals, return the **minimum number of intervals you need to remove** to make the rest of the intervals non-overlapping.

---

## Constraints
- `1 <= intervals.length <= 10^5`
- `intervals[i].length == 2`
- `-5 * 10^4 <= start_i < end_i <= 5 * 10^4`

---

## Test Cases
```text
Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1

Input: [[1,2],[1,2],[1,2]]
Output: 2

Input: [[1,2],[2,3]]
Output: 0

# Tips to identify the pattern
Tips to Identify Pattern

Sort intervals by end time.

Always keep interval with smallest end (greedy).

If overlap → remove the one with bigger end.