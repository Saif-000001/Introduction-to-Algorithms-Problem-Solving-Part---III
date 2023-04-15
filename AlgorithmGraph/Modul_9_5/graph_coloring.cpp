#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int> adj_list[N];
int visited[N];
int color[N];
int n, e;

bool DFS(int nodes)
{
    visited[nodes] = 1;

    for (auto adj_node : adj_list[nodes])
    {
        if (visited[adj_node] == 0)
        {
            if (color[nodes] == 1)
                color[adj_node] = 2;
            else
                color[adj_node] = 1;
            bool bicolor = DFS(adj_node);

            if (!bicolor)
                return false;
        }
        else
        {
            if (color[nodes] == color[adj_node])
                return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool bicolorable = true;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            color[i] = 1;
            bool ok = DFS(i);
            if (!ok)
            {
                bicolorable = false;
                break;
            }
        }
    }

    if (!bicolorable)
        cout << "IMPOSIBLE \n";
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << color[i] << "\t";
        }
        cout << "\n";
    }
    return 0;
}