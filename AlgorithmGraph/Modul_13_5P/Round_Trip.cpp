/*

5 6
1 3
1 2
5 3
1 5
2 4
4 5
Output:
4
3 5 1 3

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj_list[N];
int visited[N], level[N], parent[N];

// void bfs(int src)
// {
//     queue<int> q;
//     visited[src] = 1;
//     level[src] = 0;
//     // parent[src] = -1;
//     q.push(src);

//     while (!q.empty())
//     {
//         int head = q.front();
//         q.pop();

//         for (auto node : adj_list[head])
//         {
//             if (visited[node] == 0)
//             {
//                 visited[node] = 1;
//                 level[node] = level[head] + 1;
//                 parent[node] = head;
//                 q.push(node);
//             }
//             else
//             {
//                 level[node] = level[head] + 1;
//                 parent[node] = head;
//             }
//         }
//     }
//     visited[src] = 2;
// }

void dfs(int src)
{
    visited[src] = 1;
    for (auto adj_node : adj_list[src])
    {
        if (visited[adj_node] == 0)
        {
            parent[adj_node] = src;
            dfs(adj_node);
        }
        else
        {
            parent[adj_node] = src;
        }
    }
    visited[src] = 2;
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
    }

    int src = 1;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            dfs(1);
    }

    cout << level[n] << "\n";

    if (visited[n] == 0)
    {
        cout << "IMPOSIBLE\n";
        return 0;
    }

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