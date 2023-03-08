// Undirect Graph
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes;
    cin >> nodes;

    int adjMatrix[nodes][nodes] = {};

    int edge;
    cin>>edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
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