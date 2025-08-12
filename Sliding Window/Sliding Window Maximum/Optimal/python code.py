from typing import List
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q = deque()  # Deque to store indices of elements in decreasing order
        res = []

        for i, cur in enumerate(nums):
            # Remove indices whose values are less than or equal to current element
            # They are no longer useful as they can't be max in current or future windows
            while q and nums[q[-1]] <= cur:
                q.pop()

            # Add the current index
            q.append(i)

            # Remove the front if it's outside the current window (i - k)
            # This keeps the deque valid for the current window
            if q[0] == i - k:
                q.popleft()

            # Start recording max values after the first k elements
            # The front of deque holds the index of the maximum value for the current window
            if i >= k - 1:
                res.append(nums[q[0]])

        return res

