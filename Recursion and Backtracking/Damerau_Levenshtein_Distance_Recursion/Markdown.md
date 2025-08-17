# Damerau-Levenshtein Algorithm Showcase  

## What it is  
The Damerau-Levenshtein distance measures similarity between two strings as the minimum number of **insertions**, **deletions**, **substitutions**, and **transpositions** needed to transform one string into the other.  

## Allowed Operations  
- Insertion  
- Deletion  
- Replacement  
- Transposition (swap two adjacent characters)  

## Example  
Transform `"kitten"` → `"sitting"` (all costs = 1):  
1. `kitten → sitten` (substitution)  
2. `sitten → sittin` (substitution)  
3. `sittin → sitting` (insertion)  

**Distance = 3**  

Transposition example:  
`"martha"` → `"marhta"` by swapping `"th"` → `"ht"`  
**Distance = 1**  

## Applications  
- Spell checking & autocorrect  
- Duplicate detection  
- DNA sequence analysis  
- Text similarity in NLP  

## This Project  
- Implements Damerau-Levenshtein using recursion  
- Two modes:  
  1. **Cost only**  
  2. **Cost + operations**  
- Implemented in **C++**, **Java**, and **Python**  

---

The DP-based approaches (matrix and space-optimized) are available in the **DP folder**, providing more efficient alternatives to the recursive implementation while maintaining full Damerau-Levenshtein distance functionality.
