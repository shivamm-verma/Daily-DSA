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

    public static boolean hashFind(TreeNode root, int k, Set<Integer> seen) {
        if (root == null) return false;

        if (seen.contains(k - root.val)) return true;
        seen.add(root.val);

        return hashFind(root.left, k, seen) || hashFind(root.right, k, seen);
    }

    public static boolean findTarget(TreeNode root, int k) {
        Set<Integer> seen = new HashSet<>();
        return hashFind(root, k, seen);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter target sum k: ");
        int k = sc.nextInt();

        System.out.println("Enter values for BST (type non-integer to end):");

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
