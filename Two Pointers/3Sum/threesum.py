class Solution(object):
    def threeSum(self, nums):
        nums.sort()
        lst = []
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j = i + 1
            k = len(nums) - 1
            while j < k:
                total = nums[i] + nums[j] + nums[k]
                if total == 0:
                    lst.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
                elif total > 0:
                    k -= 1
                else:
                    j += 1
        return lst


if __name__ == "__main__":
    try:
        user_input = input("Enter a list of integers separated by spaces: ")
        nums = list(map(int, user_input.strip().split()))
        solution = Solution()
        result = solution.threeSum(nums)
        print("Triplets that sum to zero:", result)
    except ValueError:
        print(" Invalid input. Please enter integers only.")