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
1.  Define a recursive function, let's say `isMatch(text_index, pattern_index)`, to check if the substring of `s` from `text_index` and the sub-pattern of `p` from `pattern_index` match.
2.  **Handle the `*` character**: If the next character in the pattern is `*`, we have two choices:
    - Ignore this part of the pattern (`*` matches zero elements) and move two steps forward in the pattern: `isMatch(text_index, pattern_index + 2)`.
    - If the current characters match, use the `*` to match one character in the text and stay at the same pattern position: `isMatch(text_index + 1, pattern_index)`.
3.  **Handle a normal match**: If the next character is not `*`, the current characters in the string and pattern must match, and we advance both by one: `isMatch(text_index + 1, pattern_index + 1)`.
4.  The base case for the recursion is when the pattern is exhausted. The match is successful only if the text is also fully exhausted.

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
1.  The recursive approach is slow because it re-computes the same states (i.e., the same `i` and `j` values) multiple times.
2.  We can optimize this by storing the result of each state `(i, j)` in a 2D memoization table, `memo[i][j]`.
3.  Before computing `isMatch(i, j)`, we first check if the result is already stored in `memo[i][j]`. If it is, we return it directly, avoiding redundant computations.

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
1.  Create a 2D DP table, `dp[m+1][n+1]`, where `dp[i][j]` is `true` if the first `i` characters of `s` match the first `j` characters of `p`.
2.  Initialize `dp[0][0] = true` (empty string matches empty pattern). Also, handle cases where a pattern like `a*b*c*` can match an empty string.
3.  Iterate through the `s` and `p`, filling the table based on the following rules for `dp[i][j]`:
    - If `p[j-1]` is a normal character or `.`: `dp[i][j]` is true only if `s[i-1]` matches `p[j-1]` AND `dp[i-1][j-1]` was true.
    - If `p[j-1]` is `*`:
      - It can match zero elements, so we check `dp[i][j-2]`.
      - If the preceding character `p[j-2]` matches `s[i-1]`, it can also match one or more elements, so we check `dp[i-1][j]`.

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
1.  Observe that to compute the current row `dp[i]`, we only need the values from the previous row `dp[i-1]`.
2.  This allows us to optimize the space complexity by using only two 1D arrays (`previous_row` and `current_row`), each of size `n+1`, instead of a full 2D table.
3.  In each outer loop iteration (for each character in `s`), we calculate `current_row` using the values from `previous_row`. At the end of the loop, `previous_row` is updated to `current_row`.

#### ⚙️ Complexities
| Time Complexity | $O(m \times n)$ — The number of computations remains the same as the tabulation method. |
| :--- | :--- |
| **Space Complexity** | **$O(n)$** — We only need two arrays of size `n+1` to store the DP states for the previous and current rows. |
