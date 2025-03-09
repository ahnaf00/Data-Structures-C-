#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll fact(ll n)
{
    if(n==0 || n == 1)
    {
        return 1;
    }

    return n*fact(n-1);
}

int main()
{
    ll n ;
    cin >> n;

    cout << fact(n);
    return 0;
}