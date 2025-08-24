class Solution(object):
    def threeSumClosest(self, nums, target):
        res = float('inf')
        nums.sort()
        for i in range(len(nums) - 2):
            j = i + 1
            k = len(nums) - 1
            while j < k:
                total = nums[i] + nums[j] + nums[k]
                if abs(total - target) < abs(res - target):
                    res = total
                if total > target:
                    k -= 1
                elif total < target:
                    j += 1
                else:
                    return res
        return res

if __name__ == "__main__":
    try:
        nums = list(map(int, input("Enter a list of integers separated by spaces: ").strip().split()))
        target = int(input("Enter the target integer: "))
        solution = Solution()
        print("The sum closest to the target is:", solution.threeSumClosest(nums, target))
    except ValueError:
        print("Invalid input. Please enter integers only.")
