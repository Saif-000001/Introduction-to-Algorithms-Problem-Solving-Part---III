/*
Input:
4 5
1 3
2 1
2 4
3 2
3 4

Output:
4
2 1 3 2

Time complexity -> O(V+E)
Space complexity -> O(V)

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N];
int n, e;

bool cycle_detected(int node)
{
    visited[node] = 1;
    for (auto adj_node : adj_list[node])
    {
        /*
            - visited[adj_node] == 0 -> unexplored node | aply dfs
            - visited[adj_node] == 1 -> "paused" node | cycle detected
            - visited[adj_node] == 2 -> "done" node | continue

        */
        if (visited[adj_node] == 0)
        {
            bool got_cycle = cycle_detected(adj_node);
            if (got_cycle)
                return true;
        }
        else if (visited[adj_node] == 1)
        {
            return true;
        }
    }
    visited[node] = 2;
    return false;
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bool cycle_exists = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            bool ok = cycle_detected(i);
            if (ok)
            {
                cycle_exists = true;
                break;
            }
        }
    }

    if (cycle_exists)
        cout << "Cycle detected\n";
    else
        cout << "No cycle detected\n";
}
