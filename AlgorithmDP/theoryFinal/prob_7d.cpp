#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, ax, ay, bx, by, cx, cy;
bool visited[N][N];
bool attacked(int x, int y)
{
    return x == ax || y == ay || x - y == ax - ay || x + y == ax + ay;
}
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool dfs(int x, int y)
{
    visited[x][y] = true;
    if (x == cx && y == cy)
        return true;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n)
            continue;
        if (attacked(nx, ny) || visited[nx][ny])
            continue;
        if (dfs(nx, ny))
            return true;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    if (dfs(bx, by))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
