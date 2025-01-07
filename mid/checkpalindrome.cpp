#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *prev;
        Node *next;

        Node(int val)
        {
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
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

bool checkIsPlaindrom(Node *head, Node *head2)
{
    Node *temp = head;
    Node *temp1 = head2;

    while (temp!=NULL)
    {
        if(temp->val != temp1->val)
        {
            return false;
        }

        temp = temp->next;
        temp1 = temp1->next;
    }

    return true;
    
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }

        insert_at_tail(head, tail, val);
        insert_at_tail(head2, tail2, val);

    }

    reverse_doubly(head2, tail2);
    
    bool flag = checkIsPlaindrom(head, head2);
    if(flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}