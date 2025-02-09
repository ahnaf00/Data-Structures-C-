#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<vector<int>> level;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

int r, c;

bool valid(int i, int j)
{
    if(i < 0 || i < j || i >= r || j >= c)
    {
        return false;
    }

    return true;
}


void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();    

        int p_i = p.first;
        int p_j = p.second;

        for (int i = 0; i < 4; i++)
        {
            int c_i, c_j;
            c_i = p_i + d[i].first;
            c_j = p_j + d[i].second;

            if(valid(c_i,c_j) && !vis[c_i][c_j])
            {
                q.push({c_i,c_j});
                vis[c_i][c_j] = true;
                level[c_i][c_j] = level[p_i][p_j]+1;
            }
        }
    }
}

int main()
{
    cin >> r >> c;

    grid.resize(r, vector<char>(c));
    vis.resize(r, vector<bool>(c, false));
    level.resize(r, vector<int>(c, -1));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
        }
    }

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    bfs(si, sj);

    cout << level[di][dj] << endl;
    

    return 0;
}