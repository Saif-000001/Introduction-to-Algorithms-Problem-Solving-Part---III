#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
int visited[N], parent[N], level[N];

void bfs(int src)
{
    queue<int> q;
    visited[src] = 1;
    level[src] = 0;
    // parent[src] = -1;
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        for (auto adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
                parent[adj_node] = head;

                q.push(adj_node);
            }
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
    bfs(src);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " -> " << parent[i] << "\n";
    // }

    if (visited[n] == 0)
    {
        cout << "IMPOSIBLE\n";
        return 0;
    }

    cout << level[n] + 1 << "\n";

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