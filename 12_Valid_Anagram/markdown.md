✅ DSA Question: Valid Anagram

🧠 Problem  
Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

Examples:

Input: s = "anagram", t = "nagaram" → Output: true  
Input: s = "rat", t = "car" → Output: false

🧭 Approach  
To determine if two strings are anagrams, we can use one of the following approaches:

**Approach 1: Sorting**  
- Sort both strings.
- If the sorted strings are equal, then they are anagrams.

**Approach 2: Frequency Count**  
- Create a frequency count of characters for both strings.
- If the frequency maps match, they are anagrams.

In this implementation, we use **sorting** for simplicity.

🔁 Generic Logic (Pseudocode)

function isAnagram(s, t):
    if length of s != length of t:
        return false

    sort s
    sort t

    if s == t:
        return true
    else:
        return false
        
⏱️ Complexities

Time Complexity:

Sorting takes O(n log n), where n is the length of the string.

Space Complexity:

O(1) if sorting is done in-place, else O(n) depending on the sorting algorithm used.