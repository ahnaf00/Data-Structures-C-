#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;
vector<int> road;

void dfs(int src)
{
    vis[src] = true;
    for (int x : adj_list[src])
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
    vis.resize(n+1,false);

    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            road.push_back(i);
            dfs(i);
        }
    }

    cout << road.size() - 1 << endl;

    for (int i = 0; i < road.size()-1; i++)
    {
        cout << road[i] << " " << road[i+1] << endl;
    }
    


    return 0;
}