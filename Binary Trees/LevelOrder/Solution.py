# Python program to perform Level Order Traversal (BFS)
# ✅ LeetCode 102. Binary Tree Level Order Traversal

from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def levelOrder(root):
    result = []
    if not root:
        return result

    queue = deque([root])

    while queue:
        level_size = len(queue)
        level = []

        for _ in range(level_size):
            node = queue.popleft()
            level.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(level)

    return result

# ------------------ Main Test ------------------
if __name__ == "__main__":
    """
             3
            / \
           9  20
              /  \
             15   7
    """
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)

    traversal = levelOrder(root)
    print("Level Order Traversal:", traversal)

"""
---------------------- 🧪 Output ----------------------
Level Order Traversal: [[3], [9, 20], [15, 7]]

---------------------- ⏳ Complexity ----------------------
Time Complexity: O(n)
Space Complexity: O(n)
✅ Intuition:
- Use a queue to store nodes level by level
- For each level, process all nodes and add their children
- Collect values in a list of lists
-----------------------------------------------------------
"""
