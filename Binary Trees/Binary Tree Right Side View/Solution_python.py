from collections import deque
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def rightSideView(root: Optional[TreeNode]) -> List[int]:
    if not root:
        return []
    
    res = []
    q = deque([root])

    while q:
        size = len(q)
        level = []
        for _ in range(size):
            node = q.popleft()
            if node.right:
                q.append(node.right)
            if node.left:
                q.append(node.left)
            level.append(node.val)
        res.append(level[0])  # rightmost at this level
    
    return res


# Example usage
if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(5)

    result = rightSideView(root)
    print(result)  # Output: [1, 3, 5]
