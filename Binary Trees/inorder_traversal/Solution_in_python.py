# Python program to perform Inorder Traversal of a Binary Tree
# Includes both Recursive and Iterative approaches

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


# ------------------ 1️⃣ Recursive Approach ------------------
def inorder_recursive(root, result):
    """
    Perform inorder traversal recursively.
    Args:
        root (TreeNode): Root node of the binary tree.
        result (list): List to store traversal order.
    """
    # Base case: if current node is None, return
    if root is None:
        return

    # Step 1: Traverse left subtree
    inorder_recursive(root.left, result)

    # Step 2: Visit (process) current node
    result.append(root.val)

    # Step 3: Traverse right subtree
    inorder_recursive(root.right, result)


# ------------------ 2️⃣ Iterative Approach ------------------
def inorder_iterative(root):
    """
    Perform inorder traversal iteratively using a stack.
    Args:
        root (TreeNode): Root node of the binary tree.
    Returns:
        list: Inorder traversal as a list.
    """
    result = []
    stack = []
    current = root

    # While there are nodes to process
    while current or stack:
        # Reach the leftmost node of the current node
        while current:
            stack.append(current)
            current = current.left

        # Pop the top node from stack
        current = stack.pop()
        result.append(current.val)

        # Now, visit the right subtree
        current = current.right

    return result


# ------------------ Main Method to Test ------------------
if __name__ == "__main__":
    """
            4
           / \
          2   5
         / \
        1   3
    """
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)

    # Recursive approach
    recursive_result = []
    inorder_recursive(root, recursive_result)
    print("Recursive Inorder:", recursive_result)

    # Iterative approach
    iterative_result = inorder_iterative(root)
    print("Iterative Inorder:", iterative_result)


"""
---------------- Output ----------------
Recursive Inorder: [1, 2, 3, 4, 5]
Iterative Inorder: [1, 2, 3, 4, 5]

---------------- Complexity ----------------
Recursive:
    Time Complexity: O(n) - Each node is visited exactly once.
    Space Complexity: O(h) - Recursion stack, h is tree height (O(n) worst case).
Iterative:
    Time Complexity: O(n) - Each node pushed and popped from stack once.
    Space Complexity: O(h) - Stack holds at most h nodes at a time.
--------------------------------------------
"""
