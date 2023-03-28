#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int adj_matrix[N][N];
int visited[N], level[N], parent[N];
int n, e;

void bfs(int src)
{
    queue<int> q;
    visited[src] = 1;
    level[src] = 0;
    parent[src] = -1;
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << head << " ";

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0 && adj_matrix[head][i] == 1)
            {
                visited[i] = 1;
                level[i] = level[head] + 1;
                parent[i] = head;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }

    int src = 1;
    cout << "BFS : ";
    bfs(src);
    cout << "\n";

    cout << "Level : ";
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
    cout << "path : ";
    for (auto node : path)
    {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}

/*
5 5
1 2
1 3
1 4
2 3
5 4

*/