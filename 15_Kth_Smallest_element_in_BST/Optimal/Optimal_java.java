class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

public class Main {

    static void solve(Node root, int[] cnt, int[] ans, int k) {
        if (root == null) return;
        
        solve(root.left, cnt, ans, k);

        cnt[0]++;
        if (cnt[0] == k) {
            ans[0] = root.data;
            return;
        }

        solve(root.right, cnt, ans, k);
    }

    static int kthSmallest(Node root, int k) {
        int[] cnt = {0};
        int[] ans = {-1};
        solve(root, cnt, ans, k);
        return ans[0];
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
