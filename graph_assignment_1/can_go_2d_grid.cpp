#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> adj_list;
vector<vector<bool>> vis;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

int r, c;
int si = -1, sj = -1, di = -1, dj = -1;

bool valid(int i, int j)
{
    if( i<0 || j<0 || i>=r || j >= c)   
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

        if(valid(ci,cj) && !vis[ci][cj] && adj_list[ci][cj] != '#')
        {
            dfs(ci,cj);
        }
    }
    
}

int main()
{
    cin >> r >> c;

    adj_list.assign(r, vector<char>(c));
    vis.assign(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> adj_list[i][j];
            if(adj_list[i][j] == 'A')
            {
                si = i;
                sj = j;
            }

            if(adj_list[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    if (si == -1 || di == -1) {
        cout << "NO" << endl;
        return 0;
    }

    dfs(si,sj);

    if(vis[di][dj])
    {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }


    return 0;
}