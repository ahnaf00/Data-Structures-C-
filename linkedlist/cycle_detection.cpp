#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;

        Node(int val)
        {
            this->val = val;
            this->next = NULL;
        }
};

void print_list(Node *head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;

    Node *hair = head;
    Node *tortoise = head;
    bool flag = false;

    while (hair!=NULL && hair->next!= NULL)
    {
        hair = hair->next->next;
        tortoise = tortoise->next;
        if(hair == tortoise)
        {
            flag = true;
            break;
        }
    }

    if(flag)
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "Cycle not detected" << endl;
    }
    


    return 0;
}