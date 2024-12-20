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

void isDuplicate(Node* head)
{
    int mx = INT_MIN;
    Node * temp = head;
    while (temp != NULL)
    {
        mx = max(mx, temp->val);
        temp = temp->next;
    }
    
    vector<int> arr(mx+1, 0);

    while (temp!=NULL)
    {
        arr[temp->val]++;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        arr[temp->val]++;
        if(arr[temp->val] > 1)
        {
            cout << "YES" << endl;
            return;
        }
        temp = temp->next;
    }
    

    cout << "NO" << endl;    
    
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

    isDuplicate(head);
    

    return 0;
}