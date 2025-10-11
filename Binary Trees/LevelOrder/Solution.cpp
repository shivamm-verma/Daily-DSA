// C++ program to perform Level Order Traversal (BFS)
// ✅ LeetCode 102. Binary Tree Level Order Traversal

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front(); q.pop();
            level.push_back(curr->val);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        result.push_back(level);
    }

    return result;
}

int main() {
    /*
             3
            / \
           9  20
              /  \
             15   7
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> traversal = levelOrder(root);

    cout << "Level Order Traversal: [";
    for (int i = 0; i < traversal.size(); i++) {
        cout << "[";
        for (int j = 0; j < traversal[i].size(); j++) {
            cout << traversal[i][j];
            if (j != traversal[i].size()-1) cout << ", ";
        }
        cout << "]";
        if (i != traversal.size()-1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}

/*
---------------------- 🧪 Output ----------------------
Level Order Traversal: [[3], [9, 20], [15, 7]]

---------------------- ⏳ Complexity ----------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/
