# 🧮 DSA QUESTION: Reverse words in a string

---

## 📝 Problem Statement
Given a string `s`, reverse the order of words.  
A word is defined as a sequence of non-space characters.  
The returned string should have words separated by a single space, with no leading or trailing spaces.

---

## 💡 Examples

**Input:**  
`s = "  the sky is blue  "`

**Output:**  
`"blue is sky the"` 

**Explanation:**  
Input:  "the sky is blue"
Split:  ["the", "sky", "is", "blue"]
Reverse:["blue", "is", "sky", "the"]
Join:   "blue is sky the"

**Input:**  
`s = "  hello world  "`  

**Output:**  
`"world hello"`  

---

## ✅ Constraints
- 1 <= s.length <= 104
- s contains English letters (upper-case and lower-case), digits, and spaces ' '.
- There is at least one word in s.  

---

## 🔄 Approach (Character Iteration, Reverse Traversal)

### 💡 Idea
Traverse the string **from end to start** and rebuild words in reverse order:

- First, trim the input string to remove leading and trailing spaces.  
- Add an extra space at the front to simplify word detection.  
- Iterate backward through the string:  
  - If you find a **space**, check if a word has been collected → append it to the result.  
  - Otherwise, keep building the current word.  
- At the end, trim the result to remove extra leading space.

---

### 🔁 Steps
1. Trim input string `s`.  
2. Add a space in front → `s = " " + s`.  
3. Initialize empty `s1` (final result) and `word` (temporary storage).  
4. Traverse from `s.length()-1` to `0`:  
   - If `s[i] == ' '`:  
     - If `word` is not empty → append `" " + word` to `s1`, then reset `word`.  
   - Else → prepend current character to `word`.  
5. Return `s1.trim()` as the final result.

---

### 📜 Pseudocode (Matching Java Solution)
```text
function reverseWords(s):
    s = trim(s)
    s = " " + s
    s1 = ""
    word = ""

    for i = length(s)-1 down to 0:
        if s[i] == ' ':
            if word != "":
                s1 = s1 + " " + word
                word = ""
        else:
            word = s[i] + word

    return trim(s1)


**⏱️ Complexities**

##Time Complexity:
Traversing string: O(n)
But string concatenations (word = char + word and s1 = s1 + word) → O(n²) worst case

##Space Complexity: O(n) — storage for result and word