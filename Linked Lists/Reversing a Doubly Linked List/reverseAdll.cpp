#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};



Node* reverseDLL(Node* head)
{   
    Node* temp = head;
    Node* newHead = head;
    while(temp!=NULL){
        Node* back = temp->prev;
        Node* front = temp->next;
        temp->prev=front;
        temp->next=back;
        newHead = temp;
        temp = temp->prev;
    }
    return newHead;
}
