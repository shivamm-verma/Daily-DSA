# Wildcard Pattern Matching - Dynamic Programming Solution
## Problem
**Description:**  You are given an input string `s` and a pattern `p`. Implement wildcard pattern matching with support for the following rules:

- `?` matches **exactly one character**.  
- `*` matches **any sequence of characters** (including the empty sequence).  

The matching should cover the **entire input string** (not partial matching).

**Examples:**
- Input: s = "aa", p = "a" → Output: false  
- Input: s = "aa", p = "*" → Output: true  
- Input: s = "cb", p = "?a" → Output: false  
- Input: s = "adceb", p = "*a*b" → Output: true  
- Input: s = "acdcb", p = "a*c?b" → Output: false  

## Approach
This solution uses **Dynamic Programming (Bottom-Up Tabulation)** to avoid repeated subproblem calculations.  

We define a 2D DP table `dp[i][j]` where:
- `dp[i][j]` = whether the first `i` characters of `s` match the first `j` characters of `p`.

### Step 1: Initialization
- `dp[0][0] = true` (empty string matches empty pattern).  
- For patterns starting with `*`, set `dp[0][j] = dp[0][j-1]` because `*` can represent an empty sequence.

### Step 2: Fill DP table
For each `i` (1 to n) and `j` (1 to m):
- If `p[j-1] == s[i-1]` or `p[j-1] == '?'`:  
  `dp[i][j] = dp[i-1][j-1]`
- If `p[j-1] == '*'`:  
  `dp[i][j] = dp[i-1][j] || dp[i][j-1]`  
  (`*` matches one more character OR empty sequence)
- Otherwise:  
  `dp[i][j] = false`

### Step 3: Result
- The answer is stored in `dp[n][m]` where `n = len(s)` and `m = len(p)`.

## Generic Logic (Pseudocode)
```
function isMatch(s, p):
    n = length of s
    m = length of p
    dp = 2D array of size (n+1) x (m+1), initialized to false
    dp[0][0] = true
    for j from 1 to m:
        if p[j-1] == '*':
            dp[0][j] = dp[0][j-1]
    for i from 1 to n:
        for j from 1 to m:
            if p[j-1] == s[i-1] or p[j-1] == '?':
                dp[i][j] = dp[i-1][j-1]
            else if p[j-1] == '*':
                dp[i][j] = dp[i-1][j] or dp[i][j-1]
    
    return dp[n][m]

```
## Complexities
**Time Complexity:** O(n × m)  
- `n` = length of string `s`  
- `m` = length of pattern `p`  

**Space Complexity:** O(n × m)  
- A 2D DP table is used.  

