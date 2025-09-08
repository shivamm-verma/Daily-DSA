#include <bits/stdc++.h>
using namespace std;

// Definition of a Node in Linked List
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to sort Linked List using Brute Force
Node* sortLL(Node* head) {
    vector<int> arr;
    Node* temp = head;

    // Store values in array
    while (temp != nullptr) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    // Reassign sorted values back to nodes
    temp = head;
    for (int val : arr) {
        temp->data = val;
        temp = temp->next;
    }
    return head;
}

/*
Time Complexity: O(N log N) 
- O(N) to traverse the list and store values
- O(N log N) to sort
- O(N) to reassign values

Space Complexity: O(N) 
- Extra space used for array to store node values
*/
