class Node {
    int val;
    Node next;
    Node(int a) {
        val = a;
        next = null;
    }
}

public class Optimal {
    // Function to insert node at the end
    static Node insertNode(Node head, int val) {
        Node newNode = new Node(val);
        if (head == null) return newNode;
        Node temp = head;
        while (temp.next != null) temp = temp.next;
        temp.next = newNode;
        return head;
    }

    // Function to print the list
    static void printList(Node head) {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) System.out.print("->");
            head = head.next;
        }
        System.out.println();
    }

    // Optimal rotation
    static Node rotateRight(Node head, int k) {
        if (head == null || head.next == null || k == 0) return head;

        // Step 1: Find length and tail
        int length = 1;
        Node tail = head;
        while (tail.next != null) {
            tail = tail.next;
            length++;
        }

        // Step 2: Make it circular
        tail.next = head;

        // Step 3: Find new head
        k = k % length;
        int stepsToNewHead = length - k;
        Node newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail.next;
        }

        Node newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }

    public static void main(String[] args) {
        Node head = null;
        head = insertNode(head, 1);
        head = insertNode(head, 2);
        head = insertNode(head, 3);
        head = insertNode(head, 4);
        head = insertNode(head, 5);

        System.out.print("Original List: ");
        printList(head);

        int k = 2;
        head = rotateRight(head, k);

        System.out.print("After " + k + " rotations: ");
        printList(head);
    }
}

/*
Time Complexity: O(n)   (n = number of nodes)
Space Complexity: O(1)
*/
