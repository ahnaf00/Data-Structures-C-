#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> vis;
vector<vector<int>> level; 
vector<pair<int,int>> d = {{2,-1},{2,1},{1,-2},{-1,-2},{-2,-1},{-2,1},{1,2},{-1,2}};

int r, c;

bool valid(int i, int j)
{
    if( i < 0 || j < 0 || i>= r || j >= c)
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
        pair<int,int> p;
        p= q.front();
        q.pop();
        
        int pi = p.first;
        int pj = p.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if(valid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj]+1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> r >> c;
        grid.assign(r, vector<int>(c));
        vis.assign(r, vector<bool>(c, false));
        level.assign(r, vector<int>(c, -1));
        
        int si, sj, di, dj;
        
        cin >> si >> sj >> di >> dj;

        bfs(si, sj);
        
        if(level[di][dj] == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << level[di][dj] << endl;
        }
    }
    

    return 0;
}