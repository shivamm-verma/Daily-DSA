def uniquePaths(i, j):
    if i == 0 and j == 0:
        return 1
    if i < 0 or j < 0:
        return 0
    up = uniquePaths(i - 1, j)
    left = uniquePaths(i, j - 1)
    return up + left

# Driver code
m = 3
n = 7
print(uniquePaths(m - 1, n - 1))
