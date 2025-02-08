#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<int> vis;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

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
            }
        }
    }
}

int main()
{
    int n ,e;
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

    bfs(0);
    int inputNode;
    cin >> inputNode;
    int count = 0;
    for(int x : adj_list[inputNode])
    {
        count++;
    }
    cout << count << endl;

    return 0;
}