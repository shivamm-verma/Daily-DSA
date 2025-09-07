class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head or not head.next or k == 0:
            return head

        # Find length
        n = 1
        tail = head
        while tail.next:
            tail = tail.next
            n += 1

        # Make it circular
        tail.next = head
        k = k % n
        steps_to_new_head = n - k

        # Move to new head
        new_tail = tail
        while steps_to_new_head > 0:
            new_tail = new_tail.next
            steps_to_new_head -= 1

        new_head = new_tail.next
        new_tail.next = None
        return new_head

"""
Time Complexity: O(N)
Space Complexity: O(1)
"""
