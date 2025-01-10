#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        vector<int> v;

        void push(int val)
        {
            v.push_back(val);
        }

        void pop()
        {
            v.pop_back();
        }

        int top()
        {
            return v.back();
        }

        int size()
        {
            return v.size();
        }

        bool empty()
        {
            return v.empty();
        }
};

int main()
{

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << (st.empty() ? "true" : "false") << endl;



    return 0;
}