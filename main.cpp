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

const int N = 1e5;
const int infinity = 1e9;
vector<pair<int, int>> adjacent[N];
vector<int> visited(N);
vector<int> distant(N, infinity);
int n, m;

void dijkstra_algorithm(int source)
{
    distant[source] = 0;
    queue<int> q;
    q.push(source);
    visited[source] = 1;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (auto child : adjacent[parent])
        {
            if (!visited[child.first])
            {
                visited[child.first] = 1;
                q.push(child.first);
                distant[child.first] = distant[parent] + child.second;
            }
            else
            {
                int temp = distant[parent] + child.second;
                if (distant[child.first] > temp)
                    distant[child.first] = temp;
            }
        }
    }
}

void get_adjacency_list()
{
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjacent[u].push_back({v, w});
        adjacent[v].push_back({u, w});
    }
}
int main()
{
    cin >> n >> m;
    get_adjacency_list();
    int src = 1;
    dijkstra_algorithm(src);

    for (int i = 1; i <= n; i++)
        cout << "Node: " << i << " distant: " << distant[i] << "\n";
    return 0;
}