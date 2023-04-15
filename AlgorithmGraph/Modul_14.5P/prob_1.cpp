// Write code to solve Dijkstra’s problem with O(n^2) time complexity

/*

6 8
1 2 4
1 3 4
3 2 2
2 4 3
2 5 1
2 6 6
4 6 2
5 6 3

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9;
vector<pair<int, int>> adj_list[N];
vector<int> visited(N);
vector<int> Dist(N, INF);
int nodes, edge;

void dijkstra(int src)
{
    Dist[src] = 0;
    for (int i = 0; i < nodes; i++)
    {
        int selec_node = -1;
        for (int j = 1; j <= nodes; j++)
        {
            if (visited[j] == 1)
                continue;

            if (selec_node == -1 || Dist[selec_node] > Dist[j])
                selec_node = j;
        }
        visited[selec_node] = 1;
        for (auto adj_enty : adj_list[selec_node])
        {
            int adj_node = adj_enty.first;
            int edge_cst = adj_enty.second;

            if (Dist[selec_node] + edge_cst < Dist[adj_node])
                Dist[adj_node] = Dist[selec_node] + edge_cst;
        }
    }
}

int main()
{
    cin >> nodes >> edge;
    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    int src = 1;
    dijkstra(src);

    for (int i = 1; i <= nodes; i++)
        cout << "Node " << i << " distance : " << Dist[i] << "\n";
}
