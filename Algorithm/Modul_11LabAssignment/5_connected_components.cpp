#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N];

void dfs(int node)
{
    visited[node] = 1;
    for (auto adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
            dfs(adj_node);
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

    int cnt_num = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
            cnt_num++;
        }
    }
    cout << cnt_num << "\n";
}

/*
5 4
0 1
1 2
2 0
2 3
*/