#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 3;
const long long INF = 1e18;
vector<pair<int, int>> adj_list[N];
long long d[N];
int parent[N];
int last_update_node;

int n, m;

bool bellman_ford(int src)
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;

    d[src] = 0;
    last_update_node = -1;

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
                    parent[v] = u;
                    if (i == n)
                    {
                        last_update_node = v;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    if (bellman_ford(1))
    {
        cout << "YES\n";

        int selected_node = last_update_node;

        for (int i = 1; i <= n; i++)
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

    return 0;
}

/*

Sample Input 1-

4 5
1 2 2
2 3 2
1 4 1
3 1 -7
3 4 -2

Sample Output 1-

YES
1 2 3 1 

Sample Input 2-

6 11
1 3 18
2 4 -5
3 5 -5
4 1 -5
5 6 -6
6 1 3
1 2 19
2 3 -5
3 4 -5
4 5 -5
5 1 -5

Sample Output 2-

YES
1 2 3 4 5 1 



*/
