# Inorder Traversal of Binary Tree — Approaches Explained

### Problem Statement
Given the `root` of a binary tree, return the inorder traversal of its nodes' values.

Inorder traversal means:
1. Visit the left subtree.
2. Visit the current node.
3. Visit the right subtree.

---

## 📘 Example

### Input
```text
Binary Tree: 1, null, 2, 3
```

## Visual Diagram
```
    1
     \
      2
     /
    3
```
Inorder traversal: [1, 3, 2]

## 1️⃣ Recursive Approach (Direct Definition)
Idea

Follow the standard recursive definition of inorder traversal:
- Recursively traverse the left subtree.
- Process (visit) the current node.
- Recursively traverse the right subtree.

### Why Simple?

- Directly matches the mathematical definition of inorder traversal.
- Easy to implement and understand.

## Complexity

- Time: O(n) — each node visited exactly once.
- Space: O(h) — recursion stack, where h is the height of the tree (O(n) in worst case for skewed tree).


## 2️⃣ Iterative Approach (Using Stack)
Idea

Simulate recursion manually using a stack:
- Start with the root node.
- Push all left children to the stack until reaching null.
- Pop from stack, visit the node, and move to its right child.
- Repeat until both stack is empty and current node is null.

### Advantage

- Avoids recursive calls (no risk of stack overflow in very deep trees).
- Still follows the inorder sequence.

## Complexity

- Time: O(n) — each node pushed and popped once.
- Space: O(h) — stack holds at most h nodes at a time.

## 📊 Comparison Summary

| Approach      | Time Complexity | Space Complexity | Pros                                       | Cons                                  |
| ------------- | --------------- | ---------------- | ------------------------------------------ | ------------------------------------- |
| **Recursive** | O(n)            | O(h)             | Very simple, matches definition            | Recursion depth limit in skewed trees |
| **Iterative** | O(n)            | O(h)             | No recursion depth limit, explicit control | Slightly more verbose code            |

