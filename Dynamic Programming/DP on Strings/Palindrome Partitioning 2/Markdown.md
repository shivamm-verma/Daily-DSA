# Problem — Palindrome Partitioning II

## Problem Statement
Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**.  
Return the **minimum number of cuts** needed to partition `s` in this way.  


## Key Insights & Approach

1. **Dynamic Programming over string indices**
   - Let `DP[i]` = minimum number of cuts needed for substring `s[0..i]`.  
   - Transition: for each `j < i`, if `s[j+1..i]` is a palindrome,  
     `DP[i] = min(DP[i], DP[j] + 1)`.  
   - If `s[0..i]` itself is a palindrome → `DP[i] = 0`.

2. **Palindrome checking optimization**
   - Precompute a **2D boolean table** `isPalindrome[i][j]` to check if `s[i..j]` is palindrome in O(1).  
   - `isPalindrome[i][j] = true` if `s[i] == s[j]` and (`j - i <= 2` or `isPalindrome[i+1][j-1] == true`).

3. **Final answer**
   - `DP[n-1]` gives the **minimum number of cuts** for the entire string `s`.



## Example Cases

| Example | Input      | Output |               Explanation                      |
|-------- |------------|--------|------------------------------------------------|
| 1       | `"aab"`    | `1`    | Partition: `"aa" | "b"`                        |
| 2       | `"a"`      | `0`    | Single character is palindrome → no cut needed |
| 3       | `"abccba"` | `0`    | The whole string is palindrome → no cut needed |
| 4       | `"abbab"`  | `1`    | Partition: `"abba" | "b"`                      |

---

##  Time & Space Complexity

| Metric    | Complexity |                        Reasoning                                   |
|-----------|------------|--------------------------------------------------------------------|
| **Time**  |  O(n²)     | Precompute palindrome table O(n²) + DP over n with inner loop O(n) |
| **Space** | O(n²)      | 2D table for palindrome check + 1D DP array                        |

---


### Notes

- This problem is a **classic string DP / interval DP** problem.  
- Precomputing the palindrome table allows for O(1) palindrome checks inside the DP transition.  
- Keep the solution **atomic** and modular if you plan to use in multiple related problems.
