
# 238. Product of Array Except Self
**LeetCode Link:** [https://leetcode.com/problems/product-of-array-except-self/](https://leetcode.com/problems/product-of-array-except-self/)

## Problem Statement

**Difficulty:** Medium  
**Topics:** Array, Prefix Product, Suffix Product  
**Companies:** Amazon, Microsoft, Apple, Google, Facebook  

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.  

The algorithm must run in **O(n)** time and **without using division**.  

---

## Examples

### Example 1

```

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Explanation:
answer[0] = 2*3*4 = 24
answer[1] = 1*3*4 = 12
answer[2] = 1*2*4 = 8
answer[3] = 1*2*3 = 6

```

### Example 2

```

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

````

---

## Constraints

- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- The product of any prefix or suffix fits in a **32-bit integer**

---

## Solutions

### Approach 1: Brute Force (Not Recommended)

**Intuition:** For each index, multiply all elements except itself.  

**Algorithm:**
- For every index i
  - Multiply all elements `nums[j]` where `j != i`
  - Store in output  

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)  

---

### Approach 2: Prefix and Suffix Products (Optimal Solution)

**Intuition:**  
The result for index `i` is the product of all elements to the **left of i** multiplied by the product of all elements to the **right of i**.  

**Algorithm:**
1. Initialize `answer` array of size n with 1.  
2. Traverse from left to right:  
   - Maintain running product `prefix`.  
   - Set `answer[i] = prefix`.  
   - Update `prefix *= nums[i]`.  
3. Traverse from right to left:  
   - Maintain running product `suffix`.  
   - Multiply `answer[i] *= suffix`.  
   - Update `suffix *= nums[i]`.  

**Time Complexity:** O(n)  
**Space Complexity:** O(1) (ignoring output array)  

---

## Step-by-Step Walkthrough

For `nums = [1,2,3,4]`:  

**Step 1: Prefix Pass**

| i | nums[i] | prefix | answer[i] |
|---|---------|--------|-----------|
| 0 | 1       | 1      | 1         |
| 1 | 2       | 1      | 1         |
| 2 | 3       | 2      | 2         |
| 3 | 4       | 6      | 6         |

After prefix pass: `answer = [1,1,2,6]`

**Step 2: Suffix Pass**

| i | nums[i] | suffix | answer[i] (updated) |
|---|---------|--------|----------------------|
| 3 | 4       | 1      | 6 * 1 = 6           |
| 2 | 3       | 4      | 2 * 4 = 8           |
| 1 | 2       | 12     | 1 * 12 = 12         |
| 0 | 1       | 24     | 1 * 24 = 24         |

Final result: `answer = [24,12,8,6]`

---

## LeetCode-Style Solutions

### C++ Solution

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};
````

### Java Solution

```java
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] answer = new int[n];

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
}
```

### Python Solution

```python
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer = [1] * n

        prefix = 1
        for i in range(n):
            answer[i] = prefix
            prefix *= nums[i]

        suffix = 1
        for i in range(n-1, -1, -1):
            answer[i] *= suffix
            suffix *= nums[i]

        return answer
```

---

## Implementation Files

* **C++:** `cpp_code.cpp` - Complete implementation with test cases
* **Java:** `java_code.java` - Complete implementation with test cases
* **Python:** `python_code.py` - Complete implementation with test cases

---

## Key Insights

* **Core Concept:** Each element’s result = product of all elements before it × product of all elements after it
* **Optimization:** Prefix and suffix trick avoids nested loops
* **Edge Cases:**

  * Multiple zeros → all results = 0
  * Single zero → only that position holds product of others

---

## Common Mistakes

1. Using **division** (not allowed).
2. Forgetting to reset prefix/suffix correctly.
3. Mishandling arrays with zeros.

---

## Follow-up Questions

1. **What if division was allowed?** → Just compute total product and divide by `nums[i]` (fails with zeros).
2. **What if the array is extremely large?** → Consider streaming computation with limited memory.

---

## Related LeetCode Problems

* [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) (Prefix/Suffix technique)
* [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)

---

**Tags:** `Array` `Prefix Product` `Suffix Product`  

**Difficulty:** Medium  

**Time Complexity:** O(n)  

**Space Complexity:** O(1)  

---
