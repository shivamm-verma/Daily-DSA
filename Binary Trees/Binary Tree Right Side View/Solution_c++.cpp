#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        queue<TreeNode*>q;
        if (root == nullptr) return{};
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
                if(i == 0) res.push_back(node->val);
                
            }
        }
        return res;
        
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    vector<int> result = rightSideView(root);
    for(int i : result) {
        cout << i << " ";
    }
    return 0;
}
