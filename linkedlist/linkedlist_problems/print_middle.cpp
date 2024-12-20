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

bool isOdd(int count)
{
    return count%2==1 ? true : false;
}

void print_middle_element(Node* head)
{
    Node* temp = head;
    int count=0;
    while (temp!=NULL)
    {
        count++;
        temp = temp->next;
    }

    temp = head;
    if(isOdd(count))
    {
        int mid = count/2;
        while (mid--)
        {
            temp = temp->next;
        }
        cout << temp->val << endl;
    }
    else
    {
        int mid = count/2;
        mid -= 1;
        while (mid--)
        {
            temp = temp->next;
        }

        cout << temp->val << endl;
        cout << temp->next->val << endl;
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
    print_middle_element(head);

    return 0;
}