#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};

ListNode* createList(const vector<int>& arr) {
    ListNode dummy(0);
    ListNode* temp = &dummy;
    for (int num : arr) {
        temp->next = new ListNode(num);
        temp = temp->next;
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> list1 = {1, 4, 5};
    vector<int> list2 = {1, 3, 4};
    vector<int> list3 = {2, 6};
    ListNode* l1 = createList(list1);
    ListNode* l2 = createList(list2);
    ListNode* l3 = createList(list3);
    vector<ListNode*> lists = {l1, l2, l3};
    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);
    cout << "Merged Linked List: ";
    printList(merged);
    return 0;
}
