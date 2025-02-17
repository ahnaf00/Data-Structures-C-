#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1},};
int r,c;

bool valid(int i, int j)
{
    if(i<0 || j < 0 || i >= r || j >= c)
    {
        return false;
    }
    return true;
}

void dfs(int si,int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '.')
        {
            dfs(ci,cj);
        }
    }
}

int main()
{
    cin >> r >> c;
    grid.resize(r,vector<char>(c));
    vis.resize(r,vector<bool>(c,false));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }    
    }

    int si,sj,di,dj;
    cin >> si >> sj >> di >> dj;

    dfs(si,sj);
    
    if(vis[di][dj])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}