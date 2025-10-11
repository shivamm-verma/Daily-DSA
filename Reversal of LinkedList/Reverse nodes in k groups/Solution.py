class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0, head)
        prev_group = dummy

        while True:
            kth = self.getKth(prev_group, k)
            if not kth:
                break
            group_next = kth.next

            prev, curr = group_next, prev_group.next
            while curr != group_next:
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp

            tmp = prev_group.next
            prev_group.next = kth
            prev_group = tmp

        return dummy.next

    def getKth(self, curr, k):
        while curr and k > 0:
            curr = curr.next
            k -= 1
        return curr
