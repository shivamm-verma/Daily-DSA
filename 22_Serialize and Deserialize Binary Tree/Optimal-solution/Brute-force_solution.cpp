// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    string serialize(TreeNode* root) {
        string preorderStr, inorderStr;
        getPreorder(root, preorderStr);
        getInorder(root, inorderStr);
        // using a separator(delimeter)
        return preorderStr + "|" + inorderStr;
    }

    TreeNode* deserialize(string data) {
        if (data.empty() || data == "|") return nullptr;

        size_t separator = data.find('|');
        string preorderStr = data.substr(0, separator);
        string inorderStr = data.substr(separator + 1);

        vector<int> preorder, inorder;
        stringstream ss_pre(preorderStr), ss_in(inorderStr);
        int val;
        while (ss_pre >> val) preorder.push_back(val);
        while (ss_in >> val) inorder.push_back(val);

        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        int preIndex = 0;
        return buildTree(preorder, preIndex, inorderMap, 0, inorder.size() - 1);
    }

private:
    void getPreorder(TreeNode* node, string& s) {
        if (!node) return;
        s += to_string(node->val) + " ";
        getPreorder(node->left, s);
        getPreorder(node->right, s);
    }

    void getInorder(TreeNode* node, string& s) {
        if (!node) return;
        getInorder(node->left, s);
        s += to_string(node->val) + " ";
        getInorder(node->right, s);
    }

    TreeNode* buildTree(vector<int>& preorder, int& preIndex, unordered_map<int, int>& inorderMap, int inStart, int inEnd) {
        if (preIndex >= preorder.size() || inStart > inEnd) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int inIndex = inorderMap[root->val];

        root->left = buildTree(preorder, preIndex, inorderMap, inStart, inIndex - 1);
        root->right = buildTree(preorder, preIndex, inorderMap, inIndex + 1, inEnd);
        return root;
    }
};