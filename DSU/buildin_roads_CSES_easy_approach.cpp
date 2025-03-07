#include <bits/stdc++.h>
using namespace std;

vector<int> par,grp_size;
int cmp, mx;

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

    if(leader1 == leader2)
    {
        return;
    }

    if(grp_size[leader1] >= grp_size[leader2])
    {
        par[leader2] = leader1;
        grp_size[leader1] += grp_size[leader2];
        mx = max(mx,grp_size[leader1]);
    }
    else
    {
        par[leader1] = leader2;
        grp_size[leader2] += grp_size[leader1];
        mx = max(mx, grp_size[leader2]);
    }

    cmp--;
}

int main()
{
    int n, e;
    cin >> n >> e;

    par.resize(n+1,-1);
    grp_size.resize(n+1,1);

    cmp = n;

    for (int i = 0; i < e; i++)
    {
        int a , b;
        cin >> a >> b;

        dsu_union(a,b);
        cout << cmp << " " << mx << endl;
    }
    


    return 0;
}