class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def preorder(root, arr):
    if root is None:
        return
    arr.append(root.data)
    preorder(root.left, arr)
    preorder(root.right, arr)

def kthSmallest(root, k):
    arr = []
    preorder(root, arr)
    arr.sort()
    return arr[k - 1]

# Build the BST
root = Node(5)
root.left = Node(3)
root.right = Node(8)
root.left.left = Node(2)
root.left.right = Node(4)
root.right.left = Node(7)
root.right.right = Node(9)

k = 3
print(f"The {k} smallest element in the BST is: {kthSmallest(root, k)}")
