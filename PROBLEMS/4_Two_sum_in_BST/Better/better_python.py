class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert_bst(root, val):
    if not root:
        return TreeNode(val)
    if val < root.val:
        root.left = insert_bst(root.left, val)
    else:
        root.right = insert_bst(root.right, val)
    return root

def inorder(root, values):
    if not root:
        return
    inorder(root.left, values)
    values.append(root.val)
    inorder(root.right, values)

def find_target(root, k):
    values = []
    inorder(root, values)
    i, j = 0, len(values) - 1
    while i < j:
        total = values[i] + values[j]
        if total == k:
            return True
        elif total < k:
            i += 1
        else:
            j -= 1
    return False

if __name__ == "__main__":
    k = int(input("Enter target sum k: "))
    print("Enter values for BST (Ctrl+D or Ctrl+Z to end):")
    root = None
    try:
        while True:
            line = input()
            if not line.strip(): break
            root = insert_bst(root, int(line))
    except EOFError:
        pass

    if find_target(root, k):
        print("True: A pair exists with the given sum.")
    else:
        print("False: No such pair exists.")
