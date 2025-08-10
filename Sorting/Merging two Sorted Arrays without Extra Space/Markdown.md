# 🔗 Merge Two Sorted Arrays Without Extra Space (Gap Method)

## ✅ Problem Statement
Given two sorted arrays `a[]` and `b[]` of sizes `n` and `m`, merge them in **ascending order** without using extra space so that both arrays remain sorted after merging.

---

## 🔍 Key Observations
- Direct merging into a third array uses **O(n + m)** space – not allowed here.
- Both arrays are **already sorted**.
- We can treat the two arrays as a single sequence and rearrange in-place.
- **Gap Method** (inspired by Shell Sort) is the optimal approach for this constraint.

---

## 💡 Algorithmic Strategy (Gap Method)

Approach:
- Treat both arrays as a single array of size `n + m`.
- Start with an initial `gap = ceil((n + m) / 2)`.
- Compare elements `gap` distance apart and **swap if out of order**.
- Reduce `gap = ceil(gap / 2)` after each pass.
- Repeat until `gap = 1` and final pass is done.

Three comparison cases:
1. Both pointers in first array `a[]`
2. First in `a[]`, second in `b[]`
3. Both pointers in second array `b[]`

---

## 📊 Complexity Analysis
- **Time Complexity:** O((n + m) * log(n + m))  
  → Each pass processes `n + m` elements, gap reduces by ~half.
- **Space Complexity:** O(1) – in-place merging, no extra array.

---

## 🧾 Pseudocode
```plaintext
function mergeArrays(a, b):
    n ← length(a)
    m ← length(b)
    gap ← ceil((n + m) / 2)

    while gap > 0:
        i ← 0
        j ← gap

        while j < (n + m):
            if j < n and a[i] > a[j]:
                swap a[i] and a[j]
            else if i < n and j ≥ n and a[i] > b[j - n]:
                swap a[i] and b[j - n]
            else if i ≥ n and b[i - n] > b[j - n]:
                swap b[i - n] and b[j - n]
            i ← i + 1
            j ← j + 1

        if gap == 1:
            break
        gap ← ceil(gap / 2)
