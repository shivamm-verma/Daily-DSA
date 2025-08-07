#include <iostream>

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

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev_group_tail = dummy;
        ListNode* curr = head;

        while (curr) {
            ListNode* group_start = curr;
            ListNode* group_end = curr;
            int count = 1;
            while (count < k && group_end) {
                group_end = group_end->next;
                count++;
            }

            if (!group_end) {
                break;
            }
            
            ListNode* next_group_start = group_end->next;
            
            ListNode* prev = next_group_start;
            while (curr != next_group_start) {
                ListNode* next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
            }

            prev_group_tail->next = group_end;
            prev_group_tail = group_start;
            
            curr = next_group_start;
        }

        return dummy->next;
    }
};