from typing import Optional

# Node definition
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        if head is None or head.next is None:
            print("Single node or empty list — palindrome by default.")
            return True

        slow = head
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            
        prev = None
        curr = slow
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt

        # Step 3: Compare first and second halves
        first = head
        second = prev
        while second and first:
            # Debug print
            print(f"Comparing {first.val} and {second.val}")

            if first.val != second.val:
                print("Mismatch found — Not a palindrome.")
                return False

            first = first.next
            second = second.next

        print("All matched — Palindrome confirmed.")
        return True


# --- MAIN FUNCTION ---
def main():
    # ✅ Example 1: Palindrome list
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(1)

    sol = Solution()
    print("Testing linked list: 1 -> 2 -> 2 -> 1")
    print("Result:", sol.isPalindrome(head))

    # ✅ Example 2: Not a palindrome
    head2 = ListNode(1)
    head2.next = ListNode(2)
    head2.next.next = ListNode(3)

    print("\nTesting linked list: 1 -> 2 -> 3")
    print("Result:", sol.isPalindrome(head2))


if __name__ == "__main__":
    main()
