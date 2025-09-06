#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void morrisInorder() {
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                cout << curr->data << " ";
                curr = curr->right;
            } else {
                Node* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }
                if (pred->right == nullptr) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    cout << curr->data << " ";
                    curr = curr->right;
                }
            }
        }
    }
};

int main() {
    BinaryTree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);

    cout << "Morris Inorder Traversal: ";
    tree.morrisInorder();
    return 0;
}
