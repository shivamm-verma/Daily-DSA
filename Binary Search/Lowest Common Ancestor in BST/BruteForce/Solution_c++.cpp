#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};


TreeNode* lcaBruteForce(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* leftLCA = lcaBruteForce(root->left, p, q);
    TreeNode* rightLCA = lcaBruteForce(root->right, p, q);

    if (leftLCA && rightLCA) return root;
    return leftLCA ? leftLCA : rightLCA;
}

int main() {
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left;          // 2
    TreeNode* q = root->left->right;   // 4

    TreeNode* lca = lcaBruteForce(root, p, q);
    cout << "Brute Force LCA: " << lca->val << endl;
}
