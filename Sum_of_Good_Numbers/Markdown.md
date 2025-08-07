## 🔢 Sum of Good Numbers Problem — Approach Explained

## 📘 Problem Statement
Given an array of integers `nums` and an integer `k`, a number is considered "good" if it is greater than all numbers within a distance of `k` from it (both left and right). Calculate the sum of all good numbers in the array.

**Definition:** A number at index `i` is "good" if:
- It is greater than all numbers at indices `[i-k, i-1]` (if they exist)
- It is greater than all numbers at indices `[i+1, i+k]` (if they exist)

## 🧪 Example
Input:
    nums = [1, 3, 2, 4, 5, 2, 1]
    k = 2

Output:
    Sum of good numbers: 9

## Explanation: 
    Index 0 (1): Not good (no left neighbors, but 1 < 3)
    Index 1 (3): Good (3 > 1, and 3 > 2)
    Index 2 (2): Not good (2 < 3, and 2 < 4)
    Index 3 (4): Good (4 > 3, 4 > 2, and 4 > 5)
    Index 4 (5): Good (5 > 2, 5 > 4, and 5 > 2)
    Index 5 (2): Not good (2 < 5, and 2 < 1)
    Index 6 (1): Not good (1 < 2, and no right neighbors)
    
    Good numbers: 3, 4, 5
    Sum: 3 + 4 + 5 = 12

## 1️⃣ Optimal Single-Pass Approach
## 💡 Idea
* Traverse the array once and check each element against its k-distance neighbors.

* For each element at index i:
  - Check if it's greater than all elements in range [i-k, i-1] (left neighbors)
  - Check if it's greater than all elements in range [i+1, i+k] (right neighbors)
  - If both conditions are satisfied, add the element to the sum.

* Use boundary conditions to handle edge cases where neighbors don't exist.

## ⚙️ Complexity
 >Time: O(n × k) - For each element, we check up to 2k neighbors

 >Space: O(1) - Only using a single variable to store the sum

## 🔍 Key Insights
* **Boundary Handling:** Elements at the beginning and end of the array have fewer neighbors
* **Comparison Logic:** An element is good if it's greater than ALL neighbors within distance k
* **Edge Cases:** Elements with no left or right neighbors within distance k are still considered
* **Efficiency:** Each element needs to be compared with up to 2k neighbors

## 📝 Algorithm Steps
1. Initialize sum = 0
2. For each index i in the array:
   - Check if element is greater than all left neighbors within distance k
   - Check if element is greater than all right neighbors within distance k
   - If both conditions are true, add element to sum
3. Return sum

## 🎯 Edge Cases Handled
* Empty array
* Array with single element
* k = 0 (no neighbors to compare)
* k >= array length (no valid neighbors)
* Elements at boundaries (fewer neighbors to compare)
* Duplicate elements in the array

## 💭 Alternative Approaches
* **Brute Force:** For each element, check all neighbors within distance k (current approach)
* **Optimized:** Could use sliding window or prefix/suffix arrays for better performance in some cases
* **Space-Time Trade-off:** Could precompute maximum values in k-distance windows 