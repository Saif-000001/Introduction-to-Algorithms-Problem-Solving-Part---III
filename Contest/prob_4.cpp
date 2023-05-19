#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
const int N = 105;

vector<int> adjacent[N];
int visited[N];
int E = 0;
int L = 0;

int x = 0, y = 0, k = 0;
int step = 0, f = 0;

void get_adjacent_element()
{
    for (int e = 0; e < E; e++)
    {
        int u, v;
        cin >> u >> v;
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
}

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (auto child : adjacent[parent])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = visited[parent] + 1;
                if (child == y)
                {
                    step = visited[child];
                    f = 1;
                    return;
                }
            }
        }
    }
}

void display()
{
    for (int i = 0; i < L; i++)
    {
        cout << i << ":- ";
        for (int k = 0; k < adjacent[i].size(); k++)
            cout << adjacent[i][k] << " ";
        cout << "\n";
    }
}

int main()
{
    Faster;
    cin >> L >> E;
    get_adjacent_element();
    cin >> x >> y >> k;
    bfs(x);
    if (!f)
    {
        cout << "NO\n";
        return 0;
    }
    step--;

    double a = (double)step / (double)2;

    int temp = ceil(a);

    if (temp <= k)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}