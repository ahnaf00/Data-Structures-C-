#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int r, c;
int minDot = 0;
bool valid(int i , int j)
{
    if(i < 0 || j < 0 || i>= r || j>=c)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    minDot++;
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

    int ans = INT_MAX;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(!vis[i][j] && grid[i][j] == '.')
            {
                minDot = 0;
                dfs(i,j);
                ans = min(minDot,ans);
            }
        }
    }

    if(ans == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}