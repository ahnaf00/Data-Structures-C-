#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
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
        p = q.front();
        q.pop();

        int pi = p.first;
        int pj = p.second;

        for(int i = 0; i < 8; i++ )
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;

            if(valid(ci,cj) && !vis[ci][cj])
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
    r = 8, c = 8;
    grid.resize(r,vector<char>(c));
    vis.resize(r,vector<bool>(c,false));
    level.resize(r,vector<int>(c,-1));

    string src, dist;
    cin >> src >> dist;

    int si = src[1] - '1';
    int sj = src[0]- 'a';

    int di = dist[1]- '1';
    int dj = dist[0]- 'a';

    bfs(si,sj);

    cout << level[di][dj] << endl;

    return 0;
}