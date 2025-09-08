import java.util.*;

class Node {
    int data;
    Node next;
    Node(int d) {
        data = d;
        next = null;
    }
}

class BruteForce {
    public static Node sortLL(Node head) {
        ArrayList<Integer> arr = new ArrayList<>();
        Node temp = head;

        // Store values in array
        while (temp != null) {
            arr.add(temp.data);
            temp = temp.next;
        }

        // Sort array
        Collections.sort(arr);

        // Reassign values back to linked list
        temp = head;
        for (int val : arr) {
            temp.data = val;
            temp = temp.next;
        }

        return head;
    }
}

/*
Time Complexity: O(N log N) 
Space Complexity: O(N)
*/

