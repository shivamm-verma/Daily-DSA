# 🔠 Group Anagrams — Multi-language Implementation

## 🧾 Problem Statement
Given an array of strings, group the anagrams together.  
An anagram is a word formed by rearranging the letters of another, such as `"eat"` and `"tea"`.

---

## 🧠 Example

**Input:**  
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

**Output:**  
```python
[
  ["eat", "tea", "ate"],
  ["tan", "nat"],
  ["bat"]
]

---

##🧩 Approach
Use a hash map to group words by their sorted character sequence.

For each string:

Sort its characters alphabetically.

Use the sorted string as a key in the map.

Append the original string to the corresponding list.

Return all grouped lists as the final result.

---

##📈 Time Complexity
O(n × k log k)

n = number of strings

k = average length of each string

Sorting each string takes O(k log k)

---

##🧠 Space Complexity
O(n × k)

For storing all strings in the hash map

---

##📌 Topics Covered
- Strings

- Hashing

- Sorting

- Anagram Detection

- Dictionary/Map Usage






