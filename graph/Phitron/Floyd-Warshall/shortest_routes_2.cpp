#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> adj_mat;

int main()
{
    int n , e , q;
    cin >> n >> e >> q;

    adj_mat.resize(n+5,vector<long long int>(n+5,LLONG_MAX));

    for (int i = 0; i < e; i++)
    {
        long long int a,b,c;
        cin >> a >> b >> c;

        adj_mat[a][b] = min(adj_mat[a][b],c);
        adj_mat[b][a] = min(adj_mat[a][b],c);
    }
    

    for (int i = 1; i <= n; i++)
    {
        adj_mat[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(adj_mat[i][k] != LLONG_MAX && adj_mat[k][j] != LLONG_MAX && adj_mat[i][k]+adj_mat[k][j] < adj_mat[i][j])
                {
                    adj_mat[i][j] = adj_mat[i][k]+adj_mat[k][j];
                }
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        if(adj_mat[a][b] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj_mat[a][b] << endl;
        }

    }
    
    
    

    return 0;
}