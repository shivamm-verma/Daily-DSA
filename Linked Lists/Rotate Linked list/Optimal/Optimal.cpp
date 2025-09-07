#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int a) {
        val = a;
        next = NULL;
    }
};

// Function to insert node at the end
void insertNode(Node* &head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// Function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Optimal rotation
Node* rotateRight(Node* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Find length and tail
    int length = 1;
    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }

    // Step 2: Make it circular
    tail->next = head;

    // Step 3: Find new head
    k = k % length;
    int stepsToNewHead = length - k;
    Node* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

int main() {
    Node* head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original List: ";
    printList(head);

    int k = 2;
    head = rotateRight(head, k);

    cout << "After " << k << " rotations: ";
    printList(head);

    return 0;
}

/*
Time Complexity: O(n)   (n = number of nodes)
Space Complexity: O(1)
*/
