#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}} ;
int r, c;

bool valid(int i, int j)
{
    if(i < 0 || j < 0 || i >= r || j>= c)
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
    
    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();

        int p_i = p.first;
        int p_j = p.second;

        cout << p_i << " " << p_j << endl;

        for (int i = 0; i < 4; i++)
        {
            int c_i = p_i + d[i].first;
            int c_j = p_j + d[i].second;

            if(valid(c_i, c_j) && !vis[c_i][c_j])
            {
                q.push({c_i,c_j});
                vis[c_i][c_j] = true;
            }
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

    bfs(si, sj);
    

    return 0;
}       