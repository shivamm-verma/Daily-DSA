// C++ program to perform Inorder Traversal of a Binary Tree
// Includes both Recursive and Iterative approaches

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = right = nullptr;
    }
};

// ------------------ 1️⃣ Recursive Approach ------------------
void inorderRecursive(TreeNode* root, vector<int>& result) {
    // Base case: if the current node is null, return
    if (root == nullptr) return;

    // Step 1: Traverse left subtree
    inorderRecursive(root->left, result);

    // Step 2: Visit (process) current node
    result.push_back(root->val);

    // Step 3: Traverse right subtree
    inorderRecursive(root->right, result);
}

// ------------------ 2️⃣ Iterative Approach ------------------
vector<int> inorderIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    TreeNode* current = root;

    // While there are nodes to process
    while (current != nullptr || !st.empty()) {
        // Reach the leftmost node of the current node
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        // Pop the top node from stack
        current = st.top();
        st.pop();
        result.push_back(current->val);

        // Now, visit the right subtree
        current = current->right;
    }

    return result;
}

// ------------------ Main Method to Test ------------------
int main() {
    /*
            4
           / \
          2   5
         / \
        1   3
    */
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Recursive approach
    vector<int> recursiveResult;
    inorderRecursive(root, recursiveResult);
    cout << "Recursive Inorder: ";
    for (int val : recursiveResult) cout << val << " ";
    cout << endl;

    // Iterative approach
    vector<int> iterativeResult = inorderIterative(root);
    cout << "Iterative Inorder: ";
    for (int val : iterativeResult) cout << val << " ";
    cout << endl;

    return 0;
}

/*
---------------- Output ----------------
Recursive Inorder: 1 2 3 4 5
Iterative Inorder: 1 2 3 4 5

---------------- Complexity ----------------
Recursive:
    Time Complexity: O(n) - Each node is visited exactly once.
    Space Complexity: O(h) - Recursion stack, h is tree height (O(n) worst case).
Iterative:
    Time Complexity: O(n) - Each node pushed and popped from stack once.
    Space Complexity: O(h) - Stack holds at most h nodes at a time.
--------------------------------------------
*/
