class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def find_path(root, target, path):
    if not root:
        return False
    path.append(root)
    if root == target:
        return True
    if target.val < root.val:
        if find_path(root.left, target, path):
            return True
    else:
        if find_path(root.right, target, path):
            return True
    path.pop()
    return False

def lca_better(root, p, q):
    path_p, path_q = [], []
    find_path(root, p, path_p)
    find_path(root, q, path_q)

    i = 0
    while i < len(path_p) and i < len(path_q) and path_p[i] == path_q[i]:
        i += 1
    return path_p[i - 1]

if __name__ == "__main__":
    root = TreeNode(6)
    root.left = TreeNode(2)
    root.right = TreeNode(8)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(4)
    root.left.right.left = TreeNode(3)
    root.left.right.right = TreeNode(5)
    root.right.left = TreeNode(7)
    root.right.right = TreeNode(9)

    p = root.left        # 2
    q = root.left.right  # 4

    lca = lca_better(root, p, q)
    print("Better Approach LCA:", lca.val)
