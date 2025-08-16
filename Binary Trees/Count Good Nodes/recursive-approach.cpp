#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, numeric_limits<int>::min());
    }

public:
    int goodNodes(TreeNode* node, int mx) {
        if (!node) return 0;
        
        int ans = node->val >= mx;
        mx = max(mx, node->val);
        
        ans += goodNodes(node->left, mx);
        ans += goodNodes(node->right, mx);
        
        return ans;
    }
};