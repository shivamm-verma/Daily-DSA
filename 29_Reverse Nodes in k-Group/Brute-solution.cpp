#include <iostream>
#include <vector>
#include <algorithm>

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
        if (!head || k == 1) {
            return head;
        }

        vector<int> values;
        ListNode* current = head;
        while (current) {
            values.push_back(current->val);
            current = current->next;
        }

        for (int i = 0; i < values.size(); i += k) {
            if (i + k <= values.size()) {
                reverse(values.begin() + i, values.begin() + i + k);
            }
        }

        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        for (int val : values) {
            if (!newHead) {
                newHead = new ListNode(val);
                tail = newHead;
            } else {
                tail->next = new ListNode(val);
                tail = tail->next;
            }
        }

        return newHead;
    }
};