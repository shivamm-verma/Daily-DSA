def uniquePaths(i, j, dp):
    if i == 0 and j == 0:
        return 1
    if i < 0 or j < 0:
        return 0
    if dp[i][j] != -1:
        return dp[i][j]
    
    up = uniquePaths(i - 1, j, dp)
    left = uniquePaths(i, j - 1, dp)
    dp[i][j] = up + left
    return dp[i][j]

# Driver code
m, n = 3, 7
dp = [[-1 for _ in range(n)] for _ in range(m)]
print(uniquePaths(m - 1, n - 1, dp))
