#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<int> dis,parent;

void dijkstra(int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dis[src] = 0;

    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();

        int p_node = p.second;
        int p_dis = p.first;

        for(auto c : adj_list[p_node])
        {
            int c_node = c.second;
            int c_dis = c.first;

            if(p_dis+c_dis<dis[c_node])
            {
                dis[c_node] = p_dis+c_dis;
                parent[c_node] = p_node;
                pq.push({dis[c_node],c_node});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >>e;
    vector<int>path;

    adj_list.resize(n+1);
    parent.resize(n+1,-1);
    dis.resize(n+1,INT_MAX);

    for (int i = 0; i < e; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;

        adj_list[a].push_back({c,b});
        adj_list[b].push_back({c,a});
    }

    dijkstra(1);
    
    if (dis[n] == INT_MAX)
    {
        cout << "-1\n";
        return 0;
    }

    int current = n;
    while(current!=-1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    for (auto p : path)
    {
        cout << p << " ";
    }
    
    return 0;
}