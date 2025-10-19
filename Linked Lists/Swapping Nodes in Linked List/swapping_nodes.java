class ListNode {
    int val;
    ListNode next;

    ListNode() {
        this.val = 0;
        this.next = null;
    }

    ListNode(int val) {
        this.val = val;
        this.next = null;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class swapping_nodes {

    public static ListNode swapNodes(ListNode head, int k) {
        if (head == null) {
            return head;
        }

        // Count total nodes
        int counter = 0;
        ListNode temp = head;
        while (temp != null) {
            counter++;
            temp = temp.next;
        }

        int l = counter - k;
        temp = head;
        ListNode temp1 = head;

        // Move temp to kth node from start
        while (k > 1) {
            k--;
            temp = temp.next;
        }

        // Move temp1 to kth node from end
        while (l > 0) {
            l--;
            temp1 = temp1.next;
        }

        // Swap values
        int m = temp.val;
        temp.val = temp1.val;
        temp1.val = m;

        return head;
    }

    // Helper function to print the linked list
    public static void printList(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);

        System.out.println("Original List:");
        printList(head);

        // Swap kth nodes
        ListNode result = swapNodes(head, 2);

        System.out.println("Swapped List:");
        printList(result);
    }
}
