#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<int> vis,parent, level;

void bfs(int src, int lvl)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int x : adj_list[p])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x] = true;
                level[x] = level[p]+1;
                parent[x] = p;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    adj_list.resize(n+1);
    vis.assign(n+1, false);
    parent.assign(n+1, -1);
    level.assign(n+1, -1);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    int lvl;
    cin >> lvl;

    bfs(0, lvl);

    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if(level[i] == lvl)
        {
            result.push_back(i);
        }
    }

    reverse(result.begin(), result.end());

    for(int x : result)
    {
        cout << x << " ";
    }
    

    return 0;
}