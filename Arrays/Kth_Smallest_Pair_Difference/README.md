✅ DSA Question: Kth Smallest Pair Difference 

🧠 Problem

Given an array of integers, find the Kth smallest absolute difference between any two elements.  
Equivalent to LeetCode #719 — “Kth Smallest Pair Distance”.

Examples:

Input: arr = [1, 3, 4], k = 2 → Output: 2  
Input: arr = [1, 1, 3], k = 2 → Output: 2  

🧭 Approach
1. Sort the array.  
2. Use binary search on the difference value `d`.  
3. For each `d`, count pairs with difference ≤ d using two pointers.  
4. If count ≥ k → move left; else move right.  
5. Return the smallest `d` satisfying the condition.

🔁 Generic Logic (Pseudocode)
function smallestDistancePair(nums, k):
    sort nums
    left = 0
    right = max(nums) - min(nums)

    while left < right:
        mid = (left + right) / 2
        if count_pairs(mid) >= k:
            right = mid
        else:
            left = mid + 1
    return left

function count_pairs(mid):
    count = 0
    left = 0
    for right in range(len(nums)):
        while nums[right] - nums[left] > mid:
            left += 1
        count += right - left
    return count

⏱️ Complexities
Time Complexity: O(n log W), where W = max(arr) - min(arr)  
Space Complexity: O(1)  

🧩 Bonus / Extensions
- Can be extended to “Kth Largest Pair Difference” or “Kth Smallest Pair Sum”.
