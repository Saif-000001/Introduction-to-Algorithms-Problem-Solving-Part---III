#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N], partite[N];

bool isBipartite(int node)
{
    visited[node] = 1;
    for (auto adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            if (partite[node] == 1)
                partite[adj_node] = 2;
            else
                partite[adj_node] = 1;

            bool bipartitable = isBipartite(adj_node);
            if (!bipartitable)
                return false;
        }
        else
        {
            if (partite[node] == partite[adj_node])
                return false;
        }
    }
    return true;
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

    bool Bipartite = true;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            partite[i] = 1;
            bool bipartitable = isBipartite(i);

            if (!bipartitable)
            {
                Bipartite = false;
                break;
            }
        }
    }

    if (Bipartite)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}