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

class Stack{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int sz;

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
            Node *deleteNode = tail;
            tail = tail->prev;

            if(tail == NULL)
            {
                head = NULL;
                return;
            }
            tail->next = NULL;
        }

        int top()
        {
            return tail->val;
        }

        int size()
        {
            return sz;
        }

        int empty()
        {
            return head == NULL;
        }
};


int main()
{
    Stack st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        st.push(v);
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();

    }
    
    return 0;
}