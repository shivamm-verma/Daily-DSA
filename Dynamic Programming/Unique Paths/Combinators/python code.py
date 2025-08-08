def uniquePaths(m, n):
    N = m + n - 2
    r = m - 1
    res = 1.0
    for i in range(1, r + 1):
        res = res * (N - r + i) / i
    return int(res)

# Driver code
m = 3
n = 7
print(uniquePaths(m, n))
