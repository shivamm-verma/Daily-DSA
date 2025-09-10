class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

# Function to insert node at the end
def insertNode(head, val):
    newNode = Node(val)
    if not head:
        return newNode
    temp = head
    while temp.next:
        temp = temp.next
    temp.next = newNode
    return head

# Function to print the list
def printList(head):
    while head:
        print(head.val, end="")
        if head.next:
            print("->", end="")
        head = head.next
    print()

# Brute force rotation
def rotateRight(head, k):
    if not head or not head.next:
        return head

    for _ in range(k):
        temp = head
        while temp.next.next:
            temp = temp.next
        end = temp.next
        temp.next = None
        end.next = head
        head = end
    return head

# Driver code
head = None
head = insertNode(head, 1)
head = insertNode(head, 2)
head = insertNode(head, 3)
head = insertNode(head, 4)
head = insertNode(head, 5)

print("Original List:", end=" ")
printList(head)

k = 2
head = rotateRight(head, k)

print(f"After {k} rotations:", end=" ")
printList(head)

"""
Time Complexity: O(n * k)   (n = number of nodes)
Space Complexity: O(1)
"""
