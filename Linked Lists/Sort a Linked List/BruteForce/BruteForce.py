class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def sortLL(head):
    arr = []
    temp = head

    # Store values
    while temp:
        arr.append(temp.data)
        temp = temp.next

    # Sort array
    arr.sort()

    # Reassign values
    temp = head
    for val in arr:
        temp.data = val
        temp = temp.next

    return head

"""
Time Complexity: O(N log N)
Space Complexity: O(N)
"""
