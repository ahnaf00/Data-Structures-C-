#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int val;
        Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_at_any_pos(Node *&head, int indx, int val)
{
    Node *newNode = new Node(val);

    if(indx == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    int index = indx-1;

    while (index--)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    
}

void print_lst(Node *head)
{
    Node *temp = head;
    while (head != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    
}

int main()
{

    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);

    head->next = a;
    a->next = b;
    b->next = c;

    insert_at_any_pos(head, 0, 100);

    print_lst(head);

    return 0;
}