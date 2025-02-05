#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        set<int> s;

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            s.insert(num);
        }

        for (int num : s)
        {
            cout << num << " ";
        }
        cout << endl;
        
        
    }
    

    return 0;
}  