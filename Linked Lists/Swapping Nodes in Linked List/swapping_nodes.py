class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def swapNodes(head, k):
    if head is None:
        return head

    # Count total nodes
    counter = 0
    temp = head
    while temp is not None:
        counter += 1
        temp = temp.next

    l = counter - k
    temp = head
    temp1 = head

    # Move temp to kth node from start
    while k > 1:
        k -= 1
        temp = temp.next

    # Move temp1 to kth node from end
    while l > 0:
        l -= 1
        temp1 = temp1.next

    # Swap the values
    temp.val, temp1.val = temp1.val, temp.val

    return head


# Helper function to print the linked list
def printList(head):
    temp = head
    while temp:
        print(temp.val, end=" ")
        temp = temp.next
    print()


# Driver code
if __name__ == "__main__":
    # Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print("Original List:")
    printList(head)

    # Swap kth nodes
    result = swapNodes(head, 2)

    print("Swapped List:")
    printList(result)
