## 🏃‍♂️ Climbing Stairs Problem — Hard Dynamic Programming Solution

## 📘 Problem Statement
You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

**Note:** This is the hard solution using dynamic programming and space optimization, suitable for production use and large inputs.

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

Input: n = 45
Output: 1836311903
Explanation: Large input handled efficiently with DP

## 1️⃣ Dynamic Programming Approach
## 💡 Idea
* Use dynamic programming to avoid redundant calculations
* Build solution bottom-up using previously computed values
* Store intermediate results in an array for reuse
* Eliminate exponential time complexity of recursive approach

## 2️⃣ Space Optimized Approach
## 💡 Idea
* Further optimize space by using only three variables
* Track previous two values and current value
* Update variables iteratively without storing full array
* Achieve O(1) space complexity

## ⚙️ Complexity
 >Time: O(n) - Linear time to fill DP array or iterate

 >Space: O(n) for DP array, O(1) for optimized version

## 🔍 Key Insights
* **Fibonacci Pattern:** The solution follows Fibonacci sequence
* **Overlapping Subproblems:** Same calculations repeated in recursion
* **Optimal Substructure:** Solution can be built from smaller solutions
* **State Transition:** dp[i] = dp[i-1] + dp[i-2]
* **Space Optimization:** Only need last two values for next calculation

## 📝 Algorithm Steps
### Dynamic Programming:
1. Create DP array of size n+1
2. Set base cases: dp[1] = 1, dp[2] = 2
3. Fill array iteratively: dp[i] = dp[i-1] + dp[i-2]
4. Return dp[n]

### Space Optimized:
1. Initialize prev2 = 1, prev1 = 2
2. Iterate from 3 to n:
   - current = prev1 + prev2
   - prev2 = prev1
   - prev1 = current
3. Return prev1

## 🎯 Edge Cases Handled
* n = 0 (returns 0)
* n = 1 (returns 1)
* n = 2 (returns 2)
* Large values of n (handled efficiently)
* Negative values (not handled, assumes valid input)

## 🔧 Implementation Details
* **Java:** Uses `int[]` for DP, three variables for optimization
* **C++:** Uses `vector<int>` for DP, three variables for optimization
* **Dynamic Programming:** Bottom-up approach with array storage
* **Space Optimization:** Rolling variables to eliminate array storage
* **Input Validation:** Assumes positive integer input

## 📊 Example Walkthrough
For input: n = 5

### DP Approach:
1. dp[1] = 1, dp[2] = 2
2. dp[3] = dp[2] + dp[1] = 2 + 1 = 3
3. dp[4] = dp[3] + dp[2] = 3 + 2 = 5
4. dp[5] = dp[4] + dp[3] = 5 + 3 = 8

### Optimized Approach:
1. prev2 = 1, prev1 = 2
2. i = 3: current = 2 + 1 = 3, prev2 = 2, prev1 = 3
3. i = 4: current = 3 + 2 = 5, prev2 = 3, prev1 = 5
4. i = 5: current = 5 + 3 = 8, prev2 = 5, prev1 = 8

Final result: 8 ways

## 🚀 Advantages of Dynamic Programming Approach
* **Performance:** Linear time complexity O(n)
* **Efficiency:** No redundant calculations
* **Scalability:** Handles large inputs efficiently
* **Reliability:** No stack overflow issues
* **Production Ready:** Suitable for real-world applications

## 🚀 Advantages of Space Optimization
* **Memory Efficiency:** O(1) space complexity
* **Cache Friendly:** Better memory locality
* **Scalability:** Handles very large inputs without memory issues
* **Performance:** Slightly faster due to reduced memory access

## 🔄 When to Use
* **Large Inputs:** When n > 20
* **Production Code:** Real-world applications
* **Performance Critical:** When speed matters
* **Memory Constrained:** When space is limited (optimized version)

## 📈 Performance Comparison
* **Simple Recursion:** O(2^n) time, O(n) space
* **Dynamic Programming:** O(n) time, O(n) space
* **Space Optimized:** O(n) time, O(1) space

## 🎓 Learning Outcomes
* Understanding of dynamic programming concepts
* Recognition of overlapping subproblems
* Space-time complexity trade-offs
* Bottom-up vs top-down approaches
* Optimization techniques in algorithms

## 🔧 Advanced Concepts
* **Memoization:** Top-down approach with caching
* **Tabulation:** Bottom-up approach (implemented here)
* **State Compression:** Reducing space requirements
* **Matrix Exponentiation:** O(log n) solution for very large n
