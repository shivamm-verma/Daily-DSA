## 🔢 String to Integer (atoi) Implementation — Approach Explained

## 📘 Problem Statement
Implement the `myAtoi` function which converts a string to a 32-bit signed integer (similar to C/C++'s `atoi` function).

The algorithm should:
1. Read and ignore any leading whitespace
2. Check for '+' or '-' to determine the sign
3. Read digits until a non-digit character or end of string is encountered
4. Convert these digits into an integer
5. Handle integer overflow by clamping to INT_MAX (2³¹−1) or INT_MIN (−2³¹)

## 🧪 Example
Input: "-042"
Output: -42

Input: "1337c0d3"
Output: 1337 

Input: "4193 with words"
Output: 4193

Input: "words and 987"
Output: 0

Input: "-91283472332"
Output: -2147483648 (INT_MIN)

## 1️⃣ Optimal Single-Pass Approach
## 💡 Idea
* Process the string character by character in a single pass
* Handle each case (whitespace, sign, digits) sequentially
* Build the integer digit by digit while checking for overflow

## ⚙️ Complexity
> Time: O(n) - Where n is the length of the string. We process each character at most once.

> Space: O(1) - Constant space is used regardless of input size.

## 🔍 Key Insights
* **Whitespace Handling:** Only leading whitespace is ignored
* **Sign Handling:** The sign must appear immediately after whitespace (if any)
* **Digit Parsing:** Conversion stops at first non-digit character
* **Overflow Protection:** Check for overflow before actually multiplying by 10

## 📝 Algorithm Steps
1. Initialize index (i), sign (positive), and result (0)
2. Skip all leading whitespace
3. Handle optional sign character ('+' or '-')
4. Process subsequent digits until non-digit or end of string:
   - Convert character to digit value
   - Check if result would overflow before adding next digit
   - If overflow would occur, return clamped value
   - Otherwise, add digit to result
5. Return final result with appropriate sign

## 🎯 Edge Cases Handled
* Empty string or all whitespace
* Strings with leading/trailing non-digit characters
* Positive and negative numbers
* Integer overflow (both positive and negative)
* Strings with multiple signs ("+-2")
* Strings with numbers followed by non-digits ("123abc")

