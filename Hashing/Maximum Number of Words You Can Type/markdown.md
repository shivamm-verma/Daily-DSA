# 🧩 Problem: Maximum Number of Words You Can Type

## 📜 Problem Statement
You are given a string `text` consisting of words separated by spaces, and another string `brokenLetters` containing characters representing keys that are broken on a keyboard.  

Your task is to determine how many words in the `text` can be **fully typed** without using any of the broken letters.

A word can be typed if none of its characters appear in the `brokenLetters` string.

---

## 💡 Example

**Input:**
```
text = "hello world"
brokenLetters = "ad"
```

**Output:**
```
1
```

**Explanation:**
- "hello" can be typed (no 'a' or 'd')
- "world" cannot be typed because it contains 'd'  
Hence, only 1 word can be typed.

---

## ⚙️ Pseudo Code

```
function canBeTypedWords(text, brokenLetters):
    create a set 'broken' from characters in brokenLetters
    split text into words using space as delimiter
    initialize count = 0

    for each word in words:
        canType = true
        for each character ch in word:
            if ch exists in broken:
                canType = false
                break
        if canType is true:
            increment count

    return count
```

---

## ⏱️ Time Complexity
- **O(N × M)**  
  where **N** is the number of words and **M** is the average word length.  
  Each character in the input text is checked once against the broken letters set.

---

## 💾 Space Complexity
- **O(K)**  
  where **K** is the number of unique broken letters (for the unordered_set).

---

## 🧠 Example Run
**Input**
```
Enter the sentence: the quick brown fox
Enter broken letters (no spaces): o
```

**Output**
```
You can type 2 word(s) without using broken letters.
```

**Explanation:**
Words: "the", "quick", "brown", "fox"  
- "brown" and "fox" contain 'o' → cannot be typed  
- "the" and "quick" can be typed → count = 2
