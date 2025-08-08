#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
void solve(Node* root, int &cnt , int &ans , int k) {
    if (root == nullptr) return;
    
    solve(root->left, cnt, ans, k);
    
    cnt++;
    if (cnt == k) {
        ans = root->data;
        return;
    }
    
    solve(root->right, cnt, ans, k);
}
int kthSmallest(Node* root, int k) {
    int cnt = 0;
    int ans = -1;
    solve(root, cnt, ans, k);
    return ans;
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int k = 3;
    cout << "The " << k << " smallest element in the BST is: " << kthSmallest(root, k) << endl;

    return 0;

}