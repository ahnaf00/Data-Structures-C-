#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int subSeq(string s1, string s2)
{
    int a = s1.size();
    int b = s2.size();

    vector<ll> dp(b+1,0);
    dp[0] = 1;
    for (int i = 0; i < a; i++)
    {
        for (int j = b-1; j >= 0; j--)
        {
            if(s1[i] == s2[j])
            {
                dp[j+1] += dp[j]; 
            }
        }
    }
    return dp[b];
}

int main()
{
    int tc;
    cin >> tc;

    while(tc--)
    {
        string s,s2;
        cin >> s >> s2;

        cout << subSeq(s,s2) << endl;
    }

    return 0;
}