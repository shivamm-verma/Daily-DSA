#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *root1 = nullptr;
void InorderTraversal(TreeNode *root)
{
    if (root != nullptr)
    {
        TreeNode *newNode = new TreeNode(root->val);
        if (root1 == nullptr)
        {
            root1 = newNode;
        }
        else
        {
            root1->right = newNode;
        }
        InorderTraversal(root->left);
        InorderTraversal(root->right);
    }
    else
    {
        return;
    }
}

void flatten(TreeNode *root)
{
    // root1 = root;
    if (root == nullptr)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right = root1;
    root->left = nullptr;
    root1 = root;
}

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    cout << "Original Traversal: ";
    preorder(root);
    cout << endl;
    flatten(root);
    cout << "Linked list Traversal: ";
    preorder(root);
    cout << endl;
    return 0;
}
