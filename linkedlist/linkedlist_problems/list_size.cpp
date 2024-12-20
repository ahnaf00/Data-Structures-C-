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

void print_list_size(Node* head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    cout << count << endl;
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

    print_list_size(head);
    

    return 0;
}