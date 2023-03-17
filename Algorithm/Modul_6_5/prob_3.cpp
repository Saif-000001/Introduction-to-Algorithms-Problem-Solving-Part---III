#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N];
vector<int> adj_list[N];
int checked[N];

void BFS(int src)
{
    queue<int> q;
    visited[src] = 1;
    q.push(src);

    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        cout<<head<<" ";

        for (auto child : adj_list[head])
        {
            if (visited[child] == 0)
            {
                visited[child] = 1;
                q.push(child);
            }
            checked[child]++;
        }
    }
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
        adj_list[v].push_back(u);
    }
    cout<<"Adjecency List : \n";
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (auto list : adj_list[i])
            cout << list << " ";
        cout << "\n";
    }

    cout<<"Cheaked List : \n";
    BFS(2);
    cout<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << checked[i] << "\n";
    }
}