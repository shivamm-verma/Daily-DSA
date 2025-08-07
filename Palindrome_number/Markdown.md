## 🔢 Palindrome Integer Problem — Stack Approach Explained

## 📘 Problem Statement
Given an integer, determine if it is a palindrome. An integer is a palindrome when it reads the same backward as forward.

**Note:** Negative numbers are not considered palindromes.

## 🧪 Example
Input: 121
Output: It is a palindrome number

Input: -121
Output: It is not a palindrome number

Input: 100
Output: It is not a palindrome number

## 1️⃣ Stack-Based Approach
## 💡 Idea
* Use a stack data structure to reverse the digits of the number.
* Push each digit onto the stack while extracting them from the number.
* Pop digits from the stack and compare with the original number's digits.
* If all digits match, the number is a palindrome.

## ⚙️ Complexity
 >Time: O(log n) - We process each digit of the number

 >Space: O(log n) - Stack space to store all digits

## 🔍 Key Insights
* **Negative Numbers:** All negative numbers are not palindromes
* **Zero:** Zero is considered a palindrome
* **Digit Extraction:** Use modulo operation to get the last digit
* **Stack Usage:** Stack naturally reverses the order of digits
* **Comparison:** Compare digits from both ends simultaneously

## 📝 Algorithm Steps
1. Check if the number is negative (return false)
2. Check if the number is zero (return true)
3. Create an empty stack
4. Extract digits from the number and push them onto the stack
5. Pop digits from the stack and compare with the original number's digits
6. If any mismatch is found, return false
7. If all digits match, return true

## 🎯 Edge Cases Handled
* Negative numbers (return false)
* Zero (return true)
* Single digit numbers (always palindromes)
* Numbers with leading zeros (handled automatically)

## 🔧 Implementation Details
* **Java:** Uses `Stack<Integer>` from `java.util.Stack`
* **C++:** Uses `stack<int>` from `#include <stack>`
* **Digit Extraction:** `num % 10` gets the last digit
* **Number Reduction:** `num / 10` removes the last digit
* **Stack Operations:** `push()`, `pop()`, `top()`, `empty()`

## 📊 Example Walkthrough
For input: 12321

1. Push digits onto stack: [1, 2, 3, 2, 1]
2. Compare stack top with number's last digit:
   - Stack: [1, 2, 3, 2, 1], Number: 12321 → 1 == 1 ✓
   - Stack: [1, 2, 3, 2], Number: 1232 → 2 == 2 ✓
   - Stack: [1, 2, 3], Number: 123 → 3 == 3 ✓
   - Stack: [1, 2], Number: 12 → 2 == 2 ✓
   - Stack: [1], Number: 1 → 1 == 1 ✓
3. All digits match, so 12321 is a palindrome 