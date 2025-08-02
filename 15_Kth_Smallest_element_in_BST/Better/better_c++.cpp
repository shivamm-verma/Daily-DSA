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
void indorder(Node* root, vector<int>& arr) {
    if (root == nullptr) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
int kthSmallest(Node* root, int k) {
    vector<int> arr;
    inorder(root, arr);
    return arr[k - 1];
    
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