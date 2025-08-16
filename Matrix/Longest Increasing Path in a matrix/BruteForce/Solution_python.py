from typing import List

class Solution:
    def dfs(self, matrix: List[List[int]], x: int, y: int) -> int:
        m, n = len(matrix), len(matrix[0])
        maxPath = 1
        directions = [(0,1), (0,-1), (1,0), (-1,0)]

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < m and 0 <= ny < n and matrix[nx][ny] > matrix[x][y]:
                maxPath = max(maxPath, 1 + self.dfs(matrix, nx, ny))

        return maxPath

    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        m, n = len(matrix), len(matrix[0])
        result = 1

        for i in range(m):
            for j in range(n):
                result = max(result, self.dfs(matrix, i, j))

        return result


# Example usage
matrix = [
    [9, 9, 4],
    [6, 6, 8],
    [2, 1, 1]
]
sol = Solution()
result = sol.longestIncreasingPath(matrix)
print("Longest Increasing Path:", result)
