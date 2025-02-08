#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
int level[1005];
int vis[1005];
int parent[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
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
                parent[x] = p;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    int src = 1, dst = n;

    bfs(src);

    int node = dst;
    vector<int> path;

    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];    
    }

    reverse(path.begin(), path.end());

    for(int x : path)
    {
        cout << x << " ";
    }
    

    return 0;
}