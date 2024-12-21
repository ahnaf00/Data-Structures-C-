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

void insert_at_head(Node* &head, int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node* &head, int val)
{
    Node* newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void delete_node(Node* &head, int pos)
{

    if(head == NULL || pos < 0)
    {
        return;
    }

    if(pos == 0)
    {
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos-1; i++)
    {
        if(temp->next == NULL)
        {
            return;
        }
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}

void print_list(Node* head)
{
    Node* temp = head;
    while (temp!=NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    cout << endl;
}

void remove_duplicates(Node* head)
{
    Node* temp = head;
    while (temp!=NULL)
    {
        
    }
    
}

int main()
{

    int testCases;
    cin >> testCases;

    Node* head = NULL;
    for (int i = 0; i < testCases; i++) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            insert_at_head(head, V);
        } else if (X == 1) {
            insert_at_tail(head, V);
        } else if (X == 2) {
            delete_node(head, V);
        }
        print_list(head);
    }
    

    return 0;
}