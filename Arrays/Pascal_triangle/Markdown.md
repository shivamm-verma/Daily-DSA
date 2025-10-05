## ✅ DSA Project: Pascal's Triangle Generator

---

### 🧠 Problem  
Generate Pascal’s Triangle up to a given number of rows. Pascal’s Triangle is a triangular array of binomial coefficients where each number is the sum of the two numbers directly above it.

**Examples:**  
- Input: `n = 5` → Output:
```
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

---

## 🧭 Approach

1. Start with the **first value** of every row as `1`.  
2. For each subsequent value in the row:  
   – Calculate using the formula:  
   ```plaintext
   val = val * (i - j) / (j + 1)
   ```
  where i is the row index and j is the position in the row.

3. Repeat until all n rows are generated.

## 🔁 Generic Logic (Pseudocode)
```
function generatePascal(n):
    for i from 0 to n-1:
        val = 1
        for j from 0 to i:
            print(val)
            val = val * (i - j) / (j + 1)
```

## ⏱️ Complexities

> Time Complexity: O(n²) — Each value of Pascal's Triangle is computed once.

> Space Complexity: O(1) — Only variables are used; no extra memory for factorials.
