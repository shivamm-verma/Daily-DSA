def cutRod(price, ind, n, dp):
    if ind == 0:
        return n * price[0]
    if dp[ind][n] != -1:
        return dp[ind][n]
    
    not_take = cutRod(price, ind - 1, n, dp)
    take = float('-inf')
    rod_len = ind + 1
    if rod_len <= n:
        take = price[ind] + cutRod(price, ind, n - rod_len, dp)
    
    dp[ind][n] = max(take, not_take)
    return dp[ind][n]

price = [1, 5, 8, 9, 10, 17, 17, 20]
n = len(price)
dp = [[-1] * (n + 1) for _ in range(n)]
print(cutRod(price, n - 1, n, dp))
