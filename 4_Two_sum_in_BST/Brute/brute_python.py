from collections import deque

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

def find_target(root, k):
    if not root:
        return False

    queue = deque([root])
    values = []

    # Level-order traversal
    while queue:
        node = queue.popleft()
        values.append(node.val)
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

    values.sort()
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
    print("Enter values for BST (press Ctrl+D or Ctrl+Z to end):")

    root = None
    try:
        while True:
            val = input()
            if not val.strip():
                break
            root = insert_bst(root, int(val))
    except EOFError:
        pass

    if find_target(root, k):
        print("True: A pair exists with the given sum.")
    else:
        print("False: No such pair exists.")
