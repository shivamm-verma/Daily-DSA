#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

bool isPalindrome(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *temp = nullptr;
    Node *temp1 = slow;
    while (temp1 != nullptr)
    {
        temp1 = temp1->next;
        slow->next = temp;
        temp = slow;
        slow = temp1;
    }
    bool flag = true;
    temp1 = head;
    while (temp1 && temp)
    {
        if (temp1->data == temp->data)
        {
            flag = true;
        }
        else
        {
            return false;
        }
        temp = temp->next;
        temp1 = temp1->next;
    }
    return flag;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    // cout << isPalindrome(head);
    if(isPalindrome(head)){
        cout << "The Linked List is Palindrome" << endl;
    }
    else{
        cout << "The Linked List is not a Palindrome" << endl;
    }
    return 0;
}