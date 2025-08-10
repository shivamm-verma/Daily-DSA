## 🔢 All Subsets Problem — Recursion and Backtracking Approach Explained

## 📘 Problem Statement
Given an array of integers, find all possible subsets (the power set). The solution set must not contain duplicate subsets.

**Note:** This problem demonstrates the efficient use of recursion and backtracking to generate all possible combinations.

## 🧪 Example
Input: [1, 2, 3]
Output: [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]

Input: [1, 2]
Output: [[], [1], [2], [1, 2]]

Input: [1]
Output: [[], [1]]

## 1️⃣ Recursion and Backtracking Approach
## 💡 Idea
* Use recursion to explore all possible combinations
* At each step, we have two choices: include the current element or exclude it
* Use backtracking to undo our choice and try the other option
* Build the result incrementally by adding each valid subset

## ⚙️ Complexity
 >Time: O(2^n) - Each element has 2 choices (include/exclude)

 >Space: O(n) - Recursion stack depth + O(2^n) for storing all subsets

## 🔍 Key Insights
* **Power Set:** A set with n elements has 2^n subsets
* **Recursive Structure:** Each subset can be built by choosing to include or exclude each element
* **Backtracking:** After exploring one choice, we undo it and try the other
* **State Management:** Keep track of current subset being built
* **Index Tracking:** Use index to avoid duplicate combinations
* **Base Case:** When we've processed all elements

## 📝 Algorithm Steps
1. Start with an empty subset and index 0
2. Add current subset to result (including empty subset)
3. For each element from current index to end:
   - Include the element in current subset
   - Recursively find subsets with remaining elements
   - Remove the element (backtrack)
4. Return all collected subsets

## 🎯 Edge Cases Handled
* Empty array (returns [[]])
* Single element array (returns [[], [element]])
* Duplicate elements (handled by index-based approach)
* Large arrays (exponential time complexity)
* Negative numbers (works correctly)

## 🔧 Implementation Details
* **Java:** Uses `ArrayList` for dynamic subset building, `List<List<Integer>>` for result
* **C++:** Uses `vector<int>` for current subset, `vector<vector<int>>` for result
* **Backtracking:** Add element, recurse, remove element
* **Index Management:** Pass index to avoid duplicate combinations
* **Result Collection:** Add each valid subset to result list

## 📊 Example Walkthrough
For input: [1, 2, 3]

1. Start with empty subset [], index 0
2. Add [] to result
3. Include 1: [1], recurse with index 1
   - Add [1] to result
   - Include 2: [1, 2], recurse with index 2
     - Add [1, 2] to result
     - Include 3: [1, 2, 3], recurse with index 3
       - Add [1, 2, 3] to result
       - Backtrack: [1, 2]
     - Backtrack: [1]
   - Include 3: [1, 3], recurse with index 3
     - Add [1, 3] to result
     - Backtrack: [1]
   - Backtrack: []
4. Include 2: [2], recurse with index 2
   - Add [2] to result
   - Include 3: [2, 3], recurse with index 3
     - Add [2, 3] to result
     - Backtrack: [2]
   - Backtrack: []
5. Include 3: [3], recurse with index 3
   - Add [3] to result
   - Backtrack: []

Final result: [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]

## 🚀 Advantages of Recursion and Backtracking Approach
* **Completeness:** Generates all possible subsets
* **Simplicity:** Clear recursive structure
* **Memory Efficient:** Reuses same data structures
* **Educational:** Demonstrates backtracking concept
* **Systematic:** Explores all combinations systematically

## 🔄 Alternative Approaches
* **Bit Manipulation:** Use binary representation (1 = include, 0 = exclude)
* **Iterative:** Use nested loops with bit manipulation
* **Cascading:** Build subsets incrementally by adding each element
* **Lexicographic:** Generate subsets in lexicographic order

## 📈 Performance Comparison
* **Recursion & Backtracking:** O(2^n) time, O(n) space
* **Bit Manipulation:** O(2^n) time, O(1) space per subset
* **Cascading:** O(2^n) time, O(2^n) space
* **Iterative:** O(2^n) time, O(2^n) space

## 🎓 Learning Outcomes
* Understanding of recursion and backtracking
* Mastery of subset generation algorithms
* Efficient problem-solving techniques
* State management in recursive algorithms
* DSA fundamentals with practical implementation 