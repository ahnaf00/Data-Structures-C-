#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int a, b, c;
    Edge(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
vector<long long> dist;
int n, e;
bool cycle = false;

void bellman_ford(int src) {
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        bool updated = false;
        for (auto ed : edge_list) {
            int a = ed.a, b = ed.b, c = ed.c;
            if (dist[a] != LLONG_MAX && dist[a] + c < dist[b]) {
                dist[b] = dist[a] + c;
                updated = true;
            }
        }
        if (!updated) break;
    }

    for (auto ed : edge_list) {
        int a = ed.a, b = ed.b, c = ed.c;
        if (dist[a] != LLONG_MAX && dist[a] + c < dist[b]) {
            cycle = true;
            return;
        }
    }
}

int main() {
    cin >> n >> e;
    
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src;
    cin >> src;

    dist.resize(n + 1, LLONG_MAX);

    bellman_ford(src);

    if (cycle) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int d;
        cin >> d;
        if (dist[d] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dist[d] << endl;
    }

    return 0;
}
