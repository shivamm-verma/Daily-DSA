from typing import List

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0

        m, n = len(matrix), len(matrix[0])
        dp = [[0] * n for _ in range(m)]

        directions = [(0,1),(0,-1),(1,0),(-1,0)]

        def dfs(x, y):
            if dp[x][y] != 0:
                return dp[x][y]

            maxx = 1
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and matrix[nx][ny] > matrix[x][y]:
                    maxx = max(maxx, 1 + dfs(nx, ny))

            dp[x][y] = maxx
            return maxx

        count = 1
        for i in range(m):
            for j in range(n):
                count = max(count, dfs(i, j))

        return count


# Example usage
matrix = [
    [9, 9, 4],
    [6, 6, 8],
    [2, 1, 1]
]
sol = Solution()
result = sol.longestIncreasingPath(matrix)
print("Longest Increasing Path:", result)
