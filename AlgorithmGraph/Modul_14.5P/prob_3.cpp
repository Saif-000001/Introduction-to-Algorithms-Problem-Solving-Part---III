/*


8 14
4 3 9
4 5 10
3 5 14
3 2 7
5 2 4
5 6 2
2 1 8
2 8 2
6 8 6
6 7 1
7 8 7
7 0 8
7 1 11
1 0 4


*/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const long long INF = 1e18;
vector<pair<int, int>> adj_list[N];
vector<int> visited(N);
vector<long long> dist(N, INF);

void Dijkstra(int src)
{
    dist[src] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<long long, int> head = pq.top();
        pq.pop();
        int selected_node = head.second;
        if (visited[selected_node] == 1)
            continue;

        visited[selected_node] = 1;

        for (auto adj_enty : adj_list[selected_node])
        {
            int adj_node = adj_enty.first;
            int edge_cst = adj_enty.second;

            if (dist[selected_node] + edge_cst < dist[adj_node])
            {
                dist[adj_node] = dist[selected_node] + edge_cst;
                pq.push({-dist[adj_node], adj_node});
            }
        }
    }
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    int src = 4;
    Dijkstra(src);

    for (int i = 0; i <= nodes; i++)
        cout << "Node " << i << " distance : " << dist[i] << "\n";
}