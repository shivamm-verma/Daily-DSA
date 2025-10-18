class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def flatten(root):
    """
    Flattens the binary tree into a linked list in-place (preorder order).
    """
    if not root:
        return

    # Use a stack to do preorder traversal
    stack = [root]

    while stack:
        current = stack.pop()

        # Push right first so left is processed first
        if current.right:
            stack.append(current.right)
        if current.left:
            stack.append(current.left)

        # Connect current node to next node in preorder
        if stack:
            current.right = stack[-1]

        current.left = None  # set left child to None


# Helper function to print flattened tree
def printFlattened(root):
    while root:
        print(root.val, end=" -> " if root.right else "")
        root = root.right
    print()


# Driver code
if __name__ == "__main__":
    # Create the tree:
    #         1
    #        / \
    #       2   5
    #      / \   \
    #     3   4   6
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(6)

    print("Before Flattening:")
    print("Tree structure is now flattened below:")
    flatten(root)

    print("\nFlattened Linked List:")
    printFlattened(root)