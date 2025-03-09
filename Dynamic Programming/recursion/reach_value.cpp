#include <bits/stdc++.h>
using namespace std;

#define ll long long int
bool reach;
unordered_map<ll, bool> dp;
bool canReach(ll currentVlaue, ll target)
{
    if(currentVlaue == target)
    {
        return true;
    }
    
    if(currentVlaue > target)
    {
        return false;
    }

    if(dp.find(currentVlaue) != dp.end())
    {
        return dp[currentVlaue];
    }

    return dp[currentVlaue] = canReach(currentVlaue*10, target) || canReach(currentVlaue*20, target);
}

int main()
{   
    int tc;
    cin >> tc;

    while (tc--)
    {
        ll n;
        cin >> n;
        dp.clear();
        
        int currentVlaue = 1;

        if(canReach(currentVlaue, n))
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