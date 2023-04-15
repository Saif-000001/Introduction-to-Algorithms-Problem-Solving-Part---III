#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
int visited[N], parent[N];

void dfs(int src)
{
    visited[src] = 1;
    for (auto adj_node : adj_list[src])
    {
        if (visited[adj_node] == 0)
        {
            parent[adj_node] = src;
            dfs(adj_node);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 1;
    dfs(src);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " -> " << parent[i] << "\n";
    // }

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
    {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}

/*

5 5
1 2
1 3
1 4
2 3
5 4

*/