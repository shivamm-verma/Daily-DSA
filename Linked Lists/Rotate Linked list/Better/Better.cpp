#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Find length of list
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Make it circular
        tail->next = head;
        k = k % n;
        int stepsToNewHead = n - k;

        // Move to new head
        ListNode* newTail = tail;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
