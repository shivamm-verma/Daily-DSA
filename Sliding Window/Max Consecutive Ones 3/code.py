class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        zeros = 0
        max_len = 0
        i = 0
        j = 0
        n = len(nums)

        while i < n and j < n:
            if nums[j] == 1:
                j += 1
            elif nums[j] == 0:
                zeros += 1
                j += 1

            while i < n and zeros > k:
                if nums[i] == 0:
                    zeros -= 1
                i += 1

            max_len = max(max_len, j - i)
        
        return max_len
