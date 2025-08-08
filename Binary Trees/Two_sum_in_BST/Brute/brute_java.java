import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
    }
}

public class BSTTargetSum {

    public static void insertBST(TreeNode root, int val) {
        if (val < root.val) {
            if (root.left == null) root.left = new TreeNode(val);
            else insertBST(root.left, val);
        } else {
            if (root.right == null) root.right = new TreeNode(val);
            else insertBST(root.right, val);
        }
    }

    public static boolean findTarget(TreeNode root, int k) {
        if (root == null) return false;

        Queue<TreeNode> q = new LinkedList<>();
        List<Integer> values = new ArrayList<>();
        q.add(root);

        // BFS to collect node values
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            values.add(node.val);
            if (node.left != null) q.add(node.left);
            if (node.right != null) q.add(node.right);
        }

        Collections.sort(values); // two-pointer
        int i = 0, j = values.size() - 1;
        while (i < j) {
            int sum = values.get(i) + values.get(j);
            if (sum == k) return true;
            else if (sum < k) i++;
            else j--;
        }
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter target sum k: ");
        int k = sc.nextInt();

        System.out.println("Enter values for BST (type non-integer to stop):");
        TreeNode root = null;
        while (sc.hasNextInt()) {
            int val = sc.nextInt();
            if (root == null) root = new TreeNode(val);
            else insertBST(root, val);
        }

        if (findTarget(root, k))
            System.out.println("True: A pair exists with the given sum.");
        else
            System.out.println("False: No such pair exists.");
    }
}
