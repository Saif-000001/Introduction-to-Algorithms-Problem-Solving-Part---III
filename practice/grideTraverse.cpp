#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
int maze[N][N];
int visited[N][N];
int r, c;
int level[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool is_inside(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if (x >= 0 && x < r && y >= 0 && y < c)
        return true;
    return false;
}

bool is_safe(pair<int, int> coord)
{
    int x = coord.first;
    int y = coord.second;

    if (maze[x][y] == -1)
        return false;
    return true;
}

void BFS(pair<int, int> src)
{
    queue<pair<int, int>> q;
    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;
    q.push(src);

    while (!q.empty())
    {
        pair<int, int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int> adj_node = {new_x, new_y};

            if (is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;
                level[new_x][new_y] = level[x][y] + 1;
                q.push(adj_node);
            }
        }
    }
}

int main()
{
    cin >> r >> c;

    pair<int, int> src, dist;
    for (int i = 0; i < r; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < c; j++)
        {
            if (input[j] == '#')
                maze[i][j] = -1;
            else if (input[j] == 'A')
                src = {i, j};
            else if (input[j] == 'B')
                dist = {i, j};
        }
    }

    BFS(src);

    if (level[dist.first][dist.second] == -1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << level[dist.first][dist.second] << "\n";
    }
}