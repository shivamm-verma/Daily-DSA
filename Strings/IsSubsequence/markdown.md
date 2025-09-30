## ✅ DSA Question: String isSubsequence

## 🧠 Problem

Given two strings `s` and `t`, check if `s` is a subsequence of `t`.

A string s is a subsequence of t if s can be derived from t by deleting some characters without changing the order of the remaining characters.

---

## Examples:

Input: s = "abc", t = "ahbgdc" → Output: true

Input: s = "axc", t = "ahbgdc" → Output: false

# Approach

To check if s is a subsequence of t, we can use the two pointers method:

## **Steps**

1. Initialize two pointers: i = 0 for s and j = 0 for t.

2. Traverse t using pointer j:

   * If s[i] == t[j], move pointer i to the next character in s.

   * Always move pointer j to the next character in t.

3. After traversal, if i equals the length of s, then s is a subsequence of t.

4. Otherwise, s is not a subsequence.