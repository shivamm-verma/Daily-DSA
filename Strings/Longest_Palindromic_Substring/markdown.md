# Longest Palindromic Substring — Approaches Explained

## Problem Statement
Given a string `s`, return the **longest palindromic substring** in `s`. A palindrome is a string that reads the same forward and backward.

## 📘 Example

#### Input
```text
s = "babad"
Output: "bab" (or "aba")
```

#### Visual Explanation
```text
String: b a b a d
        ↑   ↑   
       "bab" is palindrome (length 3)
       
String: b a b a d
          ↑ ↑ ↑
         "aba" is palindrome (length 3)
```

#### More Examples
```text
Input: s = "cbbd"
Output: "bb"

Input: s = "racecar" 
Output: "racecar"
```

---

## 1️⃣ Brute Force Approach

### Idea
- Generate all possible substrings of the input string
- Check each substring to see if it's a palindrome
- Keep track of the longest palindrome found

### Why Brute Force?
- Checks every possible substring (n² substrings)
- For each substring, performs palindrome check (O(n) operation)
- No optimization or early termination
- Doesn't leverage any string properties

### Algorithm Steps
1. Use nested loops to generate all substrings
2. For each substring, check if it's a palindrome by comparing characters from both ends
3. Update the longest palindrome if current substring is longer

### Complexity
- **Time**: O(n³) - O(n²) substrings × O(n) palindrome check
- **Space**: O(1) - Only storing result string

---

## 2️⃣ Better Approach (Expand Around Centers)

### Idea
- For each possible center in the string, expand outward while characters match
- Handle both odd-length palindromes (single center) and even-length palindromes (center between two characters)
- Keep track of the longest palindrome found during expansion

### Advantage
- **Eliminates redundant checks**: Instead of checking all substrings, only expands promising centers
- **Leverages palindrome property**: Uses the fact that palindromes are symmetric around their center
- **Early termination**: Stops expanding when characters don't match
- **Handles both cases**: Efficiently manages odd and even length palindromes

### Algorithm Steps
1. For each position `i` in the string:
   - Expand around center `i` (odd-length palindromes)
   - Expand around centers `i` and `i+1` (even-length palindromes)
2. For each expansion, continue while characters match
3. Update longest palindrome if current expansion is longer

### Complexity
- **Time**: O(n²) - O(n) centers × O(n) expansion per center
- **Space**: O(1) - Only storing result string

---

## 3️⃣ Optimal Approach (Manacher's Algorithm)

### Idea
- Transform the string to handle odd/even cases uniformly
- Use previously computed palindrome information to avoid redundant expansions
- Maintain the rightmost palindrome boundary and use symmetry property
- Achieve linear time complexity through clever optimizations

### Why Optimal?
- **Avoids redundant work**: Uses mirror property to skip known palindrome checks
- **Linear time complexity**: Each character is processed at most twice
- **Uniform handling**: Transforms string to treat odd/even palindromes consistently
- **Advanced technique**: Represents the theoretical optimal solution

### Algorithm Steps
1. **Transform string**: Insert separators (e.g., "abc" → "^#a#b#c#$")
2. **Initialize arrays**: Track palindrome radius for each position
3. **Process each position**:
   - Use mirror property if within known palindrome boundary
   - Expand around center to find actual palindrome length
   - Update rightmost boundary if current palindrome extends further
4. **Find maximum**: Identify the longest palindrome from computed radii

### Key Concepts
- **P[i]**: Radius of palindrome centered at position i
- **Center & Right**: Track center and right boundary of rightmost palindrome
- **Mirror property**: P[i] ≥ min(P[mirror], right - i) when i < right

### Complexity
- **Time**: O(n) - Each position expanded at most once
- **Space**: O(n) - Additional arrays for transformation and palindrome radii

---

## 📊 Comparison Summary

| Approach | Time Complexity | Space Complexity | Pros | Cons |
|----------|----------------|------------------|------|------|
| **Brute Force** | O(n³) | O(1) | Simple logic, easy to understand | Highly inefficient for large inputs |
| **Expand Around Centers** | O(n²) | O(1) | Good balance of efficiency and simplicity | Still quadratic time complexity |
| **Manacher's Algorithm** | O(n) | O(n) | Optimal time complexity, finds all palindromes | Complex implementation, harder to debug |

---

## 🎯 When to Use Each Approach

| Scenario | Recommended Approach | Reason |
|----------|---------------------|---------|
| **Small inputs (n < 100)** | Brute Force | Simplicity outweighs performance concerns |
| **General purpose solution** | Expand Around Centers | Best balance of performance and readability |
| **Large inputs (n > 1000)** | Manacher's Algorithm | Linear time complexity essential |
| **Interview settings** | Expand Around Centers | Demonstrates good algorithmic thinking |
| **Performance critical applications** | Manacher's Algorithm | Optimal theoretical complexity |

---

## 🔍 Key Insights

### Pattern Recognition
- **Brute Force**: When unsure, generate all possibilities
- **Expand Around Centers**: Leverage problem structure (palindrome symmetry)
- **Manacher's**: Use mathematical properties to eliminate redundancy

### Optimization Journey
1. **Identify bottlenecks**: Brute force has expensive palindrome checks
2. **Exploit structure**: Palindromes have center symmetry
3. **Eliminate redundancy**: Previously computed information helps future calculations
4. **Transform problem**: Sometimes changing representation simplifies solution

---

## 🧪 Test Cases Coverage

All implementations handle:
- **Single character**: `"a"` → `"a"`
- **Two characters same**: `"aa"` → `"aa"`  
- **Two characters different**: `"ab"` → `"a"` (or `"b"`)
- **Entire string palindrome**: `"racecar"` → `"racecar"`
- **No palindromes > 1**: `"abcdef"` → `"a"`
- **Multiple same length**: `"babad"` → `"bab"` or `"aba"`
- **Empty string**: `""` → `""` (edge case)