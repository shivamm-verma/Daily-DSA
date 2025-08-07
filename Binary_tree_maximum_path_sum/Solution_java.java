class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
    }
}

public class MaxPathSum {
    private static int maxPath(TreeNode root, int[] maxi) {
        if (root == null) return 0;

        int left = Math.max(0, maxPath(root.left, maxi));
        int right = Math.max(0, maxPath(root.right, maxi));
        maxi[0] = Math.max(maxi[0], root.val + left + right);
        return root.val + Math.max(left, right);
    }

    public static int maxPathSum(TreeNode root) {
        int[] maxi = new int[]{Integer.MIN_VALUE};
        maxPath(root, maxi);
        return maxi[0];
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        int result = maxPathSum(root);
        System.out.println("Maximum path sum: " + result);  // Output: 11
    }
}
