#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int>> adj_list[N];

int D[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        D[i] = INF;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    int src = 1;
    D[src] = 0;

    bool negative_cycle = false;

    for (int i = 1; i <= n; i++)
    {
        for (int node = 0; node < n; node++)
        {
            for (pair<int, int> adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if (D[u] + w < D[v])
                    D[v] = D[u] + w;
                if (i == n)
                    negative_cycle = true;
            }
        }
    }

    if (negative_cycle == true)
        cout << "Graph has negative cycle \n";
    else
    {
        for (int i = 1; i <= n; i++)
            cout << D[i] << " ";

        cout << "\n";
    }
    return 0;
}

/*
4 4 
1 2 10
1 3 5
2 3 -12
3 4 4

4 4
1 2 5
1 3 -2
2 4 -6
3 4 1

*/