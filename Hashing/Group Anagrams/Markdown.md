# 🧩 Problem: Group Anagrams

Given an array of strings `strs`, group the anagrams together.  
An anagram is a word formed by rearranging the letters of another word using all original letters exactly once.

---

## 📌 Constraints

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.

---

## 🧠 Pseudocode

Initialize empty dictionary: dic For each word in input list: Sort the word to get a key If key not in dic: Create new list for this key Append word to dic[key]

Initialize result list For each value in dic: Append value (list of anagrams) to result

Return result

---

## 🧪 Example

**Input:**
["eat", "tea", "tan", "ate", "nat", "bat"]

**Output:**
[ ["eat", "tea", "ate"], ["tan", "nat"], ["bat"] ]

---

## ⏱️ Time Complexity

- Sorting each word: `O(k log k)` where `k` is the length of the word
- For `n` words: `O(n * k log k)`
- Final grouping: `O(n)`

**Overall:**  
`O(n * k log k)` — where `n` is the number of words and `k` is the average word len(length)

---

## 📦 Space Complexity

- Dictionary to store grouped anagrams: `O(n * k)`
- Result list: `O(n)`

**Overall:**  
`O(n * k)` — storing all words and their sorted keys

---

## ✅ Notes

- Sorting is used to generate a unique key for each anagram group.
- Dictionary helps in constant-time lookup and grouping.
- Efficient for large datasets due to linear grouping after sorting.
