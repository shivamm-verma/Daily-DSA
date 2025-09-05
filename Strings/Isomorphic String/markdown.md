## ✅ DSA Question: Isomorphic Strings

## 🧠 Problem

Given two strings `s` and `t`, determine if they are **isomorphic**.

Two strings are isomorphic if the characters in `s` can be replaced to get `t`, with the following conditions:

* Every character must map to exactly one other character.
* No two different characters can map to the same character.

### Examples:

* Input: `s = "egg"`, `t = "add"` → Output: `true`
* Input: `s = "foo"`, `t = "bar"` → Output: `false`
* Input: `s = "paper"`, `t = "title"` → Output: `true`

---

## 🧭 Approach

To check if two strings are isomorphic, we need to ensure a **one-to-one mapping** between characters of `s` and `t`.

### **Steps**

1. If lengths differ, return `false`.
2. Use two hash maps (or arrays for ASCII) to store:

   * mapping `s -> t`
   * mapping `t -> s`
3. While traversing, check consistency of mapping:

   * If a mapping exists, it must match the current character.
   * If not, create a new mapping.
4. If all mappings are consistent, return `true`.

---

## 🔁 Generic Logic (Pseudocode)

```
function isIsomorphic(s, t):
    if length(s) != length(t):
        return false

    mapST = {}
    mapTS = {}

    for i in range(0, length(s)):
        a = s[i]
        b = t[i]

        if a in mapST and mapST[a] != b:
            return false
        if b in mapTS and mapTS[b] != a:
            return false

        mapST[a] = b
        mapTS[b] = a

    return true
```

---

## ⏱️ Complexities

* **Time Complexity:** O(n), where n = length of strings
* **Space Complexity:** O(k), where k = size of character set (constant for ASCII)

---
