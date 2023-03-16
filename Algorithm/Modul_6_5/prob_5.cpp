#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
vector<int> adj_list[N];

void BFS(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (auto child : adj_list[head])
        {
            if (visited[child] == 0)
            {
                visited[child] = 1;
                q.push(child);
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

    cout << "Adjecency List : \n";
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto child : adj_list[i])
            cout << child << " ";
        cout << "\n";
    }

    BFS(2);

    if (visited[6])
        cout << "Nodes 2 and 6 are connected\n";
    else
        cout << "Nodes 2 and 6 are not connected\n";
}