#include <bits/stdc++.h>
using namespace std;
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

const int N = 20005;

int T, n, visited[N], species[N], vcount, lcount;
vector<int> adj[N];

void dfs(int source)
{
    visited[source] = 1;
    if (species[source] == 1)
        vcount++;
    else if (species[source] == 2)
        lcount++;
    for (auto v : adj[source])
    {
        if (!visited[v])
        {
            species[v] = 3 - species[source];
            dfs(v);
        }
    }
}

int main()
{
    Faster;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        memset(visited, 0, sizeof(visited));
        memset(species, 0, sizeof(species));
        for (int i = 1; i <= 20000; i++)
        {
            if (!visited[i] && !adj[i].empty())
            {
                vcount = lcount = 0;
                species[i] = 1;
                dfs(i);
                ans += max(vcount, lcount);
            }
        }
        cout << "Case " << t << ": " << ans << "\n";

        for (int i = 1; i <= N; i++)
            adj[i].clear();
    }

    return 0;
}
