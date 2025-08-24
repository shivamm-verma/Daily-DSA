class Node {
    Node[] links = new Node[2];

    boolean isSet(int bit) {
        return links[bit] != null;
    }

    Node get(int bit) {
        return links[bit];
    }

    void put(int bit, Node node) {
        links[bit] = node;
    }
}

class Tries {
    private Node root;

    public Tries() {
        root = new Node();
    }

    public void insert(int num) {
        Node node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node.isSet(bit)) {
                node.put(bit, new Node());
            }
            node = node.get(bit);
        }
    }

    public int getMax(int num) {
        Node node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node.isSet(1 - bit)) {
                maxi |= (1 << i);
                node = node.get(1 - bit);
            } else {
                node = node.get(bit);
            }
        }
        return maxi;
    }
}
class java_code {
    public static int findMaximumXOR(int[] nums) {
        Tries trie = new Tries();
        int res = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            trie.insert(nums[i]);
            res = Math.max(res, trie.getMax(nums[i]));
        }
        return res;
    }
    public static void main(String[] args) {
        int[] nums={3,10,5,25,2,8};
        System.out.println(findMaximumXOR(nums));
    }
}