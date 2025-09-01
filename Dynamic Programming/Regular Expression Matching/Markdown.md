✅ **DSA Question: Regular Expression Matching**
***
### 🧠 Problem
You are given an input string `s` and a pattern `p`. Your task is to implement regular expression matching with support for two special characters:
- `.` (dot): Matches any single character.
- `*` (asterisk): Matches zero or more of the preceding element.

The matching must cover the entire input string, not just a part of it.

**Examples:**
- Input: `s = "aab"`, `p = "c*a*b"` → Output: `true`
  - **Explanation**: `c*` matches zero instances of 'c', `a*` matches two instances of 'a'. The pattern successfully matches "aab".
- Input: `s = "mississippi"`, `p = "mis*is*p*."` → Output: `false`
***
### 🤔 Approach 1: Brute Force (Recursive)
**Idea**

-  Define a recursive function isMatch(i, j) that checks `s` from index `i` against `p` from index `j`.
-  If the next pattern character is `*`, explore two possibilities:
   -  Matching zero elements (by skipping ahead in the pattern).
   -  Matching one element (by advancing in the string).
-  If there's no `*`, proceed only if the current characters match.

**Advantage**

- Direct translation of the problem's logic.
- The code structure is straightforward and easy to understand initially.

#### 💻 Generic Logic (Pseudocode)
```
function isMatch(s, p, i, j):
  // Base case: if pattern is exhausted, text must also be
  if j == length(p):
    return i == length(s)

  first_match = (i < length(s) and (p[j] == s[i] or p[j] == '.'))

  // If next char is '*'
  if j + 1 < length(p) and p[j+1] == '*':
    //           (zero occurrences)       or (one or more occurrences)
    return isMatch(s, p, i, j + 2) or (first_match and isMatch(s, p, i + 1, j))
  else:
    return first_match and isMatch(s, p, i + 1, j + 1)
```

#### ⚙️ Complexities
| Time Complexity | $O(2^{m+n})$ — where m and n are the lengths of the string and pattern. The recursive tree can branch into two paths at each `*` character, leading to exponential complexity. |
| :--- | :--- |
| **Space Complexity** | **$O(m+n)$** — due to the maximum depth of the recursion stack. |
***
### 🤔 Approach 2: Top-Down DP (Memoization)
**Idea**
`
- Optimize the recursive approach by caching results.
- Use a memoization table (e.g., a 2D array) to store the outcomes of `isMatch(i, j)`.
- Before computing a state, check if its result already exists in the table to avoid redundant work.

**Advantage**

- Drastically improves performance by eliminating repeated computations.
- Maintains the readable, top-down structure of the recursive solution.

#### 💻 Generic Logic (Pseudocode)
```
memo = new table
function isMatchMemo(s, p, i, j):
  if (i, j) in memo:
    return memo[(i, j)]

  // ... (rest of the logic is the same as the recursive approach) ...
  // For example:
  if j == length(p):
    return i == length(s)

  // ... calculate result ...

  memo[(i, j)] = result
  return result
```

#### ⚙️ Complexities
| Time Complexity | $O(m \times n)$ — Each state `(i, j)` is computed only once. |
| :--- | :--- |
| **Space Complexity** | **$O(m \times n)$** — For the memoization table, plus $O(m+n)$ for the recursion stack. |
***
### 🤔 Approach 3: Bottom-Up DP (Tabulation)
**Idea**

- Build the solution iteratively from the ground up.
- Use a 2D DP table where `dp[i][j]` represents whether `s[:i]` matches `p[:j]`.
- Fill the table by calculating each state `dp[i][j]` based on previously computed states.

**Advantage**

- Avoids recursion, preventing potential stack overflow errors on large inputs.
- Typically has slightly better performance than memoization due to no recursion overhead.

#### 💻 Generic Logic (Pseudocode)
```
function isMatchDP(s, p):
  m = length(s), n = length(p)
  dp = new table(m+1, n+1) initialized to false
  dp[0][0] = true

  // Handle patterns like a*, a*b*, etc., for an empty string
  for j from 1 to n:
    if p[j-1] == '*':
      dp[0][j] = dp[0][j-2]

  for i from 1 to m:
    for j from 1 to n:
      if p[j-1] == '.' or p[j-1] == s[i-1]:
        dp[i][j] = dp[i-1][j-1]
      else if p[j-1] == '*':
        dp[i][j] = dp[i][j-2] // Zero occurrences
        if p[j-2] == '.' or p[j-2] == s[i-1]:
          dp[i][j] = dp[i][j] or dp[i-1][j] // One or more occurrences
      else:
        dp[i][j] = false

  return dp[m][n]
```
#### ⚙️ Complexities
| Time Complexity | $O(m \times n)$ — We iterate through the entire DP table once. |
| :--- | :--- |
| **Space Complexity** | **$O(m \times n)$** — To store the DP table. |
***
### 🤔 Approach 4: Space Optimized DP
**Idea**

- Optimize the space usage of the tabulation approach.
- Recognize that computing the current row of the DP table only requires the previous row.
- Use two 1D arrays (or even one) to store only the necessary states, instead of the full 2D table.

**Advantage**

- Provides the most memory-efficient solution.
-  Crucial for problems with very large input strings where an `O(m * n)` table would be too big

#### ⚙️ Complexities
| Time Complexity | $O(m \times n)$ — The number of computations remains the same as the tabulation method. |
| :--- | :--- |
| **Space Complexity** | **$O(n)$** — We only need two arrays of size `n+1` to store the DP states for the previous and `current rows. |
