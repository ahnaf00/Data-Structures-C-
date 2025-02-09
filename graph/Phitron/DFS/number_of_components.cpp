#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;

void dfs(int src)
{
    cout << src << " ";
    vis[src] = true;
    for(int x : adj_list[src])
    {   
        if(!vis[x])
        {
            dfs(x);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    adj_list.resize(n+1);
    vis.assign(n+1, false);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cout << endl;
        }
    }
    
    

    return 0;
}