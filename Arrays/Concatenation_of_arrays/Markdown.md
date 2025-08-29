# Concatenation of array

## 🧠 Problem Statement
Given an integer array nums of length n, you need to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n. Specifically, ans is the concatenation of two nums arrays.

## 🧪 Example Input/Output

### Example 1:
**Input:** 
nums = [1, 2, 3]

**Output:** 
[1, 2, 3, 1, 2, 3]

### Example 2:
**Input:** 
nums = [1,2,1]

**Output:** 
[1, 2, 1, 1, 2, 1]

Explanation:
The array ans is formed by concatenating two copies of nums.

✅ Constraints
1 <= nums.length <= 1000
1 <= nums[i] <= 1000

🔁 Steps
Create a new array ans with length 2*n
Iterate through the original array
For each element at index i, place it at both ans[i] and ans[i+n]
Return the concatenated array

## 🔁 Generic Logic
### Optimal Approach
## Key Idea

The most straightforward approach is to create a new array of double the size and manually copy each element from the original array twice.
While the brute-force approach is already optimal for this problem (O(n) time), we can consider language-specific optimizations:

Java/C++: Manual copying remains most efficient

## ⏱ Time and Space Complexity

Time Complexity: O(n) - We need to copy all elements twice
Space Complexity: O(n) - We create a new array of size 2n
