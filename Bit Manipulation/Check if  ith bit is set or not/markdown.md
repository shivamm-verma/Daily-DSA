# 🧩 Problem: Check if the i-th bit is set or not

### Problem Statement
Given two integers `n` and `i`, determine whether the `i-th` bit (0-indexed from the least significant bit) in the binary representation of `n` is **set (1)** or **not set (0)**.

---

### Input Format
- Two integers `n` and `i`, separated by a space.

---

### Output Format
- Print `"Yes"` if the `i-th` bit is set.
- Otherwise, print `"No"`.

---

### Example 1
**Input:**
5 0

**Output:**
Yes


**Explanation:**  
Binary representation of 5 = `101`  
The 0th bit (rightmost) = `1`, hence it is set.

---

### Example 2
**Input:**
12 2

**Output:**
No


**Explanation:**  
Binary representation of 12 = `1100`  
The 2nd bit = `0`, hence it is not set.

---

### Constraints
- `0 ≤ n ≤ 10^9`
- `0 ≤ i ≤ 31`

---

### Approach
1. Create a mask by left-shifting 1 by `i` positions → `(1 << i)`.
2. Perform bitwise AND between `n` and the mask.
3. If the result is non-zero, the bit is set; otherwise, it’s not.

---

### Time Complexity
**O(1)** — Constant time operation.

### Space Complexity
**O(1)** — No extra space used.

---

### Topic Tags
`Bit Manipulation` `Beginner Friendly` `Logic Building`

---


