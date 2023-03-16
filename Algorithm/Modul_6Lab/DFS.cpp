#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;

int visited[N];

vector<int> adj_list[N];

void DFS(int node)
{
    cout << node << " ";

    visited[node] = 1;

    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
            DFS(adj_node);
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    cout << "Adjecency List : \n";
    for (int i = 0; i < node; i++)
    {
        cout << i << "-> ";
        for (auto list : adj_list[i])
        {
            cout << list << " ";
        }
        cout << "\n";
    }

    cout << "DFS Adjecency List : \n";
    int src = 0;
    DFS(src);
    cout << "\n";


    return 0;
}

/*
6 6

0 1
1 2
1 5
2 3
2 4
3 5
*/