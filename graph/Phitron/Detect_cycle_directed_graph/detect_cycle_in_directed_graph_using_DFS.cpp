#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis,pasthvis;
bool cycle;

void dfs(int src)
{
    vis[src] = true;
    pasthvis[src] = true;

    for(int x : adj_list[src])
    {
        if(vis[x] && pasthvis[x])
        {
            cycle = true;
        }

        if(!vis[x])
        {
            dfs(x);
        }
    }
    pasthvis[src] = false;

}

int main()
{
    int n, e;
    cin >> n >> e;

    adj_list.resize(n);
    vis.assign(n,false);
    pasthvis.assign(n,false);
    cycle = false;

    for (int i = 0; i < e; i++)
    {
        int a , b;
        cin >> a >> b;

        adj_list[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }


    if(cycle)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        cout << "No Cycle" << endl;
    }
    
    

    return 0;
}