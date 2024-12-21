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

void print_similarity(Node* head, Node* head1)
{
    Node* temp = head;
    Node* temp1 = head1;

    while (temp != NULL && temp1!= NULL)
    {
        if(temp->val != temp1->val)
        {
            cout << "NO" << endl;
            return;
        }
        temp = temp->next;
        temp1 = temp1->next;
    }

    if(temp == NULL && temp1 == NULL)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    Node* head1 = NULL;
    Node* tail1 = NULL;

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

    int val1;
    while (true)
    {
        cin >> val1;
        if(val1 == -1)
        {
            break;
        }

        insert_at_tail(head1, tail1, val1);
    }

    print_similarity(head, head1);
    

    return 0;
}