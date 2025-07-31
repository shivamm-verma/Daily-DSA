def knapsack(wt, val, capacity, n):
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n)]

    for w in range(capacity + 1):
        dp[0][w] = (w // wt[0]) * val[0]

    for i in range(1, n):
        for w in range(capacity + 1):
            not_take = dp[i - 1][w]
            take = float('-inf')
            if wt[i] <= w:
                take = val[i] + dp[i][w - wt[i]]
            dp[i][w] = max(not_take, take)

    return dp[n - 1][capacity]

if __name__ == "__main__":
    val = [6, 1, 7, 7]
    wt = [1, 3, 4, 5]
    capacity = 8
    print(knapsack(wt, val, capacity, len(wt)))
