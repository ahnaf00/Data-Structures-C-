#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int a, b, c;

        Edge(int a, int b, int c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};

vector<Edge> edge_list;
vector<int> dist;
int n, e;

void bellman_ford()
{
    dist[0] = 0;

    for (int i = 0; i < n-1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if(dist[a] != INT_MAX && dist[a]+c < dist[b])
            {
                dist[b] = dist[a]+c;
            }
        }
    }
}


int main()
{
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b , c;
        cin >> a >> b >> c;

        edge_list.push_back(Edge(a,b,c));
    }

    dist.resize(n,INT_MAX);

    bellman_ford();
    
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }
    

    return 0;
}