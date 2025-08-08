def knapsack(ind, wt, val, capacity, dp):
    if ind == 0:
        return (capacity // wt[0]) * val[0]
    
    if dp[ind][capacity] != -1:
        return dp[ind][capacity]
    
    not_take = knapsack(ind - 1, wt, val, capacity, dp)
    take = float('-inf')
    if wt[ind] <= capacity:
        take = val[ind] + knapsack(ind, wt, val, capacity - wt[ind], dp)
    
    dp[ind][capacity] = max(take, not_take)
    return dp[ind][capacity]

if __name__ == "__main__":
    val = [6, 1, 7, 7]
    wt = [1, 3, 4, 5]
    capacity = 8
    n = len(wt)
    
    # Initialize dp array with -1
    dp = [[-1 for _ in range(capacity + 1)] for _ in range(n)]
    
    print(knapsack(n - 1, wt, val, capacity, dp))
