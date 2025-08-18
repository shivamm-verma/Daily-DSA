## Lowest Common Ancestor in Binary Search Tree — Approaches Explained

### Problem Statement
Given a binary search tree (BST) and two nodes `p` and `q`, find their lowest common ancestor (LCA). The LCA is defined as the lowest node in the tree that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).

**Note**: All node values are unique, and both `p` and `q` exist in the BST.

### 📘 Example

#### Input
```text
BST Structure:
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

p = 2, q = 4
Output: 2 (since 2 is an ancestor of 4, and 2 is the lowest such node)
```

#### Visual Diagram
```text
        6
       / \
     [2]  8    ← LCA is node 2
     / \ / \
    0 [4] 7  9  ← p=2, q=4
      / \
     3   5
```

**Key Insight**: In a BST, the LCA is the first node where paths to `p` and `q` diverge, or one of the target nodes itself.

---

### 1️⃣ Brute Force Approach (Generic Tree LCA)

#### Idea
- Treat the BST as a regular binary tree (ignore BST properties).
- Recursively search for both nodes in left and right subtrees.
- If both nodes are found in different subtrees, current node is LCA.
- If both are in same subtree, recurse into that subtree.

#### Why Brute Force?
- Ignores the BST property completely
- Searches both subtrees even when unnecessary
- Works for any binary tree but inefficient for BST

#### Complexity
- Time: O(n) - may visit all nodes
- Space: O(h) - recursion stack height

---

### 2️⃣ Better Approach (Path Storage + Comparison)

#### Idea
- Find the path from root to `p` and store it.
- Find the path from root to `q` and store it.
- Compare both paths and find the last common node.
- This node is the LCA.

#### Advantage
- Uses BST property to find paths efficiently
- Clear separation of path finding and comparison
- Easy to understand and debug

#### Complexity
- Time: O(log n) for path finding + O(log n) for comparison = O(log n)
- Space: O(log n) for storing paths

---

### 3️⃣ Optimal Approach (BST Property Exploitation)

#### Idea
- Use the BST property: left subtree < root < right subtree.
- If both `p` and `q` are smaller than current node, LCA must be in left subtree.
- If both `p` and `q` are larger than current node, LCA must be in right subtree.
- If `p` and `q` are on different sides (or one equals current), current node is LCA.

#### Why Optimal?
- **Single Pass**: Only one traversal needed
- **Space Efficient**: O(1) space complexity (iterative) or O(h) (recursive)
- **BST Optimized**: Leverages BST properties perfectly
- **Elegant Logic**: Simple comparison-based decision making

#### Key Insight
The LCA is the first node encountered where the paths to `p` and `q` diverge.

#### Complexity
- Time: O(log n) average, O(h) worst case
- Space: O(1) iterative, O(h) recursive

---

### 🔍 Algorithm Walkthrough (Optimal Approach)

For the BST with `p = 2`, `q = 4`:

| Step | Current Node | p.val vs root | q.val vs root | Decision | Action |
|------|-------------|---------------|---------------|----------|--------|
| 1 | 6 | 2 < 6 | 4 < 6 | Both smaller | Go left |
| 2 | 2 | 2 = 2 | 4 > 2 | Split point | Return 2 |

For `p = 2`, `q = 8`:

| Step | Current Node | p.val vs root | q.val vs root | Decision | Action |
|------|-------------|---------------|---------------|----------|--------|
| 1 | 6 | 2 < 6 | 8 > 6 | Split point | Return 6 |

---


### 🎯 Key Takeaways

1. **BST Property is Crucial**: The ordered nature of BST makes LCA finding much more efficient than in a general binary tree.

2. **Three Decision Cases**: 
   - Both nodes in left subtree → go left
   - Both nodes in right subtree → go right  
   - Nodes split or current node matches → found LCA

3. **Space vs Readability Trade-off**: Iterative version uses O(1) space but recursive version is more readable.

4. **Edge Cases**: Handle cases where one node is ancestor of another (LCA is the ancestor node itself).

---

### 🔧 Test Cases

```text
Test Case 1: p=2, q=8 → LCA=6 (root)
Test Case 2: p=2, q=4 → LCA=2 (ancestor case)  
Test Case 3: p=3, q=5 → LCA=4 (deeper LCA)
Test Case 4: p=0, q=9 → LCA=6 (maximum distance)
```

The optimal BST-specific approach provides the best balance of efficiency and simplicity for this problem.