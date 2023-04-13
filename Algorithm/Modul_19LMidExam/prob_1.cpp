#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
vector<pair<int, int>> adj_list[N];
int d[N];

int n, m;
bool bellman_ford(int src)
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;

    d[src] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (auto adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if (d[u] + w < d[v])
                {
                    d[v] = d[u] + w;
                    if (i == n)
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    if (bellman_ford(4))
        cout << "YES\n";
    else
        cout << "NO\n";
}


/*

5 7
1 2 3
1 3 2
2 3 1
2 4 -8
2 5 5
4 1 2
4 5 2

*/
