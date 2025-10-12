class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
        this.val = 0;
        this.left = null;
        this.right = null;
    }

    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class FlattenBinaryTree {

    // Function to flatten the tree into linked list (preorder)
    public static void flatten(TreeNode root) {
        if (root == null) return;

        java.util.Stack<TreeNode> stack = new java.util.Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode current = stack.pop();

            // Push right child first (so left is processed first)
            if (current.right != null)
                stack.push(current.right);

            if (current.left != null)
                stack.push(current.left);

            // Connect current node to next node in preorder
            if (!stack.isEmpty())
                current.right = stack.peek();

            current.left = null; // Set left child to null
        }
    }

    // Helper function to print the flattened tree
    public static void printFlattened(TreeNode root) {
        TreeNode curr = root;
        while (curr != null) {
            System.out.print(curr.val);
            if (curr.right != null)
                System.out.print(" -> ");
            curr = curr.right;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Construct the tree:
        //         1
        //        / \
        //       2   5
        //      / \   \
        //     3   4   6

        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(5);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.right = new TreeNode(6);

        System.out.println("Before Flattening (Tree created)");

        flatten(root);

        System.out.println("\nFlattened Linked List:");
        printFlattened(root);
    }
}
