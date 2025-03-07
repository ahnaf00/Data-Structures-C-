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
        grp_size[leader2] += leader1;
    }
}

int main()
{
    
    int n;
    cin >> n;

    par.resize(n+1,-1);
    grp_size.resize(n+1,1);

    vector<pair<int,int>> rmv, connects;

    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if(leaderA == leaderB)
        {
            rmv.push_back({a,b});
        }
        else{
            dsu_union(a,b);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        int pari_1 = dsu_find(1);
        int pari_i = dsu_find(i);

        if(pari_1 != pari_i)
        {
            connects.push_back({1,i});
            dsu_union(1,i);
        }   
    }

    cout << rmv.size() << endl;
    
    for (int i = 0; i < rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << connects[i].first << " " << connects[i].second << endl;
    }

    return 0;
}