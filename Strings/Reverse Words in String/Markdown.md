✅ DSA Question: Reverse Words in a String


Problem:
Given a string s, reverse the order of words in the string.
A word is defined as a sequence of non-space characters.
The words in s are separated by one or more spaces.
The output string should have words separated by a single space, with no leading or trailing spaces.

Examples:
Input: "the sky is blue" → Output: "blue is sky the"
Input: " hello world " → Output: "world hello"
Input: "a good example" → Output: "example good a"

🧭 Approach

Trim spaces
– Remove leading and trailing spaces.
Split words
– Split the string by spaces (ignoring multiple spaces).
Reverse the word list
– Reverse the order of words.
Join words
– Concatenate words with a single space in between.

🔁 Generic Logic (Pseudocode)
function reverseWords(s):
    s = trim spaces from start and end of s
    words = split s by spaces (ignore extra spaces)

    reverse(words)

    return join words with " "

⏱️ Complexities
Time Complexity
O(n) — traversing the string and reversing the words takes linear time.
Space Complexity
O(n) in most languages, because splitting creates an array of words.
Can be optimized to O(1) (in-place reversal) if done manually with character array.