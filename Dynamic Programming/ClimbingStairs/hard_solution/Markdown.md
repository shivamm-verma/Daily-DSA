# Climbing Stairs - Hard Dynamic Programming Solution

## Problem
**Description:** You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**Examples:**
- Input: n = 2 → Output: 2
  - 1 step + 1 step
  - 2 steps
- Input: n = 3 → Output: 3
  - 1 step + 1 step + 1 step
  - 1 step + 2 steps
  - 2 steps + 1 step
- Input: n = 45 → Output: 1836311903 (handled efficiently with DP)

## Approach
This solution uses dynamic programming to avoid redundant calculations and achieve optimal performance.

**Step 1:** Initialize base cases
- dp[1] = 1 (only 1 way to climb 1 step)
- dp[2] = 2 (2 ways to climb 2 steps)

**Step 2:** Build solution bottom-up
- For each i from 3 to n: dp[i] = dp[i-1] + dp[i-2]
- This follows the Fibonacci pattern without recursion

**Step 3:** Return dp[n] as the final result

**Space Optimization:** Use only three variables instead of full array
- prev2, prev1, current to track last two values
- Achieve O(1) space complexity

## Generic Logic (Pseudocode)
```
function climbStairs(n):
    if n <= 2:
        return n
    dp = array of size n+1
    dp[1] = 1
    dp[2] = 2
    
    for i from 3 to n:
        dp[i] = dp[i-1] + dp[i-2]
    
    return dp[n]
function climbStairsOptimized(n):
    if n <= 2:
        return n
    
    prev2 = 1
    prev1 = 2
    
    for i from 3 to n:
        current = prev1 + prev2
        prev2 = prev1
        prev1 = current
    
    return prev1
```

## Complexities
**Time Complexity:** O(n) - Linear time to fill DP array or iterate through steps

**Space Complexity:** 
- DP Array approach: O(n) - Array to store intermediate results
- Space Optimized: O(1) - Only three variables used
