#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;
vector<int> node_to_src, node_to_dst;

int n,e,cnt;

void bfs(int src, vector<int> &arr)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    arr[src] = 0;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        cnt++;

        for(int c : adj_list[p])
        {
            if(!vis[c])
            {
                q.push(c);
                vis[c] = true;

                arr[c] = arr[p]+1;
            }
        }
    }
}

int main()
{
    int tc;
    cin >> tc;

    for (int k = 1; k <= tc; k++)
    {
        cin >> n >> e;
    
        adj_list.assign(n,vector<int>());

        for(int i = 0; i < e; i++)
        {
            int a , b; 
            
            cin >> a >> b;
            
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }

        int src , dist;
        cin >> src >> dist;

        vis.assign(n,false);
        node_to_src.resize(n,-1);

        bfs(src, node_to_src);

        vis.assign(n,false);
        node_to_dst.resize(n,-1);

        bfs(dist, node_to_dst);

        int ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int val = node_to_src[i]+node_to_dst[i];
            ans = max(ans,val);
        }

        cout << "Case " << k << ": " << ans << endl;
    }
    

    return 0;
}