# Damerau-Levenshtein Algorithm Showcase  

## Introduction to Damerau-Levenshtein Distance  

The **Damerau-Levenshtein distance** is a measure of similarity between two strings, defined as the minimum number of **insertions**, **deletions**, **substitutions**, and **transpositions** required to transform one string into the other. It extends the classic Levenshtein distance by adding the transposition operation, making it particularly effective for detecting common human typing errors.

### Allowed Operations  
- **Insertion**: Adding a character to string A  
- **Deletion**: Removing a character from string A  
- **Replacement**: Replacing a character in string A with another character  
- **Transposition**: Swapping two adjacent characters in string A  

### Example  

Transform `"kitten"` into `"sitting"` (all operations cost 1):  

1. `kitten → sitten` (substitute `"s"` for `"k"`)  
2. `sitten → sittin` (substitute `"i"` for `"e"`)  
3. `sittin → sitting` (insert `"g"` at the end)  

**Damerau-Levenshtein distance = 3**  

**Transposition Example:**  

Transform `"martha"` into `"marhta"`:  

1. `martha → marhta` (transpose `"th"` to `"ht"`)  

**Damerau-Levenshtein distance = 1** (Levenshtein distance = 2)  

### Research Foundation

According to Damerau's research, more than **80% of spelling errors** fall into one of these four operation categories, with transposition being a particularly frequent mistake.

### Bounds  
- **Lower bound**: `0` (identical strings)  
- **Upper bound**: `max(m, n)` for strings of length `m` and `n`  

### Applications  
- **Spell checkers** – Accurate correction suggestions (e.g., Microsoft Word, Google Docs)  
- **Autocorrect algorithms** – Enhanced text prediction and correction  
- **Data deduplication** – Identify similar records with transposition errors  
- **DNA sequence analysis** – Detect genetic mutations and variations  
- **Natural language processing** – Improved text similarity matching  

### Algorithm Variants
- **Optimal String Alignment (OSA)** – Simple, restricted (no substring edited more than once)  
- **True Damerau-Levenshtein** – Unrestricted adjacent transpositions, maintains metric properties  

### Relationship with Other Edit Distances  
- **Levenshtein distance**: Subset without transposition  
- **Hamming distance**: Only for equal-length strings, counts differing positions  
- **Jaro-Winkler distance**: Focus on transpositions and prefix matching  

---

## Project Overview  

Implements **Damerau-Levenshtein Algorithm** in **two approaches** across **three languages** for comparison.

### Approaches  
1. **Better Solution** – DP with full DP matrix  
2. **Optimal Solution** – Space-optimized DP  

### Languages  
1. **C++**  
2. **Java**  
3. **Python**  

---

## Brute Force Approach  

**Recursive Implementation:**  

- **Function 1**: Minimum edit distance only  
  - Time Complexity: `O(4^N)`  
  - Space Complexity: `O(N)`  

- **Function 2**: Minimum edit distance + operation sequence  
  - Time Complexity: `O(4^N)`  
  - Space Complexity: `O(N^2)`  

**Details:**  
- Detects transposition when `str1[i] == str2[j+1]` and `str1[i+1] == str2[j]`  
- Advances indices by 2 if transposition applied  
- Compares four operations to find minimum  

---

## Better Approach – Minimum Weighted Edit Distance (DP Matrix)  

**Dynamic Programming Implementation:**  

- **Function 1**: Minimum edit distance  
  - Time Complexity: `O(M*N)`  
  - Space Complexity: `O(M*N)`  

- **Function 2**: Minimum edit distance + operations  
  - Time Complexity: `O(M*N)`  
  - Space Complexity: `O(M*N)`  

**Enhanced DP Matrix:**  
- Tracks character positions for transpositions  
- Checks diagonals two steps back for transposition  
- Supports both OSA and unrestricted variants  

---

## Optimal Approach – Space Optimization  

**DP Vector Implementation:**  
- Maintains three vectors (`prev_prev`, `prev`, `curr`) for transposition support  
- Time Complexity: `O(M*N)`  
- Space Complexity: `O(3*min(M,N))`  
- Returns minimum edit distance with detailed operation logging  

**Features:**  
- Automatic string swapping for optimal space  
- Transposition detection with three-vector approach  
- Step-by-step logging and detailed cost tracking  
- Custom operation costs supported  

**Transposition Handling:**  
- Uses `prev_prev[i-2]` for transposition cost  
- Vector shifting: `prev_prev ← prev ← curr`  

---

## Advanced Features  

### Custom Operation Costs
- Configurable for insert, delete, replace, transpose  
- Uniform or individual cost modes  

### Operation Tracking
- Full transformation sequence  
- Cost breakdown per operation  
- Visual step-by-step logging  

### Multi-Language Support
- Consistent API across C++, Java, Python  
- Feature parity and language-specific optimizations  
- Space-efficient implementation  

---

The **brute force approach** resides in the **recursion folder**, providing a foundational recursive implementation for full Damerau-Levenshtein distance.
