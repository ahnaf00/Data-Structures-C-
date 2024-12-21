#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
};

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void find_duplicate(Node* head)
{
    for (Node* i = head; i != NULL; i = i->next)
    {
        Node* prev = i;
        Node* j = i->next;

        while (j != NULL)
        {
            if(i->val == j->val)
            {
                Node* deleteNode = j;
                prev->next = j->next;
                j = prev->next;
                delete deleteNode;
            }
            else
            {
                prev = j;
                j = j->next;
            }
        }
        
    }
}

void print_list(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
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
    while (true)
    {
        cin >> val;
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    find_duplicate(head);
    print_list(head);


    return 0;
}   