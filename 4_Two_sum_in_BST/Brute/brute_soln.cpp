#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool find_target(TreeNode* root, int k) {
    queue<TreeNode*> q; // used to push node in level order
    vector<int> values;
    if (!root) return false;

    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        values.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    sort(values.begin(), values.end()); // sort the values to use two-pointer technique
    int i = 0, j = values.size() - 1;
    while (i < j) {
        int sum = values[i] + values[j];
        if (sum == k) return true;//
        else if (sum < k) i++; //move the left pointer to increase the sum
        else j--; //move the right pointer to decrease the sum
    }
    return false;
}

void insertBST(TreeNode*& root, int val) {
    if (!root) { // if the tree is empty, create a new node
        root = new TreeNode(val);
        return;
    }
    if (val < root->val) insertBST(root->left, val);// if the value is less than the root, insert in the left subtree
    else insertBST(root->right, val);// if the value is greater than or equal to the root, insert in the right subtree
}

int main() {
    int k;
    cout << "Enter target sum k: ";
    cin >> k;

    cout << "Enter values for BST :" << endl;

    int n;
    TreeNode* root = nullptr;

    while (cin >> n) {
        insertBST(root, n);
    }

    if (find_target(root, k))
        cout << "True: A pair exists with the given sum." << endl;
    else
        cout << "False: No such pair exists." << endl;

    return 0;
}
