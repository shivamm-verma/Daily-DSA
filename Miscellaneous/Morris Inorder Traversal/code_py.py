class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def morris_inorder(root):
    curr = root
    while curr:
        if not curr.left:
            print(curr.data, end=" ")
            curr = curr.right
        else:
            pred = curr.left
            while pred.right and pred.right != curr:
                pred = pred.right
            if not pred.right:
                pred.right = curr
                curr = curr.left
            else:
                pred.right = None
                print(curr.data, end=" ")
                curr = curr.right

# Example usage
root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print("Morris Inorder Traversal:", end=" ")
morris_inorder(root)
