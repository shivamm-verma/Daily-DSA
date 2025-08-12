from typing import List

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        res = []

        # Loop over each window
        for i in range(n - k + 1):
            window = nums[i:i + k]
            max_val = max(window)  # Find the max in the current window
            res.append(max_val)

        return res

