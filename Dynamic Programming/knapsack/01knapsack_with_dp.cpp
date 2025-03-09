#include <bits/stdc++.h>
using namespace std;

int val[1000], weight[1000];
vector<vector<int>> dp; 

int knapsack(int i, int max_weight)
{
    if(i < 0 || max_weight <= 0)
    {
        return 0;
    }

    if(dp[i][max_weight] != -1)
    {
        return dp[i][max_weight];
    }

    if(weight[i] <= max_weight)
    {
        int opt1 = knapsack(i-1,max_weight - weight[i]) + val[i];
        int opt2 = knapsack(i-1,max_weight);

        return dp[i][max_weight] = max(opt1,opt2);
    }
    else
    {
        return dp[i][max_weight] = knapsack(i-1,max_weight);
    }
}


int main()
{
    int n,max_weight;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cin >> max_weight;
    
    dp.resize(n,vector<int>(max_weight+1,-1));

    cout << knapsack(n-1, max_weight);
    

    return 0;
}