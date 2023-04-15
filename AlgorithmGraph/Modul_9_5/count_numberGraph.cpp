#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
vector<int> adj_list[N];
int visited[N];
int n, e;

void DFS(int src)
{
    visited[src] = 1;
    for (auto adj_node : adj_list[src])
    {
        if (visited[adj_node] == 0)
        {
            visited[adj_node] = 1;
            DFS(adj_node);
        }
    }
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

    int cnt_room = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            DFS(i);
            cnt_room++;
        }
    }
    cout << "Count number of component : "<< cnt_room << "\n";
}

/*

6 5
1 2
1 3
2 3
4 5
6 6

*/