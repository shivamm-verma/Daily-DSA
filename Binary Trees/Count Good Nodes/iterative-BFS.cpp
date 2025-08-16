#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, numeric_limits<int>::min()});
        int ans = 0;
        while (!empty(q)) {
            auto [node, mx] = q.front(); q.pop();
            
            ans += node->val >= mx;
            mx = max(mx, node->val);
            if (node->left) q.push({node->left, mx});
            if (node->right) q.push({node->right, mx});
        }
        
        return ans;
    }
}