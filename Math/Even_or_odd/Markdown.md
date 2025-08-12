## 🔢 Even or Odd Number Problem — Bitwise Operator Approach Explained

## 📘 Problem Statement
Given an integer, determine if it is even or odd. An integer is even if it is divisible by 2, and odd otherwise.

**Note:** This problem demonstrates the efficient use of bitwise operators for checking number properties.

## 🧪 Example
Input: 10
Output: 10 is even

Input: 7
Output: 7 is odd

Input: 0
Output: 0 is even

Input: -3
Output: -3 is odd

## 1️⃣ Bitwise Operator Approach
## 💡 Idea
* Use the bitwise AND operator (&) to check the least significant bit (LSB)
* If the LSB is 0, the number is even
* If the LSB is 1, the number is odd
* This is more efficient than using modulo operator (%)

## ⚙️ Complexity
 >Time: O(1) - Constant time operation

 >Space: O(1) - No extra space required

## 🔍 Key Insights
* **Binary Representation:** Every number has a binary representation
* **Least Significant Bit:** The rightmost bit determines if a number is even or odd
* **Bitwise AND:** `num & 1` extracts the LSB
* **Even Numbers:** Have LSB = 0 (e.g., 10 = 1010₂)
* **Odd Numbers:** Have LSB = 1 (e.g., 7 = 0111₂)
* **Negative Numbers:** Work the same way due to two's complement representation

## 📝 Algorithm Steps
1. Take the input number
2. Perform bitwise AND with 1: `num & 1`
3. If result is 0, the number is even
4. If result is 1, the number is odd
5. Return the appropriate result

## 🎯 Edge Cases Handled
* Zero (0 is even)
* Negative numbers (work correctly with two's complement)
* Large numbers (bitwise operations are efficient)
* Single digit numbers (work correctly)

## 🔧 Implementation Details
* **Java:** Uses `Scanner` for input, bitwise AND operator `&`
* **C++:** Uses `cin` for input, bitwise AND operator `&`
* **Bitwise AND:** `num & 1` returns 0 for even, 1 for odd
* **Boolean Return:** Function returns `even` for even, `odd` for odd
* **Input Validation:** Handles all integer types

## 📊 Example Walkthrough
For input: 10

1. Binary representation: 10 = 1010₂
2. Perform bitwise AND with 1: 1010₂ & 0001₂ = 0000₂ = 0
3. Since result is 0, 10 is even

For input: 7

1. Binary representation: 7 = 0111₂
2. Perform bitwise AND with 1: 0111₂ & 0001₂ = 0001₂ = 1
3. Since result is 1, 7 is odd

## 🚀 Advantages of Bitwise Approach
* **Efficiency:** Faster than modulo operation
* **Memory:** No extra space required
* **Simplicity:** One-line solution
* **Universal:** Works for all integer types
* **Educational:** Demonstrates bitwise operator usage

## 🔄 Alternative Approaches
* **Modulo Operator:** `num % 2 == 0` (slower but more readable)
* **Division:** `(num / 2) * 2 == num` (inefficient)
* **Bitwise XOR:** `(num ^ 1) == num + 1` (for even numbers)

## 📈 Performance Comparison
* **Bitwise AND:** O(1) - Fastest
* **Modulo:** O(1) - Slightly slower due to division
* **Division:** O(1) - Slowest due to full division operation

## 🎓 Learning Outcomes
* Understanding of binary number representation
* Mastery of bitwise operators
* Efficient problem-solving techniques
* Performance optimization concepts
* DSA fundamentals with practical implementation 