#include <bits/stdc++.h>
using namespace std;


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

const int N = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int>> adj_list[N];
int d[N], visited[N];
int nodes, edges;

/*
    w
u------> v
 ------> x
    a

u -> (v,w) (x,a)

*/

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
    {
        d[i] = INF;
    }
    d[src] = 0;

    for (int i = 0; i < nodes; i++)
    {
        int selected_node = -1;
        for (int j = 1; j <= nodes; j++)
        {
            if (visited[j] == 1)
                continue;
            // selected node = 2
            // j = 4
            // d[2] > d[4] -> selected node = j

            if (selected_node == -1 || d[selected_node] > d[j])
            {
                selected_node = j;
            }
        }
        visited[selected_node] = 1;

        for (auto adj_enty : adj_list[selected_node])
        {
            int adj_node = adj_enty.first;
            int edge_cst = adj_enty.second;

            if (d[selected_node] + edge_cst < d[adj_node])
            {
                d[adj_node] = d[selected_node] + edge_cst;
            }
        }
    }
}

int main()
{
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    int src = 2;
    dijkstra(src);

    for (int i = 1; i <= nodes; i++)
        cout << "Node: " << i << " distant: " << d[i] << "\n";

    cout << "\n";

    return 0;
}


/*

8 12
2 1 3
2 3 18
1 3 22
1 6 3
1 8 3
1 4 1
4 8 10
4 7 4
4 3 2
3 7 1
7 6 2
6 8 2


*/