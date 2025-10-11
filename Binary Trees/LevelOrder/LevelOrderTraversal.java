// Java program to perform Level Order Traversal (BFS) of a Binary Tree
// ✅ LeetCode 102. Binary Tree Level Order Traversal

import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        left = right = null;
    }
}

public class LevelOrderTraversal {

    // ------------------ BFS / Level Order ------------------
    public static List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode curr = queue.poll();
                level.add(curr.val);

                if (curr.left != null) queue.add(curr.left);
                if (curr.right != null) queue.add(curr.right);
            }

            result.add(level);
        }
        return result;
    }

    // ------------------ Main Method ------------------
    public static void main(String[] args) {
        /*
                 3
                / \
               9  20
                  /  \
                 15   7
        */

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        List<List<Integer>> traversal = levelOrder(root);
        System.out.println("Level Order Traversal: " + traversal);
    }
}

/*
---------------------- 🧪 Output ----------------------
Level Order Traversal: [[3], [9, 20], [15, 7]]

---------------------- ⏳ Complexity ----------------------
Time Complexity: O(n) — Each node is processed exactly once
Space Complexity: O(n) — Queue stores up to n nodes in worst case

✅ Intuition:
- Use a queue to process each level one by one
- For each node, push its children into the queue
- Collect values level by level
-----------------------------------------------------------
*/
