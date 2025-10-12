# Flatten Binary Tree to Linked List

### Description
You are given the root of a binary tree.
Flatten the tree into a “linked list” in-place following the preorder traversal (Root → Left → Right).

After flattening,

- Each node’s right child points to the next node in preorder traversal.

- Each node’s left child is set to null.

**Example:**  
Input: 
        1
       / \
      2   5
     / \   \
    3   4   6

Output: 
1 -> 2 -> 3 -> 4 -> 5 -> 6


---

## Approach 1: Using Stack (Iterative Preorder)

**Concept:**

- Use a stack to perform a preorder traversal of the binary tree.
- Push the right subtree first and then the left subtree (so left is processed first).
- Set each node’s right pointer to the next node in preorder order.
- Set each node’s left pointer to null.

**Algorithm:**

1. Initialize a stack and push the root node.
2. While the stack is not empty:
- Pop the top node as current.
- If current.right exists, push it onto the stack.
- If current.left exists, push it onto the stack.
- If the stack is not empty, set current.right to the top of the stack.
- Set current.left = null.
3. The tree is now flattened.

**Complexity:**

- Time: `O(N)`  
- Space: `O(N)`

---

## Approach 2: Optimized (Morris Traversal - O(1) Space)

**Concept:**

- Traverse the tree using preorder traversal without extra space.
- For each node:
  - If it has a left subtree:
  - Find the rightmost node in its left subtree.
  - Connect that node’s right to the current node’s original right subtree.
  - Move the left subtree to the right and set left = null.
- Move to the next right node.

**Complexity:**

- Time: `O(N)`  
- Space: `O(1)` (no stack or recursion used)
