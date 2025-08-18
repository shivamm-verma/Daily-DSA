class Solution:
    def maxCoins(self, nums: list[int]) -> int:
        n = len(nums)
        arr = [1] + nums + [1]
        m = n + 2
        dp = [[0]*m for _ in range(m)]
        for length in range(2, m):
            for left in range(0, m - length):
                right = left + length
                for i in range(left+1, right):
                    dp[left][right] = max(dp[left][right], arr[left]*arr[i]*arr[right] + dp[left][i] + dp[i][right])
        return dp[0][m-1]

# quick test
if __name__ == '__main__':
    sol = Solution()
    print(sol.maxCoins([3,1,5,8]))  # 167