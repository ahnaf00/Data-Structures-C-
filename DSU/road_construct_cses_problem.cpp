#include <bits/stdc++.h>
using namespace std;

vector<int> par,group_size;

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

int max_grp_size;

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);

    if(group_size[node1] >= group_size[node2])
    {
        par[leader2] = node1;
        group_size[leader1] += group_size[leader2];
        max_grp_size = max(group_size[leader1],max_grp_size);
    }
    else
    {
        par[leader1] = node2;
        group_size[leader2] += group_size[leader1];
        max_grp_size = max(group_size[leader2],max_grp_size);
    }
}

int main()
{
    int n,e;
    cin >> n >> e;

    int component = n;
    max_grp_size = 1;

    par.assign(n+1,-1);
    group_size.assign(n+1,1);

    while (e--)
    {
        int u, v;
        cin >> u >> v;

        int par_u = dsu_find(u);
        int par_v = dsu_find(v);

        if(par_u != par_v)
        {
            dsu_union(u,v);
            component--;
        }

        cout << component << " " << max_grp_size << endl;
    }
    


    return 0;
}