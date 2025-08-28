# 🏃 Jump Game Problem

## 📝 Problem Statement

You are given an integer array `nums` where each element represents the maximum number of steps you can jump forward from that position. You are initially positioned at the **first index** of the array.

Return `true` if you can reach the **last index**, or `false` otherwise.

**Constraints:**
1. You can only move forward (no backward jumps).
2. From index `i`, you can jump to any index from `i+1` to `i+nums[i]`.
3. The goal is to determine if the last index is reachable.

---

##  Example

**Input:**  
`nums = [2, 3, 1, 1, 4]`

**Output:**  
`true`

**Explanation:**  
- Start at index 0 (value 2) → can jump to index 1 or 2
- Jump to index 1 (value 3) → can jump to index 2, 3, or 4
- Jump to index 4 (last index) → **Goal reached!**

**Alternative path:** 0 → 2 → 3 → 4

---

**Input:**  
`nums = [3, 2, 1, 0, 4]`

**Output:**  
`false`

**Explanation:**  
- You will always arrive at index 3 (value 0)
- From index 3, you cannot jump anywhere (0 steps allowed)
- Index 4 is unreachable

---

##  Approach (Greedy - Farthest Reach)

###  Step-by-Step Breakdown

1. **Initialize** `maxReach = 0` to track the maximum reachable index.
2. **Iterate** through each index `i` from 0 to `n-1`:
   - If `i > maxReach`, return `false` (current position is unreachable).
   - Update `maxReach = max(maxReach, i + nums[i])`.
   - If `maxReach >= n-1`, return `true` (last index is reachable).
3. **Return** `true` (if loop completes without early termination).

### 🔄 Alternative Approach (Working Backwards)

1. Start from the **last index** as the target.
2. **Iterate backwards** from `n-2` to 0:
   - If `i + nums[i] >= target`, update `target = i`.
3. **Return** `target == 0` (first index can reach the original target).

---

##  Time and Space Complexity

| Metric            | Value         | Explanation                                      |
|-------------------|---------------|--------------------------------------------------|
| Time Complexity   | `O(n)`        | Single pass through the array                    |
| Space Complexity  | `O(1)`        | Only using constant extra space                  |

---

## 📌 Notes

- This is a classic **greedy algorithm** problem.
- The key insight is to track the **farthest reachable position** at each step.
- No need to explore all possible paths - greedy approach is optimal.
- The backwards approach can be more intuitive for some developers.
- Edge case: If array has only one element, return `true` (already at target).

---

## 🎯 Key Insights

- **Greedy Choice:** Always try to reach as far as possible from current position.
- **Early Termination:** Return `true` as soon as last index becomes reachable.
- **Unreachable Detection:** If current index > maxReach, impossible to proceed.

---


### Python Solution
```python
from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        """
        Greedy solution: track the furthest reachable index.
        Time: O(n), Space: O(1)
        """
        max_reach = 0
        n = len(nums)
        for i, jump in enumerate(nums):
            if i > max_reach:
                return False
            max_reach = max(max_reach, i + jump)
            if max_reach >= n - 1:
                return True
        return True

if __name__ == "__main__":
    solution = Solution()
    print(solution.canJump([2, 3, 1, 1, 4]))  # True
    print(solution.canJump([3, 2, 1, 0, 4]))  # False
```

### Java Solution
```java
// Greedy approach: track furthest reachable index.
// Time: O(n), Space: O(1)
class Solution {
    public boolean canJump(int[] nums) {
        int maxReach = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false;
            maxReach = Math.max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) return true;
        }
        return true;
    }
    
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.canJump(new int[]{2, 3, 1, 1, 4})); // true
        System.out.println(solution.canJump(new int[]{3, 2, 1, 0, 4})); // false
    }
}
```

### C++ Solution
```cpp
// Greedy: track the furthest reachable index.
// Time: O(n), Space: O(1)
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
       
        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) return true;
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
   
    cout << (solution.canJump(nums1) ? "true" : "false") << endl;  // true
    cout << (solution.canJump(nums2) ? "true" : "false") << endl;  // false
}
```