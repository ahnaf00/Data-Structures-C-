#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);

    for (int i = 0; i < m; i++)
    {
        int u, w;
        cin >> u >> w;
        adj[i].push_back({u,w});
    }
    

    return 0;
}