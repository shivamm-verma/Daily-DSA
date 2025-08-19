# First Missing Positive

## Problem Statement

**Difficulty:** Hard
**Topics:** Array, Hash Table (idea), In-place / Indexing tricks
**Companies:** (common interview favorite)

Given an **unsorted** integer array `nums`, return the **smallest positive** integer **not present** in `nums`.

You must implement an algorithm that runs in **O(n)** time and uses **O(1)** auxiliary space.

---

## Examples

### Example 1

```
Input:  nums = [1,2,0]
Output: 3
Explanation: 1 and 2 are present, so the smallest missing positive is 3.
```

### Example 2

```
Input:  nums = [3,4,-1,1]
Output: 2
Explanation: 1 is present but 2 is missing.
```

### Example 3

```
Input:  nums = [7,8,9,11,12]
Output: 1
Explanation: Smallest positive 1 is missing.
```

---

## Constraints

* `1 <= nums.length <= 10^5`
* `-2^31 <= nums[i] <= 2^31 - 1`

---

## Core Insight

For an array of length `n`, the answer must be in the range **\[1..n+1]**.
If all numbers `1..n` are present, the answer is `n+1`. Otherwise, it’s the first missing in that range.

---

## Solutions

### Approach A (Optimal): Index Marking via In-Place Sign Flips

**Idea:** Use the array itself as a presence bitmap for `1..n`.
We’ll mark “seen `k`” by flipping the sign of `nums[k-1]` to negative.

**Algorithm:**

1. **Check 1:** If `1` is missing anywhere, the answer is `1`.
2. **Normalize:** Replace all numbers `<=0` or `>n` with `1`. (They’re irrelevant.)
3. **Mark presence:** For each `a = abs(nums[i])` in range `1..n`, set `nums[a-1] = -|nums[a-1]|`.
4. **Scan:** First index `i` with `nums[i] > 0` → answer is `i+1`. If none → answer is `n+1`.

**Time:** O(n)
**Space:** O(1) (in-place)

#### Dry Run (nums = `[3,4,-1,1]`)

* Step 1 (check 1): present.
* Step 2 normalize: `[3,4,1,1]` (since `-1 → 1`)
* Mark:

  * See `3` → mark index `2`: `[3,4,-1,1]`
  * See `4` → mark index `3`: `[3,4,-1,-1]`
  * See `1` → mark index `0`: `[-3,4,-1,-1]`
  * See `1` → index `0` already negative
* Scan: index `1` is positive → answer `2`.

---

### Approach B (Optimal): Cyclic Placement (Index = value - 1)

**Idea:** Place each value `v` (if `1..n`) at index `v-1` by swapping until every valid number is in its spot. Then the first index `i` where `nums[i] != i+1` gives the answer.

**Algorithm:**

* For `i = 0..n-1`:

  * While `nums[i]` in `1..n` and `nums[nums[i]-1] != nums[i]`, swap `nums[i]` with `nums[nums[i]-1]`.
* Scan for first `i` with `nums[i] != i+1` → return `i+1`; else return `n+1`.

**Time:** O(n) amortized
**Space:** O(1)

---

## LeetCode-Style Implementations

### C++ (Approach A: Index Marking)

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        bool hasOne = false;
        for (int x : nums) if (x == 1) { hasOne = true; break; }
        if (!hasOne) return 1;

        // Normalize
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }

        // Mark presence
        for (int i = 0; i < n; i++) {
            int a = abs(nums[i]);
            if (a >= 1 && a <= n) {
                if (nums[a - 1] > 0) nums[a - 1] = -nums[a - 1];
            }
        }

        // Find first positive index
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};
```

### Java (Approach A: Index Marking)

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;

        boolean hasOne = false;
        for (int x : nums) if (x == 1) { hasOne = true; break; }
        if (!hasOne) return 1;

        // Normalize
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }

        // Mark presence
        for (int i = 0; i < n; i++) {
            int a = Math.abs(nums[i]);
            if (a >= 1 && a <= n) {
                if (nums[a - 1] > 0) nums[a - 1] = -nums[a - 1];
            }
        }

        // Find first positive index
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
}
```

### Python (Approach A: Index Marking)

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)

        # Check for 1
        if 1 not in nums:
            return 1

        # Normalize
        for i in range(n):
            if nums[i] <= 0 or nums[i] > n:
                nums[i] = 1

        # Mark presence
        for i in range(n):
            a = abs(nums[i])
            if 1 <= a <= n:
                if nums[a - 1] > 0:
                    nums[a - 1] = -nums[a - 1]

        # First positive index
        for i in range(n):
            if nums[i] > 0:
                return i + 1
        return n + 1
```

---

## Implementation Files

* **C++:** `FirstMissingPositive_index_marking.cpp`
* **Java:** `FirstMissingPositive_index_marking.java`
* **Python:** `first_missing_positive.py`
  (Each contains the ready-to-submit solution.)

---

## Key Insights

* The answer is always in `[1..n+1]`.
* Reusing the input array as a presence map avoids extra space.
* Two classic O(n)/O(1) methods: **Index Marking** and **Cyclic Placement**.

---

## Common Mistakes

1. Using extra data structures (like sets) → violates O(1) space.
2. Forgetting to handle non-positive and out-of-range values.
3. Off-by-one errors when mapping value `v` to index `v-1`.
4. Not checking for `1` early (fast exit case).

---

## Follow-ups / Related

* **268. Missing Number** (0..n range; XOR / sum trick)
* **448. Find All Numbers Disappeared in an Array** (similar marking trick)
* **442. Find All Duplicates in an Array** (marking/cyclic swap)

---

**Tags:** `Array` `In-Place` `Indexing` `Greedy-ish`
**Difficulty:** Hard
**Time Complexity:** O(n)
**Space Complexity:** O(1) (auxiliary)
