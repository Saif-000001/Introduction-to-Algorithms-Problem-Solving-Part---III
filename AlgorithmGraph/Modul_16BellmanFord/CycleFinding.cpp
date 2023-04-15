#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];
long long dist[N];
int parent[N];

int main()
{
    
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    int src = 1;
    dist[src] = 0;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }


    bool negative_cycle = false;
    int last_update_node = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int node = 1; node <= n; node++)
        {
            for (auto adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;

                    if (i == n)
                    {
                        negative_cycle = true;
                        last_update_node = v;
                    }
                }
            }
        }
    }

    if (negative_cycle == true)
    {
        cout << "YES\n";

        int selected_node = last_update_node;
        for (int i = 1; i < n; i++)
            selected_node = parent[selected_node];

        int first_node = selected_node;

        vector<int> cycle;
        cycle.push_back(selected_node);

        while (true)
        {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);
            if (selected_node == first_node)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        for (auto node : cycle)
            cout << node << " ";
        cout << "\n";
    }
    else
        cout << "NO\n";
}

/*

5 7
1 2 4
1 3 2
2 4 -1
2 5 2
3 2 1
3 4 1
4 5 3

output:
NO 

6 6
1 2 1
2 3 1
3 4 0
4 2 -2
4 5 0
5 6 1

output:
YES
4 2 3 4
*/