/*
Assumption : Acyclic Graph
Input:
5 3
1 2
3 1
4 5

Output:
3 4 1 5 2

Time complexity -> O(E+V)
Space complexity -> O(V)

*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> adj_list[N];
int visited[N];
stack<int> node_stack;
int n, e;

void dfs(int node)
{
    visited[node] = 1;
    for (auto adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
            dfs(adj_node);
    }
    node_stack.push(node);
}

int main()
{
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    while (!node_stack.empty())
    {
        cout << node_stack.top() << " ";
        node_stack.pop();
    }
    cout << "\n";
}
