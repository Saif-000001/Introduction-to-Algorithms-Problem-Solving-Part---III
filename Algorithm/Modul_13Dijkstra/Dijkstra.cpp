#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int>> adj_list[N];
vector<int> visited(N);
vector<int> Distance(N, INF);
int n, m;

void Dijkstra(int src)
{
    queue<int> q;
    Distance[src] = 0;
    visited[src] = 1;
    q.push(src);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (auto child : adj_list[parent])
        {
            if (visited[child.first] == 0)
            {
                visited[child.first] = 1;
                Distance[child.first] = Distance[parent] + child.second;
                q.push(child.first);
            }
            else
            {
                if (Distance[parent] + child.second < Distance[child.first])
                    Distance[child.first] = Distance[parent] + child.second;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int source = 1;

    Dijkstra(source);

    for (int i = 1; i <= n; i++)
        cout << "Node : " << i << " Distance : " << Distance[i] << "\n";

    return 0;
}