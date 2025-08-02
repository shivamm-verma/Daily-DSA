## Search in Rotated Sorted Array — Approaches Explained

### Problem Statement
You are given an integer array `nums` sorted in ascending order (with **distinct** values), and an integer `target`. The array is rotated at some pivot unknown to you beforehand. Find the index of `target` in the array. If `target` is not found, return `-1`.

**Note**: You must write an algorithm with `O(log n)` runtime complexity.

### 📘 Example

#### Input
```text
nums = [4,5,6,7,0,1,2]
target = 0
Output: 4
```

#### Visual Diagram
```text
Original sorted array: [0,1,2,4,5,6,7]
After rotation at pivot 4: [4,5,6,7,0,1,2]
                            ↑       ↑
                         left=0   target at index 4
```

**Key Insight**: The array is split into two sorted portions around the rotation point.

---

### 1️⃣ Brute Force Approach (Linear Search)

#### Idea
- Iterate through the entire array linearly.
- Check each element to see if it matches the target.
- Return the index when found, or -1 if not found.

#### Why Brute Force?
- Ignores the sorted property of the rotated array
- Doesn't leverage the rotation structure
- Simple but inefficient for large arrays

#### Complexity
- Time: O(n)
- Space: O(1)


---

### 2️⃣ Better Approach (Find Pivot + Binary Search)

#### Idea
- First, find the pivot (rotation point) where the array was rotated.
- Once pivot is found, determine which half contains the target.
- Apply binary search on the appropriate sorted half.

#### Advantage
- Leverages the fact that both halves are individually sorted
- Uses binary search which is more efficient than linear search
- Clear separation of concerns (find pivot, then search)

#### Complexity
- Time: O(log n) for finding pivot + O(log n) for binary search = O(log n)
- Space: O(1)

---

### 3️⃣ Optimal Approach (Single Pass Binary Search)

#### Idea
- Use modified binary search in a single pass.
- At each step, determine which half is sorted.
- Check if target lies in the sorted half; if yes, search there, otherwise search the other half.
- This eliminates the need to find the pivot separately.

#### Why Optimal?
- **Single Pass**: Only one binary search needed
- **Space Efficient**: O(1) space complexity
- **Time Efficient**: O(log n) with minimal constant factors
- **Elegant Logic**: Handles rotation seamlessly during search

#### Key Insight
In a rotated sorted array, at least one half (left or right) is always completely sorted.

#### Complexity
- Time: O(log n)
- Space: O(1)

---

### 🔍 Algorithm Walkthrough (Optimal Approach)

For `nums = [4,5,6,7,0,1,2]`, `target = 0`:

| Step | left | right | mid | nums[mid] | Left Half Sorted? | Action |
|------|------|-------|-----|-----------|-------------------|---------|
| 1 | 0 | 6 | 3 | 7 | Yes [4,5,6,7] | target(0) not in [4,7], go right |
| 2 | 4 | 6 | 5 | 1 | No, right sorted [1,2] | target(0) not in [1,2], go left |
| 3 | 4 | 4 | 4 | 0 | Found! | Return 4 |

---

### 📊 Comparison Summary

| Approach | Time Complexity | Space Complexity | Pros | Cons |
|----------|----------------|------------------|------|------|
| **Brute Force** | O(n) | O(1) | Simple, works for any array | Doesn't leverage sorted property |
| **Better** | O(log n) | O(1) | Clear logic, easy to understand | Two separate binary searches |
| **Optimal** | O(log n) | O(1) | Single pass, most efficient | Slightly more complex logic |

---