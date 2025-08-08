## ✅ DSA Question: Check if a String is a Palindrome

---

### 🧠 Problem  
Check whether the given string reads the same forward and backward.

**Examples:**  
- Input: `"madam"` → Output: `true`  
- Input: `"hello"` → Output: `false`

---

## 🧭 Approach

1. Initialize two pointers:  
   – `left` at index `0`  
   – `right` at index `length - 1`

2. While `left < right`:  
   – If characters at `left` and `right` don't match → return `false`  
   – Else, increment `left`, decrement `right`

3. If loop completes without mismatches → return `true`

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function isPalindrome(s):
    left = 0
    right = length of s - 1

    while left < right:
        if s[left] != s[right]:
            return false
        left += 1
        right -= 1

    return true
```

## ⏱️ Complexities
 > Time Complexity
**O(n)** — where n is the length of the string; each character is checked once.

> Space Complexity
**O(1)** — constant space; no extra space used except pointers.