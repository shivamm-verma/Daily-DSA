# Levenshtein Algorithm Showcase  


## Introduction to Levenshtein Distance  

The **Levenshtein distance** is a measure of similarity between two strings, defined as the minimum number of **insertions**, **deletions**, and **substitutions** required to transform one string into the other.  

### Allowed Operations  
- **Insertion**: Adding a character to string A.  
- **Deletion**: Removing a character from string A.  
- **Replacement**: Replacing a character in string A with another character.  

### Example  
Transform `"kitten"` into `"sitting"`:
{Considering that the cost of all the cost are same and equal to 1}  

1. `kitten → sitten` (substitute `"s"` for `"k"`)  
2. `sitten → sittin` (substitute `"i"` for `"e"`)  
3. `sittin → sitting` (insert `"g"` at the end)  

Here, **Levenshtein distance = 3**.  

### Bounds  
- **Lower bound**: `0` (when both strings are identical).  
- **Upper bound**: `max(m, n)` for strings of length `m` and `n`.  

### Applications  
- **Autocorrect algorithms** – Used in text editors and keyboards (e.g., Gboard, SwiftKey).  
- **Data cleaning** – Removing redundancy and identifying similar records.  
- **Data clustering/classification** – Grouping or labeling similar text records.  

### Relationship with Other Edit Distances  
- **Damerau–Levenshtein distance**: Includes transpositions as a fourth allowed operation.  
- **Hamming distance**: Works only on equal-length strings, counts differing positions.  

---

## Project Overview  
This project implements the **Levenshtein Algorithm** using **two approaches**, each developed in **three programming languages** for versatility and comparison.  

### Approaches  
1. **Better Solution** – Dynamic Programming with full DP matrix.  
2. **Optimal Solution** – Space-optimized Dynamic Programming.  

### Languages  
1. **C++**  
2. **Java**  
3. **Python**  

---

## **Brute Force Approach**  
**Recursive Implementation**:  
- **Function 1**: Returns only the minimum edit distance.  
  - Time Complexity: `O(3^N)`  
  - Space Complexity: `O(N)` (stack space)  
- **Function 2**: Returns both minimum edit distance and the sequence of operations.  
  - Time Complexity: `O(3^N)`  
  - Space Complexity: `O(N)` (stack + operation vector)  

---

## **Better Approach – Minimum Weighted Edit Distance (DP Matrix)**  
**Dynamic Programming Implementation**:  
- **Function 1**: Returns only the minimum edit distance.  
  - Time Complexity: `O(M*N)`  
  - Space Complexity: `O(M*N)` (DP matrix)  
- **Function 2**: Returns minimum edit distance + operations performed.  
  - Time Complexity: `O(M*N)`  
  - Space Complexity: `O(M*N)` (DP matrix + operation vector)  

---

## **Optimal Approach – Space Optimization**  
**DP Vector Implementation**:  
- Only two rows (previous and current) are stored instead of the full matrix.  
- **Time Complexity**: `O(M*N)` (two nested loops).  
- **Space Complexity**: `O(2N)` (two DP vectors).  
- Function returns only the minimum edit distance and prints vector calculations.  

---


The brute force approach is under **recursion folder**, in the same project.