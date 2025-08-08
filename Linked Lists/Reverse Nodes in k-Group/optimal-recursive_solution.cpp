#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        for (int i = 0; i < k; ++i) {
            if (!curr) {
                return head; 
            }
            curr = curr->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* current_head = head;
        for (int i = 0; i < k; ++i) {
            ListNode* next_node = current_head->next;
            current_head->next = prev;
            prev = current_head;
            current_head = next_node;
        }

        if (current_head != nullptr) {
            head->next = reverseKGroup(current_head, k);
        }
        
        return prev;
    }
};