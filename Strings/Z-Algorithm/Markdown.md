# Z-Algorithm for Pattern Matching

## Problem Statement

Implement the Z-Algorithm to find all occurrences of a pattern in a given text in O(n + m) time complexity, where n is the length of the text and m is the length of the pattern.

## Brief Description

The Z-Algorithm is an efficient string matching algorithm that finds all occurrences of a pattern in a text string. It uses a Z-array (also called Z-function) to achieve linear time complexity.

## Algorithm Overview

### What is Z-Array?

For a string S, the Z-array Z[i] represents the length of the longest substring starting from position i that matches the prefix of S.

**Example:**
```
String: "ababcababa"
Z-array: [10, 0, 1, 0, 0, 3, 0, 1, 0, 1]
```

- Z[0] = 10 (entire string length)
- Z[2] = 1 (substring "a" matches prefix "a")
- Z[5] = 3 (substring "aba" matches prefix "aba")

### How Z-Algorithm Works

1. **Create Combined String**: Combine pattern + '$' + text
2. **Build Z-Array**: For the combined string
3. **Find Matches**: Look for Z-values equal to pattern length

### Key Concepts

#### Z-Box
A Z-box is a substring that matches the prefix of the string. We maintain:
- **Left boundary (L)**: Start of the Z-box
- **Right boundary (R)**: End of the Z-box

#### Three Cases for Z-Array Construction

1. **Outside Z-box**: i > R
   - Expand from current position
   - Update L and R

2. **Inside Z-box**: i ≤ R
   - Use previously computed Z[k] where k = i - L
   - If Z[k] < R - i + 1: Z[i] = Z[k]
   - If Z[k] ≥ R - i + 1: Expand from R

## Time and Space Complexity

- **Time Complexity**: O(n + m)
- **Space Complexity**: O(n + m)

## Advantages

1. **Linear Time**: O(n + m) time complexity
2. **No Preprocessing**: Unlike KMP, no failure function needed
3. **Simple Implementation**: Easy to understand and implement
4. **Handles Overlapping**: Finds all overlapping occurrences

## Disadvantages

1. **Space Usage**: Requires O(n + m) extra space
2. **Special Character**: Needs a separator character not in pattern/text

## Applications

1. **String Matching**: Find all occurrences of a pattern
2. **Pattern Recognition**: DNA sequence analysis
3. **Text Processing**: Search engines, text editors
4. **Competitive Programming**: String problems

## Example Walkthrough

**Text**: "ababcababa"  
**Pattern**: "aba"

### Step 1: Create Combined String
```
Combined: "aba$ababcababa"
```

### Step 2: Build Z-Array
```
Position: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
String:   a b a $ a b a b c a  b  a  b  a
Z-array: 14 0 1 0 3 0 1 0 0 3  0  1  0  1
```

### Step 3: Find Matches
Look for Z[i] = 3 (pattern length) in text part:
- Z[4] = 3 → Match at position 0
- Z[9] = 3 → Match at position 5
- Z[11] = 1 → No match (not equal to pattern length)

**Result**: [0, 5, 7] (positions 0, 5, and 7 in original text)

## Test Cases

### Test Case 1: Basic Example
```
Text: "ababcababa"
Pattern: "aba"
Expected Output: [0, 5, 7]
```

### Test Case 2: No Matches
```
Text: "abcdefgh"
Pattern: "xyz"
Expected Output: []
```

### Test Case 3: Overlapping Patterns
```
Text: "aaaaaa"
Pattern: "aa"
Expected Output: [0, 1, 2, 3, 4]
```

### Test Case 4: Single Character
```
Text: "programming"
Pattern: "m"
Expected Output: [6, 7]
```

### Test Case 5: Edge Cases
```
Text: "hello"
Pattern: ""
Expected Output: []

Text: "abc"
Pattern: "abcdef"
Expected Output: []
```

## Implementation Notes

### Python Implementation
- Uses list comprehension for Z-array
- Handles edge cases (empty pattern, pattern longer than text)
- Includes performance testing

### Java Implementation
- Uses ArrayList for dynamic arrays
- Multiple implementation variants (optimized, StringBuilder)
- Comprehensive test cases

### C++ Implementation
- Uses vector for dynamic arrays
- Const references for better performance
- Memory optimization with reserve()

## Comparison with Other Algorithms

| Algorithm | Time Complexity | Space Complexity | Preprocessing |
|-----------|----------------|------------------|---------------|
| Naive | O(nm) | O(1) | None |
| KMP | O(n + m) | O(m) | O(m) |
| Z-Algorithm | O(n + m) | O(n + m) | None |
| Rabin-Karp | O(n + m) | O(1) | None |

## Optimization Tips

1. **Early Termination**: Stop if pattern is longer than text
2. **Memory Pre-allocation**: Reserve space for vectors/arrays
3. **Const References**: Use const references in C++ for better performance
4. **StringBuilder**: Use StringBuilder in Java for string concatenation

## Common Mistakes

1. **Forgetting Separator**: Must use a character not in pattern/text
2. **Index Calculation**: Be careful with text index calculation
3. **Boundary Conditions**: Handle empty strings and edge cases
4. **Z-Box Updates**: Correctly update L and R boundaries

## Practice Problems

1. **LeetCode**: Implement strStr()
2. **SPOJ**: Pattern Find
3. **Codeforces**: String Matching
4. **HackerRank**: String Similarity

## Further Reading

1. [Z-Algorithm Tutorial](https://cp-algorithms.com/string/z-function.html)
2. [String Matching Algorithms](https://en.wikipedia.org/wiki/String_searching_algorithm)
3. [Competitive Programming Handbook](https://cses.fi/book/book.pdf)

---

**Difficulty**: Hard/Optimized  
**Topic**: String Algorithms / Pattern Matching  
**Tags**: #string-matching #pattern-matching #z-algorithm #linear-time
