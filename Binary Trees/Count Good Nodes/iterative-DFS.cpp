#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        stack<pair<TreeNode*, int>> st;
        st.push({root, numeric_limits<int>::min()});
        int ans = 0;
        while (!empty(st)) {
            auto [node, mx] = st.top(); st.pop();
            
            ans += node->val >= mx;
            mx = max(mx, node->val);
            if (node->left) st.push({node->left, mx});
            if (node->right) st.push({node->right, mx});
        }
        
        return ans;
    }
};