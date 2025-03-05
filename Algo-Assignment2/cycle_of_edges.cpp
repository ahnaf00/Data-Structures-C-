#include <bits/stdc++.h>
using namespace std;

vector<int> par, grp_size;

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

bool dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);

    if(leader1 == leader2)
    {
        return false;
    }

    if(grp_size[leader1] >= grp_size[leader2])
    {
        par[leader2] = node1;
        grp_size[leader1]+=grp_size[leader2];
    }
    else
    {
        par[leader1] = node2;
        grp_size[leader2]+=grp_size[leader1];
    }

    return true;
}

int main()
{
    int n, e, count_cycle=0;
    cin >> n >> e;

    par.assign(n+1,-1);
    grp_size.assign(n+1,1);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        if(!dsu_union(u,v))
        {
            count_cycle++;
        }
    }
    
    cout << count_cycle << endl;

    return 0;
}