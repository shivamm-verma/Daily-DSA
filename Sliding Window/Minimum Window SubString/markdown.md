## ✅ DSA Question: Minimum Window Substring

---

### 🧠 Problem  
Given two strings `s` and `t`, return the **minimum window substring** of `s` such that every character in `t` is included.  If no such substring exists, return `""`.

**Examples:**  
- Input: `"s = "ADOBECODEBANC", t = "ABC"` → Output: `"BANC"`  
- Input: `"s = "a", t = "a"` → Output: `"a"`  

**Constraints:**  
- 1 <= s.length, t.length <= 10^5  
- `s` and `t` consist of uppercase and lowercase English letters.

---

## 🧭 Approach [ Brute Force ]

1. Generate **all substrings** of `s`.
2. For each substring, check if it contains all characters of `t`.
3. Track the minimum length substring.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function minWindowBrute(s, t):
    ans = ""
    minLen = INF
    for i from 0 to n-1:
        for j from i to n-1:
            sub = s[i:j+1]
            if sub contains all chars in t and length < minLen:
                ans = sub
                minLen = length of sub
    return ans
```

## ⏱️ Complexities
 > Time Complexity
**O(n^3)** — generating all substrings + checking

> Space Complexity
**O(1)** — only a few variables
---

## 🧭 Approach [ Better Approach ]

1. Use a frequency array or hashmap for t.
2. For each starting index i in s, expand the window until all chars of t are covered.
3. Track the minimum window length.
---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function minWindowBetter(s, t):
    ans = ""
    minLen = INF
    for i from 0 to n-1:
        freq = hashmap of t
        for j from i to n-1:
            decrement freq[s[j]] if present
            if all freq <= 0:
                update ans and minLen
                break
    return ans
```

## ⏱️ Complexities
 > Time Complexity
**O(n^2)** — sliding window for each start

> Space Complexity
**O(128) ~ O(1)** — for frequency array

---

## 🧭 Approach [ Optimal Approach ]

1. Use sliding window + hashmap:
   - Keep two pointers l and r for window.
   - Expand r and include characters until window covers all chars in t.
   - Shrink l to minimize window while maintaining all chars.

2. Track minimum length window during process.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function minWindowOptimal(s, t):
    need = hashmap of t counts
    window = empty hashmap
    have = 0, required = number of unique chars in t
    l = 0, minLen = INF, start = 0

    for r from 0 to n-1:
        add s[r] to window
        if window[s[r]] == need[s[r]]:
            have += 1

        while have == required:
            if current window length < minLen:
                update minLen and start
            remove s[l] from window
            if window[s[l]] < need[s[l]]:
                have -= 1
            l += 1

    return substring starting at start of length minLen
```

## ⏱️ Complexities
 > Time Complexity
**O(n)** — each char processed at most twice

> Space Complexity
**O(128) ~ O(1)** — for hashmap

---
