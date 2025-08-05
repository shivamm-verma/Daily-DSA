
# ❓ Problem: Rotate Matrix 90° Clockwise (In-Place)

Given an `N x N` square matrix, rotate the matrix by **90 degrees clockwise**, **in-place** (i.e., without using extra space).

---

## 📌 Example

**Input:**
```
[
 [1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]
]
```

**Output:**
```
[
 [7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]
]
```

---

## Approach

### 🔍 Intuition

1. **Transpose the matrix**
2. **Reverse each row**

All steps are done in-place and use only a constant number of extra variables.

---

## ✅ Final Summary Table

Approach         

Time Complexity - O(N²)  
Space Complexity - O(1)