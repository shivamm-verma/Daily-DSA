class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        n = len(nums)
        k = k % n

        self.reverse(nums, 0, n - k - 1)
        self.reverse(nums, n - k, n - 1)
        self.reverse(nums, 0, n - 1)

    def reverse(self, nums: list[int], start: int, end: int) -> None:
        while start <= end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
