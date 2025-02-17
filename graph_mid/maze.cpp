#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<vector<pair<int,int>>> parent;

vector<pair<int,int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int r,c;

bool valid(int i, int j)
{
    if(i < 0 || j < 0 || i >= r || j >= c )
    {
        return false;
    }
    return true;
}

void bfs(int si, int sj,int di, int dj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();

        int pi = p.first;
        int pj = p.second;

        if(pi == di && pj == dj)
        {
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {pi,pj};
            }
        }
    }
    
    
    
}

int main()
{
    cin >> r >> c;
    grid.resize(r,vector<char>(c));
    vis.resize(r,vector<bool>(c,false));
    parent.resize(r,vector<pair<int,int>>(c,{-1,-1}));
    int si, sj, di, dj;

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
            if(grid[i][j] == 'R')    
            {
                si = i;
                sj = j; 
            }
            else if(grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    bfs(si,sj,di,dj);

    if(vis[di][dj])
    {
        int x = di, y = dj;

        while (parent[x][y].first != -1 && parent[x][y].second != -1)
        {
            int pi = parent[x][y].first;
            int pj = parent[x][y].second;

            if(pi == si && pj == sj) 
            {
                break; 
            }
            
            grid[pi][pj] = 'X';

            x = pi;
            y = pj;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout <<  grid[i][j];    
        }
        cout << endl;
    }


    return 0;
}