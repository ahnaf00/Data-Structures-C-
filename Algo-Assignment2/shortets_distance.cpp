#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int n, e;
    cin >> n >> e;
    
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int a, b;
        long long w; 
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        int src, dst;
        cin >> src >> dst;

        if (dist[src][dst] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[src][dst] << endl;
        }
    }

    return 0;
}