#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int n, q;
    cin >> n >> q;

    ll arr[n+1] = {0};

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        arr[i] = arr[i-1]+x;
    }

    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << arr[r]-arr[l-1] << endl;
    }
    

    return 0;
}