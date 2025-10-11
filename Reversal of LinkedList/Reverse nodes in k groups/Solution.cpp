#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* nextNode) : val(x), next(nextNode) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* prevGroup = &dummy;

        while (true) {
            ListNode* kth = getKth(prevGroup, k);
            if (!kth) break;
            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;
            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            ListNode* tmp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = tmp;
        }
        return dummy.next;
    }

    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
