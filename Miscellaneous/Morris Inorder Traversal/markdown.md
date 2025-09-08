## ✅ DSA Question: Morris Inorder Traversal

---

### 🧠 Problem  
Traverse a binary tree in inorder sequence using O(1) extra space, without recursion or an explicit stack, by temporarily modifying tree links.

**Examples:**  
Input -        1
              / \
             2   3
            / \
           4   5
Output - 4 2 5 1 3

**Constraints:**  
- 1 <= Number of nodes <= 10^4
- -10^5 <= Node value <= 10^5

---

## 🧭 Approach 

- Initialize the current node as the root.
- While the current node is not nullptr:
- If the current node has no left child, print its value and move to its right child.
- If the current node has a left child:
- Find the inorder predecessor of the current node (rightmost node in the left subtree).
- If the predecessor’s right is nullptr, make the current node its right child (create a temporary thread), and move to the left child of the current node.
- If the predecessor’s right points to the current node, it means we have already visited the left subtree. Remove the thread, print the current node’s value, and move to its right child.
- Repeat until all nodes are visited.

---

## 🔁 Generic Logic (Pseudocode)
```plaintext
function morrisInorderTraversal(root):
    curr = root
    
    while curr is not null:
        if curr.left is null:
            print(curr.data)     // Visit node
            curr = curr.right
        else:
            // Find the inorder predecessor
            pred = curr.left
            while pred.right is not null AND pred.right != curr:
                pred = pred.right

            if pred.right is null:
                pred.right = curr   // Create temporary thread
                curr = curr.left
            else:
                pred.right = null   // Remove thread
                print(curr.data)    // Visit node
                curr = curr.right
```

## ⏱️ Complexities

 > Time Complexity
**O(n)** — Each edge is visited at most twice (once to create the thread, once to remove it).

> Space Complexity
**O(1)** — Only uses pointers, temporarily modifies the tree structure.
---

