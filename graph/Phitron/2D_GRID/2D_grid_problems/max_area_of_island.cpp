#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj_list;
vector<vector<bool>> vis;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}}; 

int r, c;

int main()
{
    cin >> r >> c;

    adj_list.resize(r,vector<int>(c));
    vis.assign(r,vector<bool>(c,false));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            
        }
        
    }
    

    return 0;
}