#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
const long long INF = 1e18;

vector<pair<int, int>> adj_list[N];
vector<int> visited(N);
// vector<long long> Distance(N, INF);
long long Distance[N];
int parent[N];
int n, e;

void dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
    {
        Distance[i] = INF;
    }
    Distance[src] = 0;
    priority_queue<pair<long long, int>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<long long, int> head = pq.top();
        int selected_node = head.second;
        pq.pop();
        if (visited[selected_node] == 1)
            continue;

        visited[selected_node] = 1;

        for (auto adj_enty : adj_list[head.second])
        {
            int adj_node = adj_enty.first;
            int adj_edge = adj_enty.second;

            if (Distance[selected_node] + adj_edge < Distance[adj_node])
            {
                Distance[adj_node] = Distance[selected_node] + adj_edge;
                parent[adj_node] = selected_node;
                pq.push({-Distance[adj_node], adj_node});
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }
    int src = 1;

    dijkstra(src);

    // cout << Distance[n] << "\n";

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Node " << i << " Distance : " << Distance[i] << "\n";
    // }

    if (visited[n] == 0)
    {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> path;
    while (true)
    {
        path.push_back(n);
        if (src == n)
            break;
        n = parent[n];
    }

    reverse(path.begin(), path.end());

    for (auto node : path)
    {
        cout << node << " ";
    }
    cout << "\n";
    return 0;
}

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


9 15
1 2 5
1 6 20
1 3 9
2 4 1
3 5 1
3 6 7
4 6 13
4 8 21
5 6 2
5 9 5
5 7 18
6 9 6
6 8 15
7 8 7
7 9 6


*/