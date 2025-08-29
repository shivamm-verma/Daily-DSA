from typing import List

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        """
        Greedy solution: track the furthest reachable index.
        Time: O(n), Space: O(1)
        """
        max_reach = 0
        n = len(nums)
        for i, jump in enumerate(nums):
            if i > max_reach:
                return False
            max_reach = max(max_reach, i + jump)
            if max_reach >= n - 1:
                return True
        return True

if __name__ == "__main__":
    solution = Solution()
    print(solution.canJump([2, 3, 1, 1, 4]))  # True
    print(solution.canJump([3, 2, 1, 0, 4]))  # False
