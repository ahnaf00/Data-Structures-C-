#include <bits/stdc++.h>
using namespace std;

#define ll long long int
bool reach;
vector<ll> dp;

bool canReach(ll currentValue, int target)
{
    if(currentValue == target)
    {
        return true;
    }

    if(currentValue > target)
    {
        return false;
    }

    if(dp[currentValue] != -1)
    {
        return dp[currentValue];
    }

    return dp[currentValue] = canReach(currentValue+3,target) || canReach(currentValue*2,target);
}

int main()
{
    int tc;
    cin >> tc;

    while (tc--)
    {
        ll n;
        cin >> n;

        dp.assign(n+1,-1);

        int currentVlaue = 1;

        if(canReach(currentVlaue,n))
        {
            cout << "YES" << endl; 
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    

    return 0;
}