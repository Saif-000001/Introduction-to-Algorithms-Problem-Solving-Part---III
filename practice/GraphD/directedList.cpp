#include <bits/stdc++.h>
using namespace std;

int main()
{
    int nodes;
    cin >> nodes;

    vector<pair<int, int>> adjList[nodes];

    int edge;
    cin >> edge;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout<<adjList[i][j].second<<" ";
        }
        cout << "\n";
    }
}

// 5
// 7
// 0 4 20
// 0 1 10
// 1 4 50
// 1 3 40
// 1 2 30
// 2 3 60
// 3 4 70