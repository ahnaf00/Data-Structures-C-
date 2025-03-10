#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll tetranacci(ll n)
{
    vector<ll> dp(n+1);

    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 2;


    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4];
    }

    return dp[n];
    

}

int main()
{
    ll n;
    cin >> n;
    
    cout << tetranacci(n) << endl;

    return 0;
}