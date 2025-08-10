## Maximum Path Sum in Binary Tree — Approach Explained

### Problem Statement
Given the `root` of a Binary Tree, return the maximum path sum of any non-empty path. A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

### 📘 Example

#### Input
```text
Tree Elements: 1, 2, 3, 4, 5
Output: 11
```

#### Visual Diagram
```text
      1
     / \
    2   3
   / \
  4   5
```
**Maximum Path**: 4 → 2 → 5  
**Path Sum**: 4 + 2 + 5 = 11

---

### 🎯 Optimal Approach (Modified DFS with Bottom-Up Calculation)

#### Idea
- Use a single DFS traversal with bottom-up approach.
- For each node, calculate the maximum path sum that can be extended to its parent.
- At each node, update the global maximum with the path passing through it (connecting left and right subtrees).
- Return the maximum path sum that goes through the current node and extends in one direction only.

#### Key Algorithm Steps
1. **Base Case**: If node is null, return 0
2. **Calculate Left Contribution**: `left = max(0, maxPath(root.left))` (ignore negative paths)
3. **Calculate Right Contribution**: `right = max(0, maxPath(root.right))` (ignore negative paths)
4. **Update Global Maximum**: `maxSum = max(maxSum, root.val + left + right)` (path through current node)
5. **Return for Parent**: `return root.val + max(left, right)` (extend path upward)

#### Why Optimal?
- **Single Pass**: Only one DFS traversal needed
- **Space Efficient**: O(h) space complexity where h is height of tree
- **Handles Negative Values**: Uses `max(0, ...)` to ignore negative contributions
- **Global vs Local Tracking**: Maintains global maximum while returning optimal path for parent
- **Bottom-Up Optimization**: Leverages optimal substructure property

#### Complexity
- **Time Complexity**: O(n) - where n is the number of nodes in the tree
  - Each node is visited exactly once during the DFS traversal
  - At each node, we perform constant time operations
- **Space Complexity**: O(h) - where h is the height of the tree
  - Space is used for the recursion call stack
  - In worst case (skewed tree): O(n)
  - In best case (balanced tree): O(log n)

---

### ⏱️ Time and Space Complexity

#### Time Complexity: O(n)
- **n** = number of nodes in the binary tree
- Each node is visited exactly once during the DFS traversal
- At each node, we perform constant time operations:
  - Calculate left and right contributions: O(1)
  - Update global maximum: O(1) 
  - Return value calculation: O(1)
- Total time: O(n) × O(1) = O(n)

#### Space Complexity: O(h)
- **h** = height of the binary tree
- Space is primarily used for the recursion call stack
- Maximum depth of recursion equals the height of the tree
- **Best Case (Balanced Tree)**: O(log n)
  - Height of balanced binary tree is log₂(n)
- **Worst Case (Skewed Tree)**: O(n)
  - Height of completely skewed tree is n
- **Average Case**: O(log n) for reasonably balanced trees

---

### 🧠 Algorithm Walkthrough

#### Step-by-Step Execution for Example Tree
```text
      1
     / \
    2   3
   / \
  4   5
```

1. **Visit Node 4**: 
   - left = 0, right = 0
   - maxi = max(INT_MIN, 4 + 0 + 0) = 4
   - return 4 + max(0, 0) = 4

2. **Visit Node 5**: 
   - left = 0, right = 0
   - maxi = max(4, 5 + 0 + 0) = 5
   - return 5 + max(0, 0) = 5

3. **Visit Node 2**: 
   - left = 4, right = 5
   - maxi = max(5, 2 + 4 + 5) = 11
   - return 2 + max(4, 5) = 7

4. **Visit Node 3**: 
   - left = 0, right = 0
   - maxi = max(11, 3 + 0 + 0) = 11
   - return 3 + max(0, 0) = 3

5. **Visit Node 1**: 
   - left = 7, right = 3
   - maxi = max(11, 1 + 7 + 3) = 11
   - return 1 + max(7, 3) = 8

**Final Answer**: 11

---

### 🎯 Key Insights

#### Understanding the Two Calculations
1. **Global Maximum Update**: `maxi = max(maxi, root.val + left + right)`
   - Considers path that goes through current node connecting both subtrees
   - This path cannot be extended further up the tree

2. **Return Value**: `return root.val + max(left, right)`
   - Returns the maximum path that can be extended to the parent node
   - Can only go in one direction (either left or right subtree)

#### Critical Observations
- **Negative Path Handling**: `max(0, childPath)` ensures we ignore negative contributions
- **Bottom-Up Approach**: Calculate from leaves to root for optimal efficiency
- **Single Traversal**: Each node is visited exactly once
- **Path Flexibility**: Maximum path can be between any two nodes in the tree

---