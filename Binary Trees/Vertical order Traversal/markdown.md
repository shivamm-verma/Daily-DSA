## ✅ DSA Question: Vertical Order Traversal of Binary Tree

---

### 🧠 Problem  
Given the root of a binary tree, return its **vertical order traversal**.  
Nodes in the same vertical line should appear from **top to bottom** and from **leftmost column to rightmost column**.

**Examples:**  
Input:
  1
  /\
 2  3
/ \ /\
4 5 6 7
Output: [[4], [2], [1, 5, 6], [3], [7]]

**Constraints:**  
- Number of nodes in tree ≤ 10^4  
- Node values are integers  

---

## 🧭 Approach 

1. Assign each node a **horizontal distance (HD)** from root:
   - Root = 0  
   - Left child = parent’s HD - 1  
   - Right child = parent’s HD + 1  

2. Use **Level Order Traversal (BFS)**:
   - Maintain a queue storing `(node, HD)`.  
   - Store nodes in a **map (HD → list of nodes)**.  

3. Traverse map from **smallest HD to largest HD** to collect vertical order.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function verticalOrder(root):
    if root is null: return []

    map = empty ordered map  # stores HD → list of nodes
    queue = [(root, 0)]

    while queue not empty:
        node, hd = queue.pop_front()
        map[hd].append(node.val)

        if node.left:
            queue.push((node.left, hd-1))
        if node.right:
            queue.push((node.right, hd+1))

    return map.values() in sorted HD order
```

## ⏱️ Complexities
 > Time Complexity
**O(N log N)** — N nodes, and TreeMap/map requires log N insertion.

> Space Complexity
**O(N)** — map + queue storage

---

