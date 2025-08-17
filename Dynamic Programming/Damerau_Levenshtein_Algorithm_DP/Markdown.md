# Damerau-Levenshtein Algorithm  

## Introduction  

The **Damerau-Levenshtein distance** measures similarity between two strings using four operations: **insertion**, **deletion**, **replacement**, and **transposition**. It extends Levenshtein by including transpositions, making it effective for detecting typing errors.  

### Example  
- `"kitten" → "sitting"` → distance = 3  
- `"martha" → "marhta"` → distance = 1 (vs. 2 in Levenshtein)  

### Properties  
- **Bounds**: `0` to `max(m, n)`  
- **Error coverage**: 80%+ of human spelling errors  
- **Variants**:  
  - OSA (restricted, no repeated edits)  
  - True (unrestricted, metric)  
- **Relations**:  
  - Levenshtein ⊂ Damerau-Levenshtein  
  - Hamming (equal-length only)  
  - Jaro-Winkler (prefix/transposition focus)  

### Applications  
Spell checkers, autocorrect, deduplication, DNA analysis, NLP  

---

## Project Overview  

Two approaches, three languages (**C++, Java, Python**):  
1. **Better** – DP matrix  
2. **Optimal** – Space-optimized DP  

---

## Brute Force  

- **Function 1**: distance only → `O(4^N)` time, `O(N)` space  
- **Function 2**: distance + operations → `O(4^N)` time, `O(N^2)` space  
- Detects transposition via character swaps, compares all four operations  

---

## Better Approach – DP Matrix  

- **Function 1**: distance → `O(M*N)` time, `O(M*N)` space  
- **Function 2**: distance + ops → `O(M*N)` time, `O(M*N)` space  
- Tracks character positions and diagonals for transpositions  
- Supports OSA and unrestricted variants  

---

## Optimal Approach – Space Optimization  

- **Method**: three vectors (`prev_prev`, `prev`, `curr`)  
- **Complexity**: `O(M*N)` time, `O(min(M,N))` space  
- Features:  
  - Auto string swap for efficiency  
  - Transposition with `prev_prev[i-2]`  
  - Vector shifting per iteration  
  - Custom costs supported  

---

## Advanced Features  

- **Custom Costs**: uniform or individual (insert, delete, replace, transpose)  
- **Operation Tracking**: sequence, breakdown, visual logs  
- **Multi-Language Support**: consistent API, feature parity, optimized per language  

---

The **brute force approach** resides in the **recursion folder**, providing a foundational recursive implementation for full Damerau-Levenshtein distance.
