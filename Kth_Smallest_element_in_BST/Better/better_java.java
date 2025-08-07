import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

public class KthSmallestInBST {

    static void inorder(Node root, List<Integer> arr) {
        if (root == null) return;
        inorder(root.left, arr);
        arr.add(root.data);
        inorder(root.right, arr);
    }

    static int kthSmallest(Node root, int k) {
        List<Integer> arr = new ArrayList<>();
        inorder(root, arr);
        return arr.get(k - 1);
    }

    public static void main(String[] args) {
        Node root = new Node(5);
        root.left = new Node(3);
        root.right = new Node(8);
        root.left.left = new Node(2);
        root.left.right = new Node(4);
        root.right.left = new Node(7);
        root.right.right = new Node(9);

        int k = 3;
        System.out.println("The " + k + " smallest element in the BST is: " + kthSmallest(root, k));
    }
}
