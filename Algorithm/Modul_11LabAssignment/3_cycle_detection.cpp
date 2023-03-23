#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
bool visited[N];

bool cycle_detection(int node)
{
    visited[node] = true;
    for (auto adj_node : adj_list[node])
    {
        if (visited[adj_node]==false)
        {
            bool cycle = cycle_detection(adj_node);
            if (cycle)
                return true;
        }
        else if (visited[adj_node] == true)
            return true;
    }
    visited[node] = 2;
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    bool checkCycle = false;

    for (int i = 0; i < n; i++)
    {
        if (visited[i]==false)
        {
            bool ok = cycle_detection(i);
            if (ok)
            {
                checkCycle = true;
                break;
            }
        }
    }

    if (checkCycle)
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}

/*
5 5
0 1
1 2
2 3
3 4
4 1
output : YES

5 4
0 1
1 2
2 3
3 4
output : NO
*/