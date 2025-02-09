#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int, int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

int r, c;

bool valid(int i, int j)
{
    if(i>=r || i<0 || j>=c || j<0)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + d[i].first;
        cj = sj + d[i].second;

        if(valid(ci,cj) && !vis[ci][cj])
        {
            dfs(ci,cj);
        }
    }
}

int main()
{
    cin >> r >> c;

    grid.resize(r, vector<char>(c));
    vis.resize(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    dfs(si, sj);


    return 0;
}