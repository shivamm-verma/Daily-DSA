# 🧩 Problem: Array With Sum Zero

## 📜 Problem Statement
Given an integer `n`, return any array containing `n` **distinct integers** such that the sum of all the elements is **0**.

For example, if `n = 5`, one valid answer is `[-2, -1, 0, 1, 2]`.

---

## 💡 Example

**Input:**
```
n = 4
```

**Output:**
```
[1, -1, 2, -2]
```

**Explanation:**
The elements are distinct, and their sum is `1 + (-1) + 2 + (-2) = 0`.

---

## ⚙️ Pseudo Code

```
function sumZero(n):
    create an empty array result of size n

    for i = 0 to n/2 - 1:
        result[i] = i + 1
        result[n - 1 - i] = -(i + 1)

    if n is odd:
        result[n/2] = 0

    return result
```

---

## ⏱️ Time Complexity
- **O(n)**  
  The loop runs n/2 times, assigning two values per iteration.

---

## 💾 Space Complexity
- **O(n)**  
  An array of size n is created to store the result.

---

## 🧠 Example Run

**Input**
```
Enter the value of n: 5
```

**Output**
```
Array with sum zero:
1 -1 2 -2 0
```

**Explanation:**
- For every positive integer `i`, the array contains its negative counterpart `-i`.  
- When `n` is odd, a zero is added in the middle to balance the sum.

---

## 🧮 Approach Summary
- Pairs of numbers `(i, -i)` ensure the sum is always 0.  
- If `n` is odd, `0` is added as the middle element.  
This guarantees both distinctness and a total sum of zero.