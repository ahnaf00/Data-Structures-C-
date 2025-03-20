#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target, indx;
    bool found = false;
    cin >> n;
    
    vector<int> num(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    cin >> target;


    for (int i = 0; i < n; i++)
    {
        if(num[i] == target)
        {
            cout << i << endl;
            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << -1 << endl;
    }
    
    return 0;
}