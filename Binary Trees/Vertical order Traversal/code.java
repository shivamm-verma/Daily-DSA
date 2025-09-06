import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int val) { this.val = val; }
}

class Pair {
    TreeNode node;
    int hd; // horizontal distance
    Pair(TreeNode node, int hd) {
        this.node = node;
        this.hd = hd;
    }
}

public class code {
    public static List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Map<Integer, List<Integer>> map = new TreeMap<>();
        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(root, 0));

        while (!queue.isEmpty()) {
            Pair curr = queue.poll();
            map.computeIfAbsent(curr.hd, k -> new ArrayList<>()).add(curr.node.val);

            if (curr.node.left != null) queue.add(new Pair(curr.node.left, curr.hd - 1));
            if (curr.node.right != null) queue.add(new Pair(curr.node.right, curr.hd + 1));
        }

        result.addAll(map.values());
        return result;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        List<List<Integer>> ans = verticalOrder(root);
        System.out.println(ans); // [[4], [2], [1, 5, 6], [3], [7]]
    }
}
