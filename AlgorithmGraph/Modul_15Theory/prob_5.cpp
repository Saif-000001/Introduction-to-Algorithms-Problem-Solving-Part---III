#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
vector<bool> visited(N);

void BFS(int node)
{
    queue<int> q;
    visited[node] = true;

    q.push(node);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (auto adj_node : adj_list[head])
        {
            if (!visited[adj_node])
            {
                visited[adj_node] = true;
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

    BFS(1);

    if (visited[n])
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}