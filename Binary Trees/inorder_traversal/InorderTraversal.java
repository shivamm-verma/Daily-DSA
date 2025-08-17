// Java program to perform Inorder Traversal of a Binary Tree
// Includes both Recursive and Iterative approaches

import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

public class InorderTraversal {

    // ------------------ 1️⃣ Recursive Approach ------------------
    public static void inorderRecursive(TreeNode root, List<Integer> result) {
        // Base case: if the current node is null, return
        if (root == null) return;

        // Step 1: Traverse left subtree
        inorderRecursive(root.left, result);

        // Step 2: Visit (process) current node
        result.add(root.val);

        // Step 3: Traverse right subtree
        inorderRecursive(root.right, result);
    }

    // ------------------ 2️⃣ Iterative Approach ------------------
    public static List<Integer> inorderIterative(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        Stack<TreeNode> stack = new Stack<>();
        TreeNode current = root;

        // While there are nodes to process
        while (current != null || !stack.isEmpty()) {
            // Reach the leftmost node of the current node
            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            // Pop the top node from stack
            current = stack.pop();
            result.add(current.val);

            // Now, visit the right subtree
            current = current.right;
        }

        return result;
    }

    // ------------------ Main Method to Test ------------------
    public static void main(String[] args) {
        /*
                4
               / \
              2   5
             / \
            1   3
        */
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(5);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);

        // Recursive approach
        List<Integer> recursiveResult = new ArrayList<>();
        inorderRecursive(root, recursiveResult);
        System.out.println("Recursive Inorder: " + recursiveResult);

        // Iterative approach
        List<Integer> iterativeResult = inorderIterative(root);
        System.out.println("Iterative Inorder: " + iterativeResult);
    }
}

/*
---------------- Output ----------------
Recursive Inorder: [1, 2, 3, 4, 5]
Iterative Inorder: [1, 2, 3, 4, 5]

---------------- Complexity ----------------
Recursive:
    Time Complexity: O(n) - Each node is visited exactly once.
    Space Complexity: O(h) - Recursion stack, h is tree height (O(n) worst case).
Iterative:
    Time Complexity: O(n) - Each node pushed and popped from stack once.
    Space Complexity: O(h) - Stack holds at most h nodes at a time.
--------------------------------------------
*/
