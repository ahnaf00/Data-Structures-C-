#include <bits/stdc++.h>
using namespace std;

int adj_mat[1001][1001];

int main()
{
    int n, e;
    cin >> n >> e;

    memset(adj_mat,0,sizeof(adj_mat));

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;

        adj_mat[a][b] = 1;
        
    }

    int query;
    cin >> query;

    for (int i = 0; i < query; i++)
    {
           
        int src, dst;
        cin >> src >> dst;

        if (src == dst) {
            cout << "YES" << endl;
        } else if (adj_mat[src][dst] == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    

    return 0;
}