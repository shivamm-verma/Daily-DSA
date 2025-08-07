
# Longest Substring Without Repeating Characters

## 🧠 Problem Statement

Given a string `s`, find the **length of the longest substring** without repeating characters.

### Example:

```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

---

## 🔍 Brute Force Approach

### 👨‍💻 Idea:

Check all substrings and see if they have all unique characters.

### 🧾 Pseudocode:
```
for i from 0 to n-1:
    for j from i to n-1:
        if substring s[i..j] has all unique characters:
            update maxLen = max(maxLen, j - i + 1)
```

### 🕒 Time Complexity:
- O(n³) → two nested loops and a set lookup for each substring

### 💾 Space Complexity:
- O(min(n, m)) → for storing characters in a Set

---

## 💻 Code Implementation

### Java

```java
import java.util.HashSet;

public class LongestSubstringBF {
    public static int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (allUnique(s, i, j)) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }

    private static boolean allUnique(String s, int start, int end) {
        HashSet<Character> set = new HashSet<>();
        for (int i = start; i <= end; i++) {
            if (set.contains(s.charAt(i)))
                return false;
            set.add(s.charAt(i));
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring("abcabcbb")); // Output: 3
    }
}
```

---

## ✅ Optimal Sliding Window Approach

### 👨‍💻 Idea:

Use a sliding window with two pointers and a HashSet to maintain the current substring.

- Start with two pointers `left` and `right`
- Move `right` and add characters to the set
- If character repeats, remove characters from `left` until it becomes unique again
- Keep track of the max window length

---

### 🔁 Pseudocode:
```
initialize set, left = 0, maxLen = 0

for right from 0 to n-1:
    while s[right] is in set:
        remove s[left] from set
        left += 1
    add s[right] to set
    maxLen = max(maxLen, right - left + 1)
```

---

### 🧪 Dry Run:

```
s = "abcabcbb"

Step-by-step:

right = 0, char = a → set = {a}, maxLen = 1  
right = 1, char = b → set = {a, b}, maxLen = 2  
right = 2, char = c → set = {a, b, c}, maxLen = 3  
right = 3, char = a → a is in set → remove a → set = {b, c}, add a → set = {b, c, a}, maxLen = 3  
...
Eventually we find substrings: "abc", "bca", "cab", all of length 3.
So max length remains 3.
```

### ✅ Final Answer = 3

---

## 🕒 Time and Space Complexity:

| Metric           | Value                                |
|------------------|----------------------------------------|
| Time Complexity  | O(n)                                   |
| Space Complexity | O(k) → k is the size of the charset    |

---

## 💡 Why Optimal is Better:

- Brute force checks all substrings → very slow for large inputs
- Optimal uses sliding window → only checks necessary characters, hence **linear time**

---




---

## 📌 Notes:

- Works with ASCII and Unicode characters.
