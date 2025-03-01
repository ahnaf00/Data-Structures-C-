#include <bits/stdc++.h>
using namespace std;

int par[100];
int group_size[100];

int dsu_find(int node)
{
    if(par[node] == -1)
    {
        return node;
    }

    int leader = dsu_find(par[node]);
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);

    if(group_size[node1] >= group_size[node2])
    {
        par[leader2] = node1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = node2;
        group_size[leader2] = group_size[leader1];
    }
}

int main()
{
    memset(par,-1,sizeof(par));
    memset(group_size,1,sizeof(group_size));

    int n, e;
    cin >> n >> e;
    bool cycle = false;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if(leaderA == leaderB)
        {
            cycle = true;
        }
        else
        {
            dsu_union(a,b);
        }
    }

    if(cycle)
    {
        cout << "Cycle detected" << endl;
    }
    else
    {
        cout << "No cycle detected" << endl;
    }
    

    return 0;
}