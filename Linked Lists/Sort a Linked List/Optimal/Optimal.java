class Node {
    int data;
    Node next;
    Node(int d) {
        data = d;
        next = null;
    }
}

class Optimal {
    // Merge two sorted lists
    Node merge(Node l1, Node l2) {
        Node dummy = new Node(-1);
        Node tail = dummy;

        while (l1 != null && l2 != null) {
            if (l1.data < l2.data) {
                tail.next = l1;
                l1 = l1.next;
            } else {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }

        tail.next = (l1 != null) ? l1 : l2;
        return dummy.next;
    }

    // Merge Sort
    Node sortLL(Node head) {
        if (head == null || head.next == null) return head;

        Node slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        Node mid = slow.next;
        slow.next = null;

        Node left = sortLL(head);
        Node right = sortLL(mid);

        return merge(left, right);
    }
}

/*
Time Complexity: O(N log N)
Space Complexity: O(log N) (due to recursion stack)
*/

