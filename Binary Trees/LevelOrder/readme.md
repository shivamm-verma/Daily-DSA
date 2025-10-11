# 🌿 Level Order Traversal (BFS) — Binary Tree

## 📝 Problem Statement
Given the `root` of a binary tree, return the **level order traversal** of its nodes' values.  
(i.e., from left to right, level by level).

---

## 🧠 Intuition
Level Order Traversal means visiting nodes **level by level** from top to bottom.  
We use a **queue** (FIFO) to keep track of nodes at each level:

1. Start by pushing the `root` into the queue.  
2. For each level:
   - Count the number of nodes currently in the queue (`levelSize`).
   - Pop each node, store its value in the current level list.
   - Push its children (if they exist) into the queue.
3. Append the level list to the result.
4. Repeat until the queue becomes empty.

This is a classic **BFS (Breadth First Search)** pattern for trees.

---

## ⏳ Complexity Analysis

| Parameter              | Complexity                 |
|-------------------------|----------------------------|
| **Time**               | O(n) — each node visited once |
| **Space**              | O(n) — queue stores nodes level by level |

---

## 🧪 Example

### Input
    3
   / \
  9  20
     /  \
    15   7

 ### Output
 [[3], [9, 20], [15, 7]]

## Similar Pattern Questions 
Zigzag Level order Traversal
Even Odd Tree
Reverse odd Levels
Deepest Leaves Sum
Add one row to Tree
Maximum width of Binary Tree
All Nodes Distance K in Binary tree