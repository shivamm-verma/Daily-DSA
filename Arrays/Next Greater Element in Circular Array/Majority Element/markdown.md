# 169. Majority Element

## Problem Statement

**Difficulty:** Easy
**Topics:** Array, Hash Table, Divide and Conquer, Sorting, Counting
**Companies:** Amazon, Microsoft, Apple, Google, Facebook

You are given an integer array `nums` of size `n`.

Return the **majority element** — the element that appears more than ⌊ n/2 ⌋ times.

It is guaranteed that the majority element **always exists** in the array.

---

## Examples

### Example 1

```
Input: nums = [3,2,3]
Output: 3
```

### Example 2

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

---

## Constraints

* `n == nums.length`
* `1 <= n <= 5 * 10⁴`
* `-10⁹ <= nums[i] <= 10⁹`
* The majority element always exists.

---

## Solutions

### Approach 1: Hash Map (Counting)

**Intuition:**
Count the frequency of each element and return the one with count > n/2.

**Algorithm:**

1. Create a hash map (dictionary) to store counts.
2. Iterate through `nums` and count occurrences.
3. Return the element whose count > ⌊ n/2 ⌋.

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

### Approach 2: Sorting

**Intuition:**
If the array is sorted, the majority element must occupy the middle index.

**Algorithm:**

1. Sort the array.
2. Return `nums[n//2]`.

**Time Complexity:** O(n log n)
**Space Complexity:** O(1) (if in-place sort)

---

### Approach 3: Boyer–Moore Voting Algorithm (Optimal)

**Intuition:**
Since the majority element appears more than half the time, we can cancel out each occurrence of a different element.
The one that remains must be the majority.

**Algorithm:**

1. Initialize `count = 0`, `candidate = None`.
2. For each element:

   * If `count == 0`, set `candidate = element`.
   * If element == candidate → increment count.
   * Else → decrement count.
3. Return `candidate`.

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

## Step-by-Step Walkthrough (Boyer–Moore)

For `nums = [2,2,1,1,1,2,2]`:

| Step | Num | Candidate | Count |
| ---- | --- | --------- | ----- |
| 1    | 2   | 2         | 1     |
| 2    | 2   | 2         | 2     |
| 3    | 1   | 2         | 1     |
| 4    | 1   | 2         | 0     |
| 5    | 1   | 1         | 1     |
| 6    | 2   | 1         | 0     |
| 7    | 2   | 2         | 1     |

Result → **2**

---

## LeetCode-Style Solutions

### C++ Solution

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
```

### Java Solution

```java
class Solution {
    public int majorityElement(int[] nums) {
        int candidate = 0, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
}
```

### Python Solution

```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = None
        count = 0
        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)
        return candidate
```

---

## Key Insights

* **Core Concept:** Majority element always exists → we don’t need extra validation.
* **Optimization:** Boyer–Moore voting reduces space to O(1).
* **Edge Cases:** None (problem guarantees a majority exists).

---

## Common Mistakes

1. Forgetting that the majority element **always exists** (no need to check).
2. Using sorting unnecessarily when O(n) solutions exist.
3. Miscounting in Boyer–Moore by not resetting candidate correctly.

---

## Follow-up Questions

1. **What if the majority element doesn’t always exist?**
   → Verify candidate with an extra pass.

2. **What if we need all elements appearing more than n/3 times?**
   → Use extended Boyer–Moore (find up to 2 candidates).

---

## Related LeetCode Problems

* [229. Majority Element II](https://leetcode.com/problems/majority-element-ii/) (Medium)
* [1157. Online Majority Element In Subarray](https://leetcode.com/problems/online-majority-element-in-subarray/) (Hard)

---

**Tags:** `Array` `Hash Table` `Divide and Conquer` `Sorting` `Counting`
**Difficulty:** Easy
**Time Complexity:** O(n)
**Space Complexity:** O(1)
