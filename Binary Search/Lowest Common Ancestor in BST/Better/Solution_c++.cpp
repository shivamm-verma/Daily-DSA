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

bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
    if (!root) return false;
    path.push_back(root);
    if (root == target) return true;
    if (target->val < root->val) {
        if (findPath(root->left, target, path)) return true;
    } else {
        if (findPath(root->right, target, path)) return true;
    }
    path.pop_back();
    return false;
}

TreeNode* lcaBetter(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> pathP, pathQ;
    findPath(root, p, pathP);
    findPath(root, q, pathQ);

    int i = 0;
    while (i < pathP.size() && i < pathQ.size() && pathP[i] == pathQ[i]) {
        i++;
    }
    return pathP[i - 1];
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

    TreeNode* lca = lcaBetter(root, p, q);
    cout << "Better Approach LCA: " << lca->val << endl;
}
