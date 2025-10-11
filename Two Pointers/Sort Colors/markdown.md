🎨 Sort Colors Problem

📘 Problem Statement
Given an array nums containing only integers 0, 1, and 2, sort the array in-place so that:
All 0s come first,
Followed by all 1s,
Then all 2s.
You cannot use the library sort function. The goal is to rearrange elements efficiently without extra space.

🧠 Approach
Use the Dutch National Flag algorithm with three pointers:
low → boundary for 0s
mid → current element
high → boundary for 2s

Traverse the array while mid <= high:
If nums[mid] == 0: swap with nums[low], increment low and mid.
If nums[mid] == 1: move mid forward.
If nums[mid] == 2: swap with nums[high], decrement high.

This ensures all 0s are at the start, 2s at the end, and 1s remain in the middle.
This method sorts the array in one pass without extra space.

📊 Example

Input:
nums = [2, 0, 2, 1, 1, 0]

Output:
[0, 0, 1, 1, 2, 2]

Explanation:
0s are moved to the start,
1s are in the middle,
2s are moved to the end.

⏱️ Time Complexity
Single-pass traversal: O(n)

Overall: O(n)

🧮 Space Complexity
In-place: O(1)

No extra arrays are used; only a few pointers.

📚 Topics Covered
Array manipulation
Two-pointer / Three-pointer technique
In-place sorting
Dutch National Flag algorithm
Constant space optimization