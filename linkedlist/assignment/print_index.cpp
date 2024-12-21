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

int print_index(Node *head, int num)
{
    Node* temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if(temp->val ==  num)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int main()
{
    int testCases;
    cin >> testCases;

    while (testCases--)
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

        int num; 
        cin >> num;
        cout << print_index(head, num) << endl;

    }
    
    

    return 0;
}