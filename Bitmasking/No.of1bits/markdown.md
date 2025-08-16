# 🧮 Count Number of 1-Bits (Set Bits)

## ✅ Problem Statement

Given an integer `n`, return the number of `1`s in its binary representation. This is also known as the **Hamming weight** or **population count**.

---

## 📥 Input

- A single integer `n` (can be positive or negative depending on implementation)

## 📤 Output

- An integer representing the count of `1` bits in the binary representation of `n`.

---

## 🧪 Example

### Input:
n = 13

### Binary Representation:
13 in binary = 00000000000000000000000000001101

### Output:
3

---

## 🧠 Explanation

We iterate through each bit position from `0` to `30` (assuming a 32-bit signed integer and ignoring the sign bit). At each position `i`, we check if the `i-th` bit is set using the expression:

```python
if n & (1 << i):
If the bit is set, we increment our counter. Finally, we return the total count.

---

⏱️ Time Complexity
O(31) → Constant time since the loop runs a fixed number of times (31 iterations).

Alternatively, O(log n) if using optimized methods like Brian Kernighan’s algorithm.

---

📦 Space Complexity
O(1) → Only a single counter variable is used; no extra space required.

---

📌 Notes
For unsigned integers, you may loop through all 32 bits.

For negative numbers, behavior depends on two's complement representation.

Consider using bin(n).count('1') for a Pythonic shortcut (though less educational for bit manipulation practice).