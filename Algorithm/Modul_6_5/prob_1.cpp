/*
    Time Complexity -> O(E+V)
    Space Complexity ->  O(V^2)
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int visited[N] = {};
int adj_Matrix[N][N];
int nodes;

void BFS(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout << head << " ";
        for (int i = 0; i < nodes; i++)
        {
            if (visited[i] != 1 && adj_Matrix[head][i] == 1)
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int edge;
    cin >> nodes >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_Matrix[u][v] = 1;
        adj_Matrix[v][u] = 1;
    }
    cout << "Adjecence Matrix : \n";
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << adj_Matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << "BFS Adjecency Matrix : \n";
    BFS(0);
    cout << "\n";
    return 0;
}