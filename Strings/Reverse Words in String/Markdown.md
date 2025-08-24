# 🧮 DSA QUESTION: Reverse Words in a String

---

## 📝 Problem Statement
Given a string `s`, reverse the order of words in the string.

- A **word** is a sequence of non-space characters.  
- Words in `s` may be separated by **one or more spaces**.  
- The output string should have words separated by a single space, with no leading or trailing spaces.  

---

## 💡 Examples

**Input:**  
`"the sky is blue"`  
**Output:**  
`"blue is sky the"`

**Input:**  
`"  hello world  "`  
**Output:**  
`"world hello"`

**Input:**  
`"a good   example"`  
**Output:**  
`"example good a"`

**Input:**  
`"single"`  
**Output:**  
`"single"`

**Input:**  
`"    "`  
**Output:**  
`""` (empty string)

---

## ✅ Constraints
- `1 <= s.length <= 10^5`  
- `s` may contain letters, digits, punctuation, and spaces.  
- Treat words as any **non-space** sequences.  

---

## 🐢 Approach (Backwards Traversal)

### 💡 Idea
Traverse the string **from end to start**, building each word character by character. When a space is found, append the completed word to the result. This avoids creating an extra array of words.

### 🔁 Steps
1. Trim the input string and add a leading space for easier processing.  
2. Initialize an empty string `word` to store the current word.  
3. Initialize an empty string `s1` to store the result.  
4. Loop from the end of the string to the start:
    - If the current character is a space:
        - If `word` is not empty, append it to `s1` with a space, then reset `word`.  
    - Else, prepend the character to `word` to build it.  
5. After the loop, trim `s1` to remove any leading/trailing spaces.  
6. Return the result.  
 

### 📜 Pseudocode
function reverseWords(s):
    s1 = ""       # final result string
    word = ""     # current word being built
    s = " " + trim(s)   # add leading space and remove extra spaces

    for i from length(s)-1 down to 0:
        if s[i] == ' ':
            if word is not empty:
                s1 = s1 + " " + word
                word = ""
        else:
            word = s[i] + word   # prepend character to build the word

    return trim(s1)   # remove leading/trailing spaces from final result


**⏱️ Complexities**
Time Complexity: O(n) — scanning, splitting, reversing, joining.
Space Complexity: O(n) — storing array of words.


**🧪 Edge Cases**

**Input:** " " 
**Output:** ""

**Input:** "single" 
**Output:** "single"

Multiple spaces between words collapse into one.
Handles punctuation/digits as part of words.