from collections import defaultdict, deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def verticalOrder(root):
    if not root:
        return []

    col_map = defaultdict(list)
    q = deque([(root, 0)])  # (node, horizontal distance)

    while q:
        node, hd = q.popleft()
        col_map[hd].append(node.val)

        if node.left:
            q.append((node.left, hd - 1))
        if node.right:
            q.append((node.right, hd + 1))

    return [col_map[x] for x in sorted(col_map.keys())]

# Example usage
if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    print(verticalOrder(root))  # [[4], [2], [1, 5, 6], [3], [7]]
