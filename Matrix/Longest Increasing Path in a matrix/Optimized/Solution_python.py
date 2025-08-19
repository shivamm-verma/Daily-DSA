from collections import deque

class Solution:
    def longestIncreasingPath(self, matrix):
        if not matrix or not matrix[0]:
            return 0

        m, n = len(matrix), len(matrix[0])
        indegree = [[0] * n for _ in range(m)]
        dp = [[1] * n for _ in range(m)]  # every cell has at least length 1

        dx = [0, 0, -1, 1]
        dy = [-1, 1, 0, 0]

        # calculate indegree for each cell
        for i in range(m):
            for j in range(n):
                for k in range(4):
                    nx, ny = i + dx[k], j + dy[k]
                    if 0 <= nx < m and 0 <= ny < n and matrix[nx][ny] < matrix[i][j]:
                        indegree[i][j] += 1

        # queue initialization with indegree == 0
        q = deque()
        for i in range(m):
            for j in range(n):
                if indegree[i][j] == 0:
                    q.append((i, j))

        maxLength = 1

        # process topological order
        while q:
            x, y = q.popleft()
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                if 0 <= nx < m and 0 <= ny < n and matrix[nx][ny] > matrix[x][y]:
                    dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1)
                    maxLength = max(maxLength, dp[nx][ny])
                    indegree[nx][ny] -= 1
                    if indegree[nx][ny] == 0:
                        q.append((nx, ny))

        return maxLength


# Example usage
if __name__ == "__main__":
    matrix = [
        [9, 9, 4],
        [6, 6, 8],
        [2, 1, 1]
    ]
    sol = Solution()
    result = sol.longestIncreasingPath(matrix)
    print("Longest Increasing Path:", result)
