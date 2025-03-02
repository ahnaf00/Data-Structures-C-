#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

int r, c, nodes;

bool isValid(int i, int j)
{
    if(i < 0 || j < 0 || i >= c || j>= r)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    nodes++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(isValid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci,cj);
        }
    }
    
}

int main()
{
    int tc;
    cin >> tc;

    for (int k = 1; k <= tc; k++)
    {
        cin >> r >> c;

        grid.assign(c,vector<char>(r));
        vis.assign(c,vector<bool>(r,false));
        
        int si, sj;

        for (int i = 0; i < c; i++)
        {
            for (int j = 0; j < r; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }

        nodes=0;
        dfs(si,sj);
        
        cout << "Case "<< k <<": "<< nodes << endl;
    }
    
    

    return 0;
}