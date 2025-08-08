class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def max_path(root, maxi):
    if root is None:
        return 0
    left = max(0, max_path(root.left, maxi))
    right = max(0, max_path(root.right, maxi))
    maxi[0] = max(maxi[0], root.val + left + right)
    return root.val + max(left, right)

def maxPathSum(root):
    maxi = [float('-inf')]
    max_path(root, maxi)
    return maxi[0]

# Example usage
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

result = maxPathSum(root)
print("Maximum path sum:", result)  # Output: 11
