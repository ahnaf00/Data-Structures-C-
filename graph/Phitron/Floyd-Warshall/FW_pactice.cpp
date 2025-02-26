#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_mat;

int main()
{
    int n, e;
    cin >> n >> e;

    adj_mat.resize(n,vector<int>(n,-1));

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj_mat[a][b] = c;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(adj_mat[i][k] != -1 && adj_mat[k][j] != -1)
                {
                    if(adj_mat[i][j] == -1 || adj_mat[i][k]+adj_mat[k][j] < adj_mat[i][j])
                    {
                        adj_mat[i][j] = adj_mat[i][k]+adj_mat[k][j];
                    }
                }
            }
        }    
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
    
    


    

    return 0;
}