#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
vector<int> adj_list[N];
int checked[N];

void DFS(int node)
{
    cout << node << " ";
    visited[node] = 1;
    for (auto child : adj_list[node])
    {
        checked[node]++;
        if (visited[child] == 0)
            DFS(child);
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

    DFS(2);
    cout << "\n";
    cout << "DFS adjecency list : \n";
    for (int i = 0; i < n; i++)
        cout << i << " ->" << checked[i] << "\n";

    return 0;
}