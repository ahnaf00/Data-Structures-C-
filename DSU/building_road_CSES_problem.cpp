#include <bits/stdc++.h>
using namespace std;

vector<int>  par, grp_size;

int dsu_find(int node)
{
    if(par[node] == -1)
    {
        return node;
    }

    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);

    if(grp_size[leader1] >= grp_size[leader2])
    {
        par[leader2] = leader1;
        grp_size[leader1] += grp_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        grp_size[leader2] += grp_size[leader1];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    par.assign(n+1,-1);
    grp_size.assign(n+1,1);

    while(e--)
    {
        int u, v;
        cin >> u >> v;

        int par_u = dsu_find(u);
        int par_v = dsu_find(v);

        if(par_u != par_v)
        {
            dsu_union(u,v);
        }
    }
    int cnt=0;
    vector<pair<int,int>> connects; 

    for (int i = 1; i <= n; i++)
    {
        int par_1 = dsu_find(1);
        int par_i = dsu_find(i);

        if(par_1!=par_i)
        {
            cnt++; 
            dsu_union(par_1,par_i);
            connects.push_back({1,i});
        }
    }

    cout << cnt << endl;
    for(auto c : connects)
    {
        cout << c.first << " " << c.second << endl;
    }
    

    return 0;
}