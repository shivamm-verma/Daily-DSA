# KMP String Pattern Matching Algorithm

## 📝 Problem Statement

Implement the Knuth-Morris-Pratt (KMP) algorithm to efficiently find all occurrences of a pattern in a text string using linear time complexity O(n+m), where n is the length of text and m is the length of pattern.

**Difficulty Level:** Hard/Optimized 

## 🔍 Algorithm Overview

The KMP algorithm is an efficient string-searching algorithm that searches for occurrences of a "pattern" within a main "text" string by employing the observation that when a mismatch occurs, the pattern itself embodies sufficient information to determine where the next match could begin.

### Key Innovation
- **Failure Function (LPS Array)**: Preprocesses the pattern to create a "Longest Proper Prefix which is also Suffix" array
- **No Backtracking**: Never moves the text pointer backward
- **Linear Time**: Achieves O(n+m) complexity instead of naive O(n×m)

## 🧠 Core Concepts

### 1. LPS Array (Longest Proper Prefix which is also Suffix)
- For each position i in pattern, LPS[i] stores the length of the longest proper prefix of pattern[0...i] which is also a suffix of pattern[0...i]
- A proper prefix is a prefix that is not equal to the string itself
- Used to skip characters during pattern matching when a mismatch occurs

### 2. Pattern Matching Process
- Compare characters from left to right
- On mismatch, use LPS array to determine how many characters can be skipped
- Continue until entire text is processed

## 🚀 Algorithm Steps

### Step 1: Build LPS Array
```
function computeLPS(pattern):
    lps = array of size m filled with 0
    len = 0, i = 1
    
    while i < m:
        if pattern[i] == pattern[len]:
            len++, lps[i] = len, i++
        else:
            if len != 0: len = lps[len-1]
            else: lps[i] = 0, i++
    
    return lps
```

### Step 2: Search Pattern
```
function KMPSearch(text, pattern):
    lps = computeLPS(pattern)
    i = 0, j = 0  // i for text, j for pattern
    
    while i < n:
        if pattern[j] == text[i]:
            i++, j++
        
        if j == m:
            // Found match at index (i-j)
            j = lps[j-1]
        elif i < n and pattern[j] != text[i]:
            if j != 0: j = lps[j-1]
            else: i++
```

## 📊 Complexity Analysis

| Operation               | Time Complexity | Space Complexity |
|-------------------------|-----------------|------------------|
| **Preprocessing (LPS)** | O(m)            | O(m)             |
| **Pattern Searching**   | O(n)            | O(1)             |
| **Overall**             | **O(n + m)**    | **O(m)**         |

Where:
- n = length of text
- m = length of pattern

## 💡 Example Walkthrough

### Pattern: "ABABCABCABCABC"

**Step 1: Build LPS Array**
```
Pattern: A B A B C A B C A B C A B C
Index:   0 1 2 3 4 5 6 7 8 9 10 11 12 13
LPS:     0 0 1 2 0 1 2 0 1 2 0 1 2 0
```

**Explanation of LPS values:**
- Index 0: A → LPS[0] = 0 (no proper prefix)
- Index 1: AB → LPS[1] = 0 (no matching prefix-suffix)
- Index 2: ABA → LPS[2] = 1 (prefix "A" matches suffix "A")
- Index 3: ABAB → LPS[3] = 2 (prefix "AB" matches suffix "AB")
- Index 4: ABABC → LPS[4] = 0 (no matching prefix-suffix)

**Step 2: Pattern Matching**
```
Text:    A B A B D A B A C D A B A B C A B C A B C A B C A B C
Pattern: A B A B C A B C A B C A B C
         ↑ ↑ ↑ ↑ ✗              
         0 1 2 3 4 (mismatch at index 4)
         
Use LPS[3] = 2, so j becomes 2:
Text:    A B A B D A B A C D A B A B C A B C A B C A B C A B C
Pattern:     A B A B C A B C A B C A B C
             ↑ ↑ ✗
             2 3 4 (mismatch again)
```

## 🎯 Advantages of KMP

1. **Linear Time Complexity**: O(n+m) vs O(n×m) for naive approach
2. **No Backtracking**: Text pointer never goes backward
3. **Optimal for Large Texts**: Efficient for searching in large documents
4. **Reusable Preprocessing**: LPS array can be reused for multiple searches
5. **Handles Overlapping**: Finds all occurrences including overlapping ones

## 🧪 Test Cases

### Test Case 1: Basic Pattern Matching
```
Text: "ABABDABACDABABCABCABCABCABC"
Pattern: "ABABCABCABCABC"
Expected: [13] (pattern found at index 13)
```

### Test Case 2: Multiple Occurrences
```
Text: "AABAACAADAABAABA"
Pattern: "AABA"
Expected: [0, 9, 12] (multiple matches)
```

### Test Case 3: Overlapping Patterns
```
Text: "AAAAAAA"
Pattern: "AAA"
Expected: [0, 1, 2, 3, 4] (overlapping matches)
```

### Test Case 4: No Match
```
Text: "ABCDEFGH"
Pattern: "XYZ"
Expected: [] (no matches found)
```

## 🔄 Comparison with Other Algorithms

| Algorithm             | Time Complexity | Space Complexity      | Notes                    |
|-----------------------|-----------------|---------------------- |--------------------------|
| **Naive/Brute Force** | O(n×m)          | O(1)                  | Simple but inefficient   |
| **KMP**               | **O(n+m)**      | **O(m)**              | Optimal for most cases   |   
| **Boyer-Moore**       | O(n+m) to O(n×m)| O(σ+m)*               | Good for large alphabets |
| **Rabin-Karp**        | O(n+m) average  | O(1)                  | Uses hashing             |

*σ = size of character set

## 🏗️ Implementation Files

- **`kmp_algorithm.cpp`** - C++ implementation with comprehensive testing
- **`kmp_algorithm.py`** - Python implementation with performance analysis
- **`KMPAlgorithm.java`** - Java implementation with detailed documentation
- **`kmp_algorithm.c`** - C implementation with step-by-step explanation and sample test cases

## 🎲 How to Run

### C++
```bash
g++ -o kmp_algorithm kmp_algorithm.cpp
./kmp_algorithm
```

### Python
```bash
python kmp_algorithm.py
```

### Java
```bash
javac KMPAlgorithm.java
java KMPAlgorithm
```
### C
```bash
gcc -o kmp_algorithm kmp_algorithm.c
./kmp_algorithm


## 🌍 Real-World Applications

1. **Text Editors**: Find and replace functionality
2. **Bioinformatics**: DNA sequence matching
3. **Network Security**: Intrusion detection systems
4. **Data Compression**: Pattern recognition in compression algorithms
5. **Plagiarism Detection**: Document comparison
6. **Search Engines**: Efficient text searching
7. **Log Analysis**: Pattern matching in system logs

## 🎯 Edge Cases Handled

- ✅ Empty pattern
- ✅ Pattern longer than text
- ✅ Pattern not present in text
- ✅ Single character patterns
- ✅ Repeated characters
- ✅ Overlapping matches
- ✅ Pattern equals text
- ✅ Special characters and spaces

## 📈 Performance Insights

For a text of length 10,000 and pattern of length 100:
- **Naive Algorithm**: ~1,000,000 character comparisons
- **KMP Algorithm**: ~10,100 character comparisons (100x faster!)

## 🎓 Learning Resources

1. **Time Complexity Analysis**: Understanding why KMP is O(n+m)
2. **LPS Array Construction**: The key to KMP's efficiency
3. **Pattern Preprocessing**: One-time cost for multiple benefits
4. **Failure Function**: How mismatches guide the next comparison

## 🤝 Contributing

This implementation is part of the Daily-DSA repository. Contributions are welcome!

**Author**: Khushi Patel
**Difficulty**: Hard/Optimized
**Date**: 04/09/2025

---

## 🔗 References

- Knuth, Donald; Morris, James H.; Pratt, Vaughan (1977). "Fast pattern matching in strings"
- Introduction to Algorithms (CLRS) - Chapter 32
- Art of Computer Programming, Volume 3 - Donald Knuth