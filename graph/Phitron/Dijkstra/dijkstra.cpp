#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>adj_list;
vector<int> dis;

void dijkstra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;

    while (!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();

        int p_node = par.first;
        int p_dis = par.second;
        
        for(auto child : adj_list[p_node])
        {
            int c_node = child.first;
            int c_dis = child.second;

            if(p_dis+c_dis < dis[c_node])
            {
                dis[c_node] = p_dis+c_dis;
                q.push({c_node,dis[c_node]});
            }
        }
    }
}

int main()
{   
    int n, e;
    cin >> n >> e;

    adj_list.resize(n);
    dis.resize(n,INT_MAX);

    for (int i = 0; i < e; i++)
    {
        int a, b,c;
        cin >> a >> b >> c;

        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
    
    dijkstra(0);
    
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    

    return 0;
}