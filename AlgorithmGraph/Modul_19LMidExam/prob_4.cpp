#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const long long INF = 1e18;

vector<pair<long long, int>> adj_list[N];
int visited[N];
int parent[N];
long long d[N];
int n, m;

void dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<long long, int> head = pq.top();
        int selected_node_u = head.second;
        pq.pop();

        if (visited[selected_node_u] == 1)
            continue;

        visited[selected_node_u] = 1;

        for (auto adj_anty : adj_list[selected_node_u])
        {
            int adj_node_v = adj_anty.first;
            int adj_edge_w = adj_anty.second;

            if (d[selected_node_u] + adj_edge_w < d[adj_node_v])
            {
                d[adj_node_v] = d[selected_node_u] + adj_edge_w;
                parent[adj_node_v] = selected_node_u;

                pq.push({-d[adj_node_v], adj_node_v});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 1;
    dijkstra(src);

    if (visited[n] == 0)
    {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;

    while (true)
    {
        path.push_back(n);
        if (src == n)
            break;
        n = parent[n];
    }

    reverse(path.begin(), path.end());

    for (auto node : path)
        cout << node << " ";

    cout << "\n";
    return 0;
}


/*

10 10
1 4 201
2 3 238
3 4 40
3 6 231
3 8 45
4 5 227
4 6 58
4 9 55
5 7 14
6 10 242

*/