# Construct Binary Tree from Preorder and Inorder Traversal

## Problem Statement

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.

**LeetCode:** [105. Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

### Constraints
- 1 <= preorder.length <= 3000  
- inorder.length == preorder.length  
- -3000 <= preorder[i], inorder[i] <= 3000  
- preorder and inorder consist of unique values.  
- Each value of inorder also appears in preorder.  
- preorder is guaranteed to be the preorder traversal of the tree.  
- inorder is guaranteed to be the inorder traversal of the tree.

---

## Intuition

1. In **preorder traversal**, the first element is always the root of the current subtree.
2. In **inorder traversal**, all elements to the left of the root belong to the left subtree and elements to the right belong to the right subtree.
3. Using a hashmap to store the index of each value in the inorder array allows O(1) lookup.
4. Recursively:
   - Take the next element in preorder as the root.
   - Find its position in inorder.
   - Build the left subtree using the left segment of inorder.
   - Build the right subtree using the right segment of inorder.

This approach ensures each node is constructed exactly once.

---

## Example Test Cases

### Example 1
Input:
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Output:
[3,9,20,null,null,15,7]

### Example 2
Input:
preorder = [-1]
inorder = [-1]

Output:
[-1]

## Similar Questions 
Construct BT from Preorder and Inorder
Construct BT from Postorder and Inorder
Maximum Binary Tree
Construct BST from Preorder