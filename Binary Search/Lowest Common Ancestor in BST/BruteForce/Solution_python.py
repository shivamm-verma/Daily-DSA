class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def lca_brute_force(root, p, q):
    if not root or root == p or root == q:
        return root

    left_lca = lca_brute_force(root.left, p, q)
    right_lca = lca_brute_force(root.right, p, q)

    if left_lca and right_lca:
        return root
    return left_lca if left_lca else right_lca

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

    p = root.left         # 2
    q = root.left.right   # 4

    lca = lca_brute_force(root, p, q)
    print("Brute Force LCA:", lca.val)
