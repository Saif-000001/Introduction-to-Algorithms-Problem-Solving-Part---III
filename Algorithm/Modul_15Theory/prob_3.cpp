#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
vector<bool> visited(N);
vector<int> parent(N);

bool is_cylce(int node)
{
    queue<int> q;
    visited[node] = true;
    parent[node] = -1;
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
                parent[adj_node] = head;
                q.push(adj_node);
            }
            else if (adj_node != parent[head])
                return true;
        }
    }
    return false;
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

    bool cycle_exist = false;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (is_cylce(i))
            {
                cycle_exist = true;
                break;
            }
        }
    }

    if (cycle_exist)
        cout << "Cycle Exist\n";
    else
        cout << "No Cycle\n";
}
