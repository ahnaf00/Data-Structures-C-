#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<int> dis;

void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();

        int p_node = p.second;
        int p_dis = p.first;

        for (auto child : adj_list[p_node])
        {
            int c_node = child.second;
            int c_dis = child.first;

            if(p_dis+c_dis < dis[c_node])
            {
                dis[c_node] = p_dis+c_dis;
                pq.push({dis[c_node],c_node});
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
        adj_list[a].push_back({c,b});
        adj_list[b].push_back({c,a});   
    }

    dijkstra(0);
    
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    

    return 0;
}