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