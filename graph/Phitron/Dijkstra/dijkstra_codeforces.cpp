#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<vector<pair<ll,ll>>> adj_list;
vector<ll> dis, parent;

void dijkstra(ll src)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,src});
    dis[src] = 0;

    while(!pq.empty())
    {
        pair<ll,ll> p = pq.top();
        pq.pop();

        ll p_node = p.second;
        ll p_dis = p.first;

        for(auto c : adj_list[p_node])
        {
            ll c_node = c.second;
            ll c_dis = c.first;

            if(p_dis+c_dis < dis[c_node])
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
    ll n, e;
    cin >> n >> e;

    adj_list.resize(n+1);
    parent.resize(n+1, -1);
    dis.resize(n+1,LLONG_MAX);

    for (ll i = 0; i < e; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;

        adj_list[a].push_back({w,b});
        adj_list[b].push_back({w,a});
    }

    dijkstra(1);

    if(dis[n] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        ll node = n;
        vector<ll> path;
        while (node != -1)
        {   
            path.push_back(node);
            node  = parent[node];
        }
        
        reverse(path.begin(), path.end());

        for(auto x : path)
        {
            cout << x << " ";
        }
    }
    
    

    return 0;
}