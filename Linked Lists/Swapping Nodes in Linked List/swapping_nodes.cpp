#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapNodes(ListNode *head, int k)
{
    if (head == nullptr)
    {
        return head;
    }
    int counter = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        counter++;
        temp = temp->next;
    }
    int l = counter - k;
    temp = head;
    ListNode *temp1 = head;
    while (k > 1)
    {
        k = k - 1;
        temp = temp->next;
    }
    while (l > 0)
    {
        l = l - 1;
        temp1 = temp1->next;
    }
    int m = temp->val;
    temp->val = temp1->val;
    temp1->val = m;
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Original List:" << endl;
    ListNode *temp = head;
    while(temp!=nullptr){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout <<endl;
    ListNode* result = swapNodes(head,2);
    cout << "Swapped List:" << endl;
    ListNode *temp1 = result;
    while(temp1!=nullptr){
        cout << temp1->val << " ";
        temp1 = temp1->next;
    }
    
    return 0;
}