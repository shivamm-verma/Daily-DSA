class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        return self.atMost(nums, k) - self.atMost(nums, k - 1)

    def atMost(self, nums, k):
        left = 0
        res = 0

        for right in range(len(nums)):
            if nums[right] % 2 == 1:
                k -= 1

            while k < 0:
                if nums[left] % 2 == 1:
                    k += 1
                left += 1

            res += right - left + 1

        return res
