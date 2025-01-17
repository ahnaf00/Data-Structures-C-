#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    if(n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    stack<int> st;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    bool flag = true;

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