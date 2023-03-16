#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int visited[N] = {};
int adj_matrix[N][N];
int nodes;

void DFS(int node)
{
    cout << node << " ";
    visited[node] = 1;
    for (int i = 0; i < nodes; i++)
    {
        if (visited[i] == 0 && adj_matrix[node][i] == 1)
            DFS(i);
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
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    cout << "Adjecency Matrix : \n";
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "DFS adjecency matrix : \n";
    DFS(0);
    cout << "\n";

    for(int i = 0; i<nodes; i++){
        cout<<i <<"-> "<<visited[i]<<"\n";
    }
    return 0;
}