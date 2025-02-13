#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;
vector<int> parent;
bool cycle;

void dfs(int src)
{
    vis[src] = true;

    for (int x : adj_list[src])
    {
        if(vis[x] && parent[src] != x)
        {
            cycle = true;
        }

        if(!vis[x])
        {
            parent[x] = src;
            dfs(x);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;  
    adj_list.resize(n);
    vis.assign(n,false);
    parent.assign(n,-1);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    cycle = false;

    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    if(cycle)
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "NO Cycle detected" << endl;
    }
    
    return 0;
}