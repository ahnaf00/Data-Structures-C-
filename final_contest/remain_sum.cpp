#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll tc;
    cin >> tc;

    while(tc--)
    {
        ll n;
        cin >> n;

        ll arr[n-2];
        ll sum = 0;
        for (ll i = 0; i < n-2; i++)
        {
            cin >> arr[i];
            sum+=arr[i];
        }

        ll total;
        cin >> total;

        ll remains = total - sum;

        if(remains < 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << remains+1 << "\n";
        }
    }


    return 0;
}