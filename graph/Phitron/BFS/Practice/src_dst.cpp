#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<int> vis, level;

void bfs(int src, int n)
{
    queue<int> q;
    q.push(src);

    vis.assign(n+1, false);
    level.assign(n+1, -1);
    
    vis[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for(int x : adj_list[p])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x] = true;
                level[x] = level[p]+1;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    adj_list.resize(n+1);


    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }


    int query;
    cin >> query;

    for (int i = 0; i < query; i++)
    {
        int src, dst;
        cin >> src >> dst;

        bfs(src, n);
        cout << level[dst] << endl;
    }
    

    return 0;
}