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

# Optimal rotation
def rotateRight(head, k):
    if not head or not head.next or k == 0:
        return head

    # Step 1: Find length and tail
    length = 1
    tail = head
    while tail.next:
        tail = tail.next
        length += 1

    # Step 2: Make it circular
    tail.next = head

    # Step 3: Find new head
    k = k % length
    stepsToNewHead = length - k
    newTail = head
    for _ in range(1, stepsToNewHead):
        newTail = newTail.next

    newHead = newTail.next
    newTail.next = None

    return newHead

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
Time Complexity: O(n)   (n = number of nodes)
Space Complexity: O(1)
"""
