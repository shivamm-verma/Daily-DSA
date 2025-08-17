## ✅ DSA Question: Valid Parentheses

## 🧠 Problem  
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Examples:

Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false

## 🧭 Approach  
To determine if two strings are anagrams, we can use one of the following approaches:

### **Approach 1: Using Stack**  
- Use a stack to store opening brackets.
- When a closing bracket comes, check if it matches the top of the stack; if yes, pop it, else return false.
- At the end, if stack is empty → string is valid, otherwise invalid.

## 🔁 Generic Logic (Pseudocode)
```
Function isValid(string):

    Initialize an empty stack

    For each character ch in string:
        If ch is an opening bracket ( ( , { , [ ):
            Push ch onto stack
        Else if ch is a closing bracket:
            If stack is empty → return False
            If top of stack matches opening of ch → Pop stack
            Else → return False

    If stack is empty → return True
    Else → return False
```
        
## ⏱️ Complexities

Time Complexity:
We traverse the input string once → O(n), where n = length of string.

Each push and pop operation on stack is O(1).

✅ Overall time complexity: O(n)

Space Complexity:
In the worst case (e.g. "(((((((("), we might push all characters into the stack.

So extra space used = size of stack = O(n).

✅ Overall space complexity: O(n)
