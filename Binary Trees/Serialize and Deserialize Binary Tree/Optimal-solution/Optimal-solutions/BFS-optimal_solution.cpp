#include <iostream>
#include <string>
#include <queue>
#include <sstream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// using Breadth-First Search (BFS) (level-order traversal).
class Solution {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        
        queue<TreeNode*> q;
        q.push(root);
        string result = "";
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                result += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "# ";
            }
        }
        return result;
    }

    TreeNode* deserialize(string data) {
        if (data == "#") return nullptr;
        
        stringstream ss(data);
        string val_str;
        
        ss >> val_str;
        TreeNode* root = new TreeNode(stoi(val_str));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            // left child
            if (ss >> val_str && val_str != "#") {
                node->left = new TreeNode(stoi(val_str));
                q.push(node->left);
            }
            
            // right child
            if (ss >> val_str && val_str != "#") {
                node->right = new TreeNode(stoi(val_str));
                q.push(node->right);
            }
        }
        return root;
    }
};