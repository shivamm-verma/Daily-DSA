import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        List<Integer> values = new ArrayList<>();
        for (ListNode node : lists) {
            while (node != null) {
                values.add(node.val);
                node = node.next;
            }
        }
        if (values.isEmpty()) return null;

        Collections.sort(values);

        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;

        for (int val : values) {
            temp.next = new ListNode(val);
            temp = temp.next;
        }
        return dummy.next;
    }
}

public class MergeKSortedListsBruteForce {
    public static ListNode createList(int[] arr) {
        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;
        for (int num : arr) {
            temp.next = new ListNode(num);
            temp = temp.next;
        }
        return dummy.next;
    }
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] list1 = {1, 4, 5};
        int[] list2 = {1, 3, 4};
        int[] list3 = {2, 6};
        ListNode l1 = createList(list1);
        ListNode l2 = createList(list2);
        ListNode l3 = createList(list3);
        ListNode[] lists = {l1, l2, l3};
        Solution sol = new Solution();
        ListNode merged = sol.mergeKLists(lists);
        System.out.print("Merged Linked List: ");
        printList(merged);
    }
}
