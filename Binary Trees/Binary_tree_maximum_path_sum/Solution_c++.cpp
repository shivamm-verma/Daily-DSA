#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxpath(TreeNode *root, int &maxi)
{
    if (root == nullptr)
        return 0;
    int left = max(0, maxpath(root->left, maxi));   // left path sum
    int right = max(0, maxpath(root->right, maxi)); // right path sum
    maxi = max(maxi, (root->val + left + right));
    return root->val + max(left, right);
}
int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    maxpath(root, maxi);
    return maxi;
}

int main()
{
    // Example usage:
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int result = maxPathSum(root);
    cout << "Maximum path sum: " << result << endl; // Output: 11 (4 -> 2 -> 1 -> 3)

    return 0;
}