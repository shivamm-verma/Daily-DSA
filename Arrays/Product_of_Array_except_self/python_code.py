from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer = [1] * n

        # Step 1: Prefix product
        prefix = 1
        for i in range(n):
            answer[i] = prefix
            prefix *= nums[i]

        # Step 2: Suffix product
        suffix = 1
        for i in range(n-1, -1, -1):
            answer[i] *= suffix
            suffix *= nums[i]

        return answer

# Example usage
if __name__ == "__main__":
    sol = Solution()
    nums = [1, 2, 3, 4]
    result = sol.productExceptSelf(nums)
    print(result)  # Output: [24, 12, 8, 6]
