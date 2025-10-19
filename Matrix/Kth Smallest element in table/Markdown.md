# Problem— Kth Smallest Number in Multiplication Table

## 📄 Problem Statement

You are given two positive integers `m` and `n`, which define an `m × n` multiplication table: the value at cell `(i, j)` (1-indexed) is `i * j`.  

Given a positive integer `k`, return the k-th smallest number in this multiplication table (when all the `m × n` values are written in a sorted order, counting duplicates).

### Constraints / Details

- `m, n` can be up to **3 × 10⁴**  
- `k` can be up to **10⁹**  
- The multiplication table has **m * n** entries (potentially up to ∼9×10⁸)  
- Sorting all elements explicitly would be computationally expensive or infeasible for large sizes

---

## 🧠 Key Insights & Approach

1. **Monotonicity & counting**  
   - In any sorted list, the k-th smallest element `x` is such that **exactly `k` values ≤ `x`** in the table.  
   - For a candidate value `X`, you can **count how many table entries ≤ `X`** by summing, for each row `i` (from 1 to `m`),  
     `min(n, floor(X / i))`.  
   - Use that count to guide a **binary search** over possible values of `X`.

2. **Search space**  
   - The **smallest** possible value is `1 * 1 = 1`.  
   - The **largest** possible value is `m * n` (i.e. the bottom-right corner of the table).  
   - Use binary search between 1 and `m * n` (or between 1 and `m * n`, or max possible product) to find the smallest `X` such that **count(≤ X) ≥ k**.

3. **Correctness & termination**  
   - Because counting function is non-decreasing in `X`, binary search will home in on the correct threshold.  
   - The final `X` found is the **k-th smallest**.

---

## ✅ Example Cases

| Example | Input | Output | Explanation |
|-------- |-------|--------|-------------|
| 1       | `m = 3`, `n = 3`, `k = 5` | `3` | The 3×3 table is: 1,2,3; 2,4,6; 3,6,9 → sorted: 1,2,2,3,3,4,6,6,9 → the 5th element is 3 |
| 2       | `m = 2`, `n = 3`, `k = 6` | `6` | The table is: 1,2,3; 2,4,6 → sorted: 1,2,2,3,4,6 → 6 is the 6th element |

---

## ⚙️ Time & Space Complexity

| Metric    |    Complexity           |
|---------- |-------------------------|
| **Time**  | O((m + n) · log(m · n)) |
| **Space** | O(1)                    | 
