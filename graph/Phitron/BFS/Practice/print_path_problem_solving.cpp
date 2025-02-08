#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<int> vis, level, parent;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

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
    parent.assign(n+1,-1);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int src = 1, dst = n;
    bfs(src);

    int node = dst;

    if(vis[dst] != true)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        vector<int> path;

        while (node != -1)
        {
            path.push_back(node);    
            node = parent[node];
        }    

        int count = path.size();
        reverse(path.begin(), path.end());

        cout << count << endl;
        for(int x : path)
        {
            cout << x << " ";
        }
    }


    
    

    return 0;
}