// adjecient Matrix
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int maze[N][N];

vector<int> adj_list[N];
int visited[N] = {};
int nodes, edges;

void bfs(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << head << " ";
        // for (int i = 0; i < nodes; i++)
        // {
        //     if (visited[i] == 0 && maze[head][i] == 1)
        //     {
        //         visited[i] = 1;
        //         q.push(i);
        //     }
        // }

        for (auto adj_node : adj_list[head])
        {
            if (visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;

    // for (int i = 0; i < edges; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     maze[u][v] = 1;
    //     maze[v][u] = 1;
    // }

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    // for (int i = 0; i < nodes; i++)
    // {
    //     for (int j = 0; j < edges; j++)
    //     {
    //         cout << maze[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for (auto child : adj_list[i])
        {
            cout << child << " ";
        }
        cout << "\n";
    }

    bfs(3);
    cout << "\n";
    return 0;
}