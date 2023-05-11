#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);


int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

vector<int> adj[1111];
bool visited[1111][1111];

bool isValid(int x, int y, int n, int m)
{
    return (x > -1 && x < n && y > -1 && y < m && !visited[x][y] && adj[x][y] != 0);
}

ll DFS(int x, int y, int n, int m)
{
    ll count = adj[x][y];
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (isValid(tx, ty, n, m))
        {
            count += DFS(tx, ty, n, m);
        }
    }
    return count;
}

int main()
{
    Faster;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            adj[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> adj[i][j];
                visited[i][j] = false;
            }
        }

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] or adj[i][j] == 0)
                    continue;
                ans = max(ans, DFS(i, j, n, m));
            }
        }

        cout << ans << endl;
    }

    return 0;
}
