class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def merge(l1, l2):
    dummy = Node(-1)
    tail = dummy
    while l1 and l2:
        if l1.data < l2.data:
            tail.next = l1
            l1 = l1.next
        else:
            tail.next = l2
            l2 = l2.next
        tail = tail.next
    tail.next = l1 if l1 else l2
    return dummy.next

def sortLL(head):
    if not head or not head.next:
        return head

    # Find middle
    slow, fast = head, head.next
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    mid = slow.next
    slow.next = None

    left = sortLL(head)
    right = sortLL(mid)

    return merge(left, right)

"""
Time Complexity: O(N log N)
Space Complexity: O(log N) (recursion stack)
"""
