// undirect + weighted Graph
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes;
    cin >> nodes;
    int adjMatrix[nodes][nodes] = {};

    int edge;
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
}