class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def solve(root, cnt, ans, k):
    if root is None:
        return
    
    solve(root.left, cnt, ans, k)
    
    cnt[0] += 1
    if cnt[0] == k:
        ans[0] = root.data
        return
    
    solve(root.right, cnt, ans, k)

def kthSmallest(root, k):
    cnt = [0]
    ans = [-1]
    solve(root, cnt, ans, k)
    return ans[0]

root = Node(5)
root.left = Node(3)
root.right = Node(8)
root.left.left = Node(2)
root.left.right = Node(4)
root.right.left = Node(7)
root.right.right = Node(9)

k = 3
print(f"The {k} smallest element in the BST is: {kthSmallest(root, k)}")
