# Damerau-Levenshtein Algorithm Showcase  

## Introduction to Damerau-Levenshtein Distance  

The **Damerau-Levenshtein distance** is a measure of similarity between two strings, defined as the minimum number of **insertions**, **deletions**, **substitutions**, and **transpositions** required to transform one string into the other. It extends the classic Levenshtein distance by adding the transposition operation, making it particularly effective for detecting common human typing errors.

### Allowed Operations  
- **Insertion**: Adding a character to string A.  
- **Deletion**: Removing a character from string A.  
- **Replacement**: Replacing a character in string A with another character.  
- **Transposition**: Swapping two adjacent characters in string A.

### Example  

Transform `"kitten"` into `"sitting"` (considering all operations cost 1):  

1. `kitten → sitten` (substitute `"s"` for `"k"`)  
2. `sitten → sittin` (substitute `"i"` for `"e"`)  
3. `sittin → sitting` (insert `"g"` at the end)  

**Damerau-Levenshtein distance = 3**.

**Transposition Example:**  

Transform `"martha"` into `"marhta"`:  

1. `martha → marhta` (transpose `"th"` to `"ht"`)  

**Damerau-Levenshtein distance = 1** (compared to Levenshtein distance = 2).

### Research Foundation

According to Damerau's research, more than **80% of spelling errors** fall into one of these four operation categories, with transposition being a particularly frequent mistake in human typing.

### Bounds  
- **Lower bound**: `0` (when both strings are identical)  
- **Upper bound**: `max(m, n)` for strings of length `m` and `n`  

### Applications  
- **Spell checkers** – More accurate correction suggestions (e.g., Microsoft Word, Google Docs)  
- **Autocorrect algorithms** – Enhanced text prediction and correction  
- **Data deduplication** – Better identification of similar records with transposition errors  
- **DNA sequence analysis** – Detecting genetic mutations and variations  
- **Natural language processing** – Improved text similarity matching  

### Algorithm Variants
The Damerau-Levenshtein distance has two main implementations:  

1. **Optimal String Alignment (OSA)** – Simpler implementation with restrictions (no substring can be edited more than once)  
2. **True Damerau-Levenshtein** – Allows unrestricted adjacent transpositions and maintains metric properties  

### Relationship with Other Edit Distances  
- **Levenshtein distance**: Subset of Damerau-Levenshtein without transposition operation  
- **Hamming distance**: Works only on equal-length strings, counts differing positions  
- **Jaro-Winkler distance**: Focuses on character transpositions and prefix matching  

---

## Project Overview  

This project implements the **Damerau-Levenshtein Algorithm** using **recursive approaches**, developed in **three programming languages** for versatility and comparison.  

### Approaches  
1. **Brute Force** – Simple recursive solution with four operations  

### Languages  
1. **C++**  
2. **Java**  
3. **Python**  

---

## Brute Force Approach  

**Recursive Implementation:**  

- **Function 1**: Returns only the minimum edit distance  
  - **Time Complexity**: `O(4^N)` (four recursive calls per position)  
  - **Space Complexity**: `O(N)` (stack space)  

- **Function 2**: Returns both minimum edit distance and the sequence of operations  
  - **Time Complexity**: `O(4^N)`  
  - **Space Complexity**: `O(N^2)` (stack + operation vector)  

**Key Implementation Details:**  
- Checks for transposition when `str1[i] == str2[j+1]` and `str1[i+1] == str2[j]`  
- Advances indices by 2 positions when transposition is applied  
- Compares four operation costs to find minimum  

---

## Better Approach – Minimum Weighted Edit Distance (DP Matrix)  

**Dynamic Programming Implementation:**  

- **Function 1**: Returns only the minimum edit distance  
  - **Time Complexity**: `O(M*N)` with additional transposition checks  
  - **Space Complexity**: `O(M*N)` (DP matrix)  

- **Function 2**: Returns minimum edit distance + operations performed  
  - **Time Complexity**: `O(M*N)`  
  - **Space Complexity**: `O(M*N)` (DP matrix + operation vector)  

**Enhanced DP Matrix:**  
- Requires tracking of character positions for transposition detection  
- May need additional space for character frequency or position mapping  
- Handles both OSA and unrestricted Damerau-Levenshtein variants  

---

## Optimal Approach – Space Optimization  

**DP Vector Implementation:**  
- Maintains minimal space while handling transposition operations  
- **Time Complexity**: `O(M*N)` (nested loops with transposition checks)  
- **Space Complexity**: `O(min(M,N))` (optimized vectors plus character tracking)  
- Function returns minimum edit distance with efficient space utilization  

**Space Optimization Challenges:**  
- Transposition requires access to diagonal elements from previous iterations  
- May require additional data structures for character position tracking  
- Trade-off between space efficiency and implementation complexity  

---

## Advanced Features  

### Custom Operation Costs
- **Configurable costs** for each operation type (insert, delete, replace, transpose)  
- **Uniform cost mode** for simplified configuration  
- **Individual cost mode** for fine-tuned distance calculations  

### Operation Tracking
- **Detailed operation sequence** showing exact transformations  
- **Cost breakdown** for each operation performed  
- **Visual representation** of the transformation process  

### Multi-Language Support
- Consistent **API design** across C++, Java, and Python  
- **Feature parity** including custom costs and operation tracking  
- **Performance characteristics** appropriate for each language  

---

The DP-based approaches (matrix and space-optimized) are available in the **DP folder**, providing more efficient alternatives to the recursive implementation while maintaining full Damerau-Levenshtein distance functionality.
