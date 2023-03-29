/*

6 8
1 2 10
1 3 15
2 4 12
2 6 15
3 5 10
4 6 1
4 5 2
6 5 5

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
    }

    int src = 1;
    Dijkstra(src);

    for (int i = 1; i <= nodes; i++)
    {
        cout << "Node " << i << " distance : " << dist[i] << "\n";
    }
}