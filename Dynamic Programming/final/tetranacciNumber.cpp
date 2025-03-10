#include <bits/stdc++.h>
using namespace std;

int n;
int dp[60];

int tetranacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (n == 3) return 2;

    if(dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = tetranacci(n-1)+tetranacci(n-2)+tetranacci(n-3)+tetranacci(n-4);
}

int main()
{
    cin >> n;

    memset(dp,-1, sizeof(dp));
    
    cout << tetranacci(n) << endl;

    return 0;
}