import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                if (node.right != null) q.offer(node.right);
                if (node.left != null) q.offer(node.left);
                level.add(node.val);
            }


            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();
                if (i == 0) res.add(node.val); // first node at this level is rightmost
                if (node.right != null) q.offer(node.right);
                if (node.left != null) q.offer(node.left);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.right = new TreeNode(5);

        Solution sol = new Solution();
        List<Integer> result = sol.rightSideView(root);
        for (int val : result) {
            System.out.print(val + " ");
        }
    }
}
