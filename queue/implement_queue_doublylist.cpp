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

class Queue{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int sz = 0;

        void push(int val)
        {
            sz++;
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

        void pop()
        {
            sz--;
            Node *deleteNode = head;
            head = head->next;
            delete deleteNode;
            if(head == NULL)
            {
                tail = NULL;
                return;
            }
            head->prev = NULL;
        }

        int front()
        {
            return head->val;
        }

        int back()
        {
            return tail->val;
        }

        int size()
        {
            return sz;
        }

        bool empty()
        {
            return head == NULL;
        }
};

int main()
{
    Queue q;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << q.front() << " " << q.back() << " " << q.size() << endl;

    cout << "=================" << endl;

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}