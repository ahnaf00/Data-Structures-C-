#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* prev = NULL;
        Node* next;

        Node(int val)
        {
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
};

void insert_at_tail(Node* &head,  Node* &tail, int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void reverse_doubly(Node* head, Node* tail)
{
    for (Node *i = head, *j=tail; i!=j && i->prev != j; i=i->next, j=j->prev)
    {
        swap(i->val, j->val);
    }
}

void print_list(Node* head)
{
    Node* temp = head;
    while (temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while(true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }

        insert_at_tail(head, tail, val);
    }
    print_list(head);
    reverse_doubly(head, tail);
    cout << endl;
    print_list(head);

    return 0;
}