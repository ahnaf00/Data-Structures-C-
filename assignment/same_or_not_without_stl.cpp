#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        list<int>l;

        void push(int val)
        {
            l.push_back(val);
        }

        void pop()
        {
            l.pop_back();
        }

        int top()
        {
            return l.back();
        }

        int size()
        {
            return l.size();
        }

        int empty()
        {
            return l.empty();
        }
};

class Queue{
    public:
        list<int> l;

        void push(int val)
        {
            l.push_back(val);
        }

        void pop()
        {
            l.pop_front();
        }

        int front()
        {
            return l.front();
        }

        int back()
        {
            return l.back();
        }

        int size()
        {
            return l.size();
        }

        bool empty()
        {
            return l.empty();
        }
};

int main()
{
    int n, m;
    cin >> n >> m;

    if(n!=m)
    {
        cout << "NO" << endl;
        return 0;
    }

    Stack st;
    Queue q;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    while (!st.empty() && !q.empty())
    {
        if(st.top() == q.front())
        {
            st.pop();
            q.pop();
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (st.empty() && q.empty())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    

    return 0;
}