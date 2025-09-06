#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Pair {
    TreeNode* node;
    int hd;
    Pair(TreeNode* n, int h) : node(n), hd(h) {}
};

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    map<int, vector<int>> mp;
    queue<Pair> q;
    q.push(Pair(root, 0));

    while (!q.empty()) {
        Pair curr = q.front();
        q.pop();
        mp[curr.hd].push_back(curr.node->val);

        if (curr.node->left) q.push(Pair(curr.node->left, curr.hd - 1));
        if (curr.node->right) q.push(Pair(curr.node->right, curr.hd + 1));
    }

    for (auto &p : mp) {
        result.push_back(p.second);
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = verticalOrder(root);
    for (auto &col : ans) {
        for (int val : col) cout << val << " ";
        cout << endl;
    }
    return 0;
}
