import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
    }
}

public class BSTTargetSumInorder {

    public static TreeNode insertBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        if (val < root.val) root.left = insertBST(root.left, val);
        else root.right = insertBST(root.right, val);
        return root;
    }

    public static void inorder(TreeNode root, List<Integer> values) {
        if (root == null) return;
        inorder(root.left, values);
        values.add(root.val);
        inorder(root.right, values);
    }

    public static boolean findTarget(TreeNode root, int k) {
        List<Integer> values = new ArrayList<>();
        inorder(root, values);

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
            root = insertBST(root, val);
        }

        if (findTarget(root, k))
            System.out.println("True: A pair exists with the given sum.");
        else
            System.out.println("False: No such pair exists.");
    }
}
