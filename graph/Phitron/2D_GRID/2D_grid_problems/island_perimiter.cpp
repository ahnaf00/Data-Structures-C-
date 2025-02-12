#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> vis;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

int r,c;
int perimiter=0;
bool valid(int i, int j)
{
    if(i <  0 || j < 0 || i >= r || j >= c)
    {
        return false;
    }
    return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci,cj) == false)
        {
            perimiter++;
        } 
        else if (valid(ci, cj) && grid[ci][cj] == 0)
        {
            perimiter++;
        }
        else if(!vis[ci][cj] && valid(ci,cj) && grid[ci][cj] == 1)
        {
            dfs(ci,cj);
        }
    }
    
}

int main()
{
    cin >> r >> c;
    perimiter = 0;
    grid.resize(r,vector<int>(c));
    vis.resize(r, vector<bool>(c,false));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(!vis[i][j] && grid[i][j] == 1)
            {
                dfs(i,j);
            }
        }
    }
    
    cout << perimiter << endl;
    
    return 0;
}