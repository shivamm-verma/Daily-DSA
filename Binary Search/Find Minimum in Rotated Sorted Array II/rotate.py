class Solution:
    def findMin(self, nums):
        lo, hi = 0, len(nums) - 1

        # If array is not rotated
        if nums[lo] < nums[hi]:
            return nums[lo]

        while lo < hi:
            mid = lo + (hi - lo) // 2

            if nums[mid] > nums[hi]:
                lo = mid + 1
            elif nums[mid] > nums[lo]:
                hi = mid
            else:
                hi -= 1
        return nums[lo]


if __name__ == "__main__":
    n = int(input("Enter number of elements: "))
    nums = list(map(int, input("Enter array elements: ").split()))

    sol = Solution()
    print("Minimum element in rotated array:", sol.findMin(nums))
