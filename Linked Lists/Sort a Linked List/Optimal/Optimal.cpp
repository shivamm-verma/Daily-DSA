#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Merge two sorted linked lists
Node* merge(Node* l1, Node* l2) {
    Node dummy(-1);
    Node* tail = &dummy;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Merge Sort
Node* sortLL(Node* head) {
    if (!head || !head->next) return head;

    // Find middle
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* mid = slow->next;
    slow->next = nullptr;

    Node* left = sortLL(head);
    Node* right = sortLL(mid);

    return merge(left, right);
}

/*
Time Complexity: O(N log N)
Space Complexity: O(log N) (recursion stack)
*/
