#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insertBST(TreeNode*& root, int val) {
    if (!root) { // if the tree is empty, create a new node
        root = new TreeNode(val);
        return;
    }
    if (val < root->val) insertBST(root->left, val);// if the value is less than the root, insert in the left subtree
    else insertBST(root->right, val);// if the value is greater than or equal to the root, insert in the right subtree
}

void inorder(TreeNode* root, vector<int>& values) {
    if (!root) return;
    inorder(root->left, values);
    values.push_back(root->val);
    inorder(root->right, values);
}

bool find_target(TreeNode* root, int k) {
    vector<int> values;
    if(!root) return false;
    inorder(root, values); // Get all values in sorted order using inorder traversal
    int i = 0, j = values.size() - 1;
    while (i < j) {
        int sum = values[i] + values[j];
        if (sum == k) return true; // Found the pair
        else if (sum < k) i++; // Move left pointer to increase sum
        else j--; // Move right pointer to decrease sum
    }

    return false;
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
