#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid; 
vector<bool> vis;

int main() {
    int edges[3][2] = {{0,1},{1,2},{2,0}};
    int n = 3; // Number of nodes
    int e = sizeof(edges) / sizeof(edges[0]); // Number of edges

    grid.resize(n);
    vis.assign(n, false);

    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        grid[u].push_back(v);
        grid[v].push_back(u);
    }

    // Print adjacency list
    for(int i = 0; i < n; i++) {
        cout << "Node " << i << ": ";
        for(int j : grid[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
