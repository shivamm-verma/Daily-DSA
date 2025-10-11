#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int preIndex = 0;
    unordered_map<int, int> inMap;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        inMap.clear();
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        return helper(preorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int idx = inMap[rootVal];

        root->left = helper(preorder, left, idx - 1);
        root->right = helper(preorder, idx + 1, right);

        return root;
    }
};
