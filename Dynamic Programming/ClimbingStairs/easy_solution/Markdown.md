## 🏃‍♂️ Climbing Stairs Problem — Easy Recursive Solution

## 📘 Problem Statement
You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**Note:** This is the easy solution using simple recursion, suitable for understanding the basic concept.

## 🧪 Example
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top:
1. 1 step + 1 step
2. 2 steps

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top:
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

## 1️⃣ Simple Recursive Approach
## 💡 Idea
* Use recursion to explore all possible ways to climb
* At each step, we have two choices: climb 1 step or 2 steps
* Base cases: if n ≤ 2, return n directly
* For n > 2, the result is the sum of climbing (n-1) and (n-2) steps

## ⚙️ Complexity
 >Time: O(2^n) - Exponential due to repeated calculations

 >Space: O(n) - Recursion stack depth

## 🔍 Key Insights
* **Fibonacci Pattern:** The solution follows Fibonacci sequence
* **Recursive Structure:** Each step depends on previous two steps
* **Base Cases:** n = 1 (1 way), n = 2 (2 ways)
* **Choice Making:** At each step, choose 1 or 2 steps
* **Sum of Possibilities:** Total ways = ways(n-1) + ways(n-2)

## 📝 Algorithm Steps
1. Check if n ≤ 2, return n directly
2. For n > 2, recursively calculate:
   - climbStairs(n-1) + climbStairs(n-2)
3. Return the sum

## 🎯 Edge Cases Handled
* n = 0 (returns 0)
* n = 1 (returns 1)
* n = 2 (returns 2)
* Large values of n (may cause stack overflow)

## 🔧 Implementation Details
* **Java:** Uses `Scanner` for input, recursive function calls
* **C++:** Uses `cin` for input, recursive function calls
* **Recursion:** Direct implementation of mathematical formula
* **Base Cases:** Handled explicitly for n ≤ 2
* **Return Type:** Integer representing number of ways

## 📊 Example Walkthrough
For input: n = 4

1. climbStairs(4) calls climbStairs(3) + climbStairs(2)
2. climbStairs(3) calls climbStairs(2) + climbStairs(1)
   - climbStairs(2) returns 2
   - climbStairs(1) returns 1
   - climbStairs(3) = 2 + 1 = 3
3. climbStairs(2) returns 2
4. climbStairs(4) = 3 + 2 = 5

Final result: 5 ways

## 🚀 Advantages of Simple Recursive Approach
* **Simplicity:** Easy to understand and implement
* **Mathematical:** Directly follows the problem's mathematical structure
* **Educational:** Great for learning recursion concepts
* **Clear Logic:** Each recursive call represents a valid choice

## ⚠️ Limitations
* **Performance:** Exponential time complexity makes it slow for large n
* **Stack Overflow:** May cause issues with very large values
* **Redundant Calculations:** Same subproblems are calculated multiple times

## 🔄 When to Use
* **Learning:** Understanding recursion and problem structure
* **Small Inputs:** When n is small (≤ 20)
* **Prototyping:** Quick implementation for testing ideas
* **Educational:** Teaching recursive problem-solving

## 📈 Performance Characteristics
* **Small n (≤ 10):** Fast enough for practical use
* **Medium n (11-20):** Noticeable delay but manageable
* **Large n (> 20):** Too slow for practical applications

## 🎓 Learning Outcomes
* Understanding of recursive problem-solving
* Recognition of Fibonacci patterns in problems
* Base case handling in recursion
* Mathematical modeling of real-world problems
* Trade-offs between simplicity and performance
