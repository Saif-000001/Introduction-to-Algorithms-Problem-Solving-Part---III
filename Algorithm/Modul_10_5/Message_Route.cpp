#include <bits/stdc++.h>
using namespace std;

const int N = 100005;;
vector<int> adj_list[N];
bool visited[N];
int level[N], present[N];

void bfs(int src, int dist)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head])
        {
            if (!visited[adj_node])
            {
                visited[adj_node] = true;
                level[adj_node] = level[head] + 1;
                present[adj_node] = head;
                cout<<present[adj_node]<<" ";
                q.push(adj_node);
            }
        }
    }

    if (!visited[dist])
    {
        cout << "IMPOSIBLE\n";
        return;
    }
    cout << level[dist] + 1 << "\n";
    int k = level[dist];

    for(int i = 0; i<=k; i++){
        cout<<present[i]<<" ";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    bfs(1, n);
    
}

/*
input:
5 5
1 2
1 3
1 4
2 3
5 4
*/