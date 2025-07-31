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

bool hash_find(TreeNode* root,int k,set<int>& s) {
    if (!root) return false;
    if (s.contains(k - root->val)) return true; // Check if the complement exists in the set
    s.insert(root->val); // Insert current node's value into the set
    return hash_find(root->left, k, s) || hash_find(root->right, k, s); // Recur for left and right subtrees
}
bool find_target(TreeNode* root, int k) {
    set<int> s;
    return hash_find(root, k, s);
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
