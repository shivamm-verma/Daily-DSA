## ✅ DSA Question: Reverse a String In-Place

---

### 🧠 Problem  
Given a string as an array of characters, reverse it in-place using **O(1)** extra memory.

You **must not return a new string**; instead, modify the input character array.

**Examples:**  
- Input: `"hello"` → Output: `"olleh"`  
- Input: `"Hannah"` → Output: `"hannaH"`

---

## 🧭 Approach

1. Initialize two pointers:  
   – `left` at index `0`  
   – `right` at index `length - 1`

2. While `left < right`:  
   – Swap `s[left]` and `s[right]`  
   – Increment `left` and decrement `right`

3. Once all elements have been swapped, the string is reversed in-place.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function reverseString(s):
    left = 0
    right = length of s - 1

    while left < right:
        temp = s[left]
        s[left] = s[right]
        s[right] = temp
        left += 1
        right -= 1
```
## ⏱️ Complexities
 >Time Complexity
**O(n)** — where n is the number of characters in the string.

 >Space Complexity
**O(1)** — in-place reversal using only two pointers.