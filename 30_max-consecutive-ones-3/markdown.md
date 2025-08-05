Problem: Max Consecutive Ones III
LeetCode ID: 1004
Difficulty: Medium

📝 Problem Statement
You are given a binary array nums and an integer k.

You can flip at most k 0's to 1's in the array.

Return the maximum number of consecutive 1's in the array after at most k flips.

💡Example:
Input:
nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output:
6
Explanation:
Flip the 0's at index 5 and 10.

The array becomes [1,1,1,0,0,1,1,1,1,1,1], which has 6 consecutive 1's from index 5 to 10.

✅ Constraints:
1 <= nums.length <= 10^5

nums[i] is either 0 or 1

0 <= k <= nums.length

#bruteforce

🐢 Brute-Force Approach

💡 Idea:
For every subarray, count the number of 0's.

If the number of 0's is ≤ k, check if it's the longest such subarray.

Time complexity: O(n²)

Steps:
Loop over every possible starting index i.

From i, try every possible ending index j.

For each subarray nums[i...j], count number of 0's.

If zero count ≤ k, update max length.

#optimal

🧠 Optimal Approach: Sliding Window
Key Idea:
Maintain a window that contains at most k zeroes.

Expand the window by moving the right pointer.

If the window contains more than k zeroes, shrink it from the left.

Steps:
Use two pointers: left and right to maintain the window.

Track the count of zeroes in the window.

When the zero count exceeds k, move the left pointer forward until the count is back within the limit.

At each step, update the max length of the window.

⌛ Time Complexity:
O(n^2)-bruteforce code
O(n) - optimal , where n is the length of the array — each element is visited at most twice (once by right, once by left).
space complexity:
O(1)- for bruteforce and optimal codes.
