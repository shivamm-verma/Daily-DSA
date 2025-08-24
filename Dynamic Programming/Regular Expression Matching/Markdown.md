🧭 Regular Expression Matching — Approaches Explained
📘 Problem Statement
You are given an input string s and a pattern p. Your task is to implement regular expression matching with support for two special characters:

. (dot): Matches any single character.

* (asterisk): Matches zero or more of the preceding element.

The matching must cover the entire input string, not just a part of it.

🧪 Example
Input:

s = "aab", p = "cab"

Output:

true

Explanation:

c* matches zero instances of 'c'.

a* matches two instances of 'a'.

The pattern effectively matches "aab".

--------------------------------------------------------------------------------------------------------


1️⃣ Brute Force Recursive Approach
💡 Idea
Define a function solve(i, j) that checks if s from index i onwards matches p from index j onwards.

If the next pattern character p[j+1] is *:

Path 1 (Zero Matches): Ignore p[j] and p[j+1] and check solve(i, j+2).

Path 2 (One or More Matches): If s[i] matches p[j], check solve(i+1, j).

If there's no *, and s[i] matches p[j], check solve(i+1, j+1).

⚙️ Complexity
Time: O(2^(m+n))
Space: O(m + n) (Recursion Stack)

----------------------------------------------------------------------------------------------------

2️⃣ Top-Down DP (Memoization)
💡 Idea
The recursive approach re-computes the same states (i, j) multiple times.

We can optimize by storing the result of each solve(i, j) call in a 2D memoization table, dp[i][j].

Before computing, check if dp[i][j] has a stored value. If so, return it directly. This avoids redundant work.

⚙️ Complexity
Time: O(m × n)
Space: O(m × n) (Memo Table) + O(m + n) (Stack Space)

------------------------------------------------------------------------------------------------------

3️⃣ Bottom-Up DP (Tabulation)
💡 Idea
Use a 2D DP table where dp[i][j] is true if the first i characters of s match the first j characters of p.

The state transition depends on the character p[j-1]:

If p[j-1] is *:
dp[i][j] = dp[i][j-2] (zero occurrences) ||
(match(s[i-1], p[j-2]) && dp[i-1][j]) (one or more occurrences)

Else:
dp[i][j] = match(s[i-1], p[j-1]) && dp[i-1][j-1]

⚙️ Complexity
Time: O(m × n)
Space: O(m × n)

---------------------------------------------------------------------------------------------------------

4️⃣ Space Optimized DP (1D Array)
💡 Idea
To compute the values for the current row i in the DP table, we only need the values from the previous row i-1.

This allows us to reduce the space from a 2D table to two 1D arrays (previous_row and current_row).

⚙️ Complexity
Time: O(m × n)
Space: O(n)

---------------------------------------------------------------------------------------------------------

🔚 Conclusion
Recursive → Simple to write but very slow due to repeated work.

Memoization → A direct top-down optimization that makes recursion viable.

Tabulation → A bottom-up iterative approach that eliminates recursion overhead.

Space Optimization → The most efficient DP solution for memory usage.


