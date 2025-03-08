#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<vector<int>> level;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n, si, sj, di, dj, cnt;

bool isValid(int i, int j)
{
    if(i<0 || j < 0 || i>= n || j >= n)
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

    while (!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();

        int p_i = p.first;
        int p_j = p.second;

        for (int i = 0; i < 4; i++)
        {
            int c_i = p_i + d[i].first;
            int c_j = p_j + d[i].second;

            if(isValid(c_i, c_j) && !vis[c_i][c_j] && grid[c_i][c_j] != 'T')
            {
                q.push({c_i, c_j});
                vis[c_i][c_j] = true;
                level[c_i][c_j] = level[p_i][p_j] + 1;
                cnt++;
            }
        }
        

    }
    

}

int main()
{
    cin >> n;
    cnt = 0;
    grid.resize(n, vector<char>(n));
    vis.resize(n,vector<bool>(n,false));
    level.resize(n,vector<int>(n,-1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'S')
            {
                si = i;
                sj = j;
            }
            else if(grid[i][j] == 'E')
            {
                di = i;
                dj = j;
            }
        }
    }
    
    bfs(si,sj);

    cout << level[di][dj] << endl;


    return 0;
}