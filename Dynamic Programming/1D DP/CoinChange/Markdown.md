# Minimum Number of Coins - Dynamic Programming Solution
## Problem
**Description:** You are given an amount X (the total value) and a set of coin denominations. Your task is to determine the minimum number of coins required to make the value X. If it is not possible to make the amount using the given denominations, return -1.

**Examples:**
- Input: coins = [1, 3, 4], X = 6 → Output: 2
- 3 + 3
- 4 + 1 + 1 (not minimum)
- Input: coins = [2], X = 3 → Output: -1

## Approach
This solution uses Dynamic Programming (Bottom-Up Tabulation) to avoid repeated subproblem calculations.

**Step 1:** Initialize a DP array of size X+1,where dp[i]represents the minimum coins needed to make amount i.
- Set dp[0] = 0 (0 coins to make amount 0).
- Initialize all other values with a large number (X+1) to represent "infinity".

**Step 2:** Iterate through each amount i from 1 to X:
- For each coin, check if it can contribute (coin <= i).
- Update dp[i] = min(dp[i], 1 + dp[i - coin]).

**Step 3:** After filling the DP array, if dp[X] > X, return -1 (not possible). Otherwise, return dp[X].

## Generic Logic (Pseudocode)
```
function minCoins(coins, X):
    dp = array of size (X+1) filled with X+1
    dp[0] = 0
    
    for i from 1 to X:
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], 1 + dp[i - coin])
    
    if dp[X] > X:
        return -1
    return dp[X]
```

## Complexities
**Time Complexity:** O(X * n)-X is the target amount,n is the number of coin types
**Space Complexity:** O(X)

Only a 1D DP array is used.