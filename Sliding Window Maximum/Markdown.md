🧊 Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.


```  

Example 1:

Input: nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3  
Output: [3, 3, 5, 5, 6, 7]  
Explanation:  
Window position          Max  
---------------------    ----  
[1  3 -1] -3  5  3  6  7   3  
 1 [3 -1 -3] 5  3  6  7    3  
 1  3 [-1 -3 5] 3  6  7    5  
 1  3 -1 [-3 5 3] 6  7     5  
 1  3 -1 -3 [5 3 6] 7      6  
 1  3 -1 -3  5 [3 6 7]     7  

Example 2:

Input: nums = [1], k = 1  
Output: [1]

``` 

 

Method 1 :- 🔁 Brute Force Approach
💡 Idea
For every possible window of size k, loop through the window and find the maximum manually.

Slide the window one step to the right and repeat.

🔢 Steps:
Loop from i = 0 to n - k.

For each window [i, i+k-1], iterate through the elements and find the max.

Append the max to the result array.

📈 Complexity:
Time Complexity: O(n * k)
(You loop through each window and within that window again.)

Space Complexity: O(1)
(No extra space apart from result array.)


Method 2 :- 🚀 Optimal Approach — Monotonic Deque (Sliding Window Maximum)
💡 Idea
Use a deque to store indices of elements.

The deque is maintained in decreasing order of values.

The front of the deque always holds the index of the maximum element for the current window.

🔢 Steps:
Iterate through the array nums.

Before inserting a new element:

Remove elements from the back that are less than the current element.

Remove the front if it's outside the current window.

Insert the current index into the deque.

The front of the deque now holds the index of the max in the current window.

Start appending results once the first full window is formed (i ≥ k - 1).

📈 Complexity:
Time Complexity: O(n)
Each element is added and removed from the deque at most once.

Space Complexity: O(k)
For storing indices in the deque.



Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length