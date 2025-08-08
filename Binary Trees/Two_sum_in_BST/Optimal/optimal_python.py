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

def hash_find(root, k, seen):
    if not root:
        return False
    if (k - root.val) in seen:
        return True
    seen.add(root.val)
    return hash_find(root.left, k, seen) or hash_find(root.right, k, seen)

def find_target(root, k):
    return hash_find(root, k, set())

if __name__ == "__main__":
    k = int(input("Enter target sum k: "))
    print("Enter values for BST (press Ctrl+D or Ctrl+Z to end):")

    root = None
    try:
        while True:
            n = input()
            if not n.strip():
                break
            val = int(n)
            root = insert_bst(root, val)
    except EOFError:
        pass

    if find_target(root, k):
        print("True: A pair exists with the given sum.")
    else:
        print("False: No such pair exists.")
