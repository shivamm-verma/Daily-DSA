class Node {
    int val;
    Node next;
    Node(int a) {
        val = a;
        next = null;
    }
}

public class BruteForce {
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

    // Brute force rotation
    static Node rotateRight(Node head, int k) {
        if (head == null || head.next == null) return head;

        for (int i = 0; i < k; i++) {
            Node temp = head;
            while (temp.next.next != null) temp = temp.next;
            Node end = temp.next;
            temp.next = null;
            end.next = head;
            head = end;
        }
        return head;
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
Time Complexity: O(n * k)   (n = number of nodes)
Space Complexity: O(1)
*/

