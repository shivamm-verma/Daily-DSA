# Climbing Stairs - Easy Recursive Solution
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

## Approach
This solution uses simple recursion to explore all possible ways to climb the stairs.

**Step 1:** Check base cases
- If n ≤ 2, return n directly
- If n = 1, return 1 (only 1 way)
- If n = 2, return 2 (2 ways)

**Step 2:** For n > 2, use recursive formula
- Total ways = ways(n-1) + ways(n-2)
- This follows the Fibonacci pattern

**Step 3:** Return the calculated result

## Generic Logic (Pseudocode)
```
function climbStairs(n):
    if n <= 2:
        return n
    
    return climbStairs(n-1) + climbStairs(n-2)
```

## Complexities
**Time Complexity:** O(2^n) - Exponential due to repeated calculations of same subproblems

**Space Complexity:** O(n) - Recursion stack depth for storing function calls
