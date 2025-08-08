class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def inorder(root, arr):
    if root is None:
        return
    inorder(root.left, arr)
    arr.append(root.data)
    inorder(root.right, arr)

def kthSmallest(root, k):
    arr = []
    inorder(root, arr)
    return arr[k - 1]

# Construct BST
root = Node(5)
root.left = Node(3)
root.right = Node(8)
root.left.left = Node(2)
root.left.right = Node(4)
root.right.left = Node(7)
root.right.right = Node(9)

k = 3
print(f"The {k} smallest element in the BST is: {kthSmallest(root, k)}")
