// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// using Depth-First Search (DFS) (pre-order traversal).
class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream oss;
        buildString(root, oss);
        return oss.str();
    }

    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return buildTree(iss);
    }

private:
    void buildString(TreeNode* node, ostringstream& oss) {
        if (!node) {
            oss << "# ";
            return;
        }
        oss << node->val << " ";
        buildString(node->left, oss);
        buildString(node->right, oss);
    }

    TreeNode* buildTree(istringstream& iss) {
        string val;
        iss >> val;
        if (val == "#") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(iss);
        node->right = buildTree(iss);
        return node;
    }
};